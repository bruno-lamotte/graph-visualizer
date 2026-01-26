#!/usr/bin/env python3
import random
import sys

def generer_map(largeur, hauteur, densite):
    # Sécurité : taille minimum
    if largeur < 3 or hauteur < 3:
        return "Erreur : La carte doit faire au moins 3x3."

    # 1. Calcul de la zone intérieure
    inner_width = largeur - 2
    inner_height = hauteur - 2
    total_inner_cells = inner_width * inner_height
    
    # 2. Préparation du contenu intérieur
    nb_murs = int(total_inner_cells * densite)
    nb_vides = total_inner_cells - nb_murs
    
    # Création de la liste exacte
    interieur = ['1'] * nb_murs + ['0'] * nb_vides
    random.shuffle(interieur)
    
    # 3. Construction de la grille
    grid = []
    for y in range(hauteur):
        row = []
        for x in range(largeur):
            # Bords
            if x == 0 or x == largeur - 1 or y == 0 or y == hauteur - 1:
                row.append('1')
            else:
                row.append(interieur.pop())
        grid.append(row)

    # 4. Placement GARANTI de P et E
    coords_interieures = []
    for y in range(1, hauteur - 1):
        for x in range(1, largeur - 1):
            coords_interieures.append((y, x))
            
    pos_p, pos_e = random.sample(coords_interieures, 2)
    
    grid[pos_p[0]][pos_p[1]] = 'P'
    grid[pos_e[0]][pos_e[1]] = 'E'

    return "\n".join("".join(row) for row in grid)

if __name__ == "__main__":
    # On accepte 2 ou 3 arguments
    if len(sys.argv) < 3:
        print("Usage: ./generateur.py <largeur> <hauteur> [densité_%]")
        print("Exemple (densité par défaut ~14%): ./generateur.py 20 10")
        print("Exemple (densité 30%):             ./generateur.py 20 10 30")
        sys.exit(1)

    try:
        l = int(sys.argv[1])
        h = int(sys.argv[2])
        
        # Gestion de la densité
        if len(sys.argv) >= 4:
            # L'utilisateur a donné un pourcentage (ex: 30 pour 30%)
            pourcentage = int(sys.argv[3])
            if not (0 <= pourcentage <= 100):
                print("Erreur : Le pourcentage doit être entre 0 et 100.")
                sys.exit(1)
            densite_finale = pourcentage / 100.0
        else:
            # Valeur par défaut (1/7 soit environ 14.28%)
            densite_finale = 1/7

        print(generer_map(l, h, densite_finale))
        
    except ValueError:
        print("Erreur: Les arguments doivent être des nombres entiers.")
