import csv
import time
import requests
import os
from tqdm import tqdm

INPUT_FILE = "adresses.csv"       # Fichier source avec 1500 adresses
OUTPUT_FILE = "adresses_geo.csv"  # Fichier de sortie
EMAIL = "quent1.perbost@gmail.com"   # Obligatoire pour User-Agent Nominatim
MAX_RETRIES = 3                    # Nombre de tentatives si erreur réseau

def geocode(adresse):
    """Renvoie (lat, lon) ou (None, None) après retries si erreur"""
    url = "https://nominatim.openstreetmap.org/search"
    params = {"q": adresse, "format": "json", "limit": 1, "addressdetails": 0}
    headers = {"User-Agent": f"geocode-script ({EMAIL})"}
    for attempt in range(1, MAX_RETRIES + 1):
        try:
            r = requests.get(url, params=params, headers=headers, timeout=10)
            r.raise_for_status()
            data = r.json()
            if data:
                return data[0]["lat"], data[0]["lon"]
            return None, None
        except Exception as e:
            print(f"\n⚠️ Erreur {attempt}/{MAX_RETRIES} pour '{adresse}': {e}")
            time.sleep(2)  # Pause avant retry
    return None, None

# Charger adresses déjà traitées
done = {}
if os.path.exists(OUTPUT_FILE):
    with open(OUTPUT_FILE, newline="", encoding="utf-8") as f:
        reader = csv.DictReader(f)
        for row in reader:
            if row["Adresse"] and row.get("lat"):
                done[row["Adresse"]] = (row["lat"], row["lon"])

# Lire toutes les lignes d'entrée
with open(INPUT_FILE, newline="", encoding="utf-8") as fin:
    reader = list(csv.DictReader(fin))
    total = len(reader)

# Ouvrir sortie
with open(OUTPUT_FILE, "a", newline="", encoding="utf-8") as fout:
    fieldnames = reader[0].keys() | {"lat", "lon"}
    writer = csv.DictWriter(fout, fieldnames=fieldnames)
    if os.path.getsize(OUTPUT_FILE) == 0:
        writer.writeheader()  # écrire l'en-tête si fichier vide

    for row in tqdm(reader, desc="Géocodage", unit="adresse"):
        adresse = row["Adresse"].strip('"')
        if adresse in done:
            row["lat"], row["lon"] = done[adresse]
        else:
            lat, lon = geocode(adresse)
            row["lat"], row["lon"] = lat, lon
            time.sleep(1)  # Respect limite 1 req/s
        writer.writerow(row)
        fout.flush()  # Sauvegarde immédiate pour reprise

print(f"\n✅ Terminé. Résultat dans {OUTPUT_FILE}")
