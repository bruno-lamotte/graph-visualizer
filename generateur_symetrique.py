import random

def generate_symmetric_map(width, height, wall_density=0.2):
    # 1. Remplir de vide ('0')
    grid = [['0' for _ in range(width)] for _ in range(height)]
    
    # 2. Générer la moitié gauche + milieu
    mid_x = (width + 1) // 2
    
    for y in range(1, height - 1):
        for x in range(1, mid_x):
            # Décision aléatoire : mur ou vide
            if random.random() < wall_density:
                grid[y][x] = '1'
                # Miroir horizontal
                grid[y][width - 1 - x] = '1'

    # 3. Forcer les murs extérieurs (Indispensable pour ton get_xy en C)
    for y in range(height):
        grid[y][0] = '1'
        grid[y][width - 1] = '1'
    for x in range(width):
        grid[0][x] = '1'
        grid[height - 1][x] = '1'

    return grid

def save_map(grid, filename="map_sym.ber"):
    with open(filename, 'w') as f:
        for row in grid:
            f.write("".join(row) + "\n")

# --- Paramètres ---
W, H = 20, 10
map_data = generate_symmetric_map(W, H, wall_density=0.15)

# Placement basique P et E pour l'exemple
# (Dans ton projet C, tu feras ça intelligemment via BFS)
map_data[1][1] = 'P' 
map_data[H-2][W-2] = 'E'

# Affichage console
for row in map_data:
    print("".join(row))

save_map(map_data)
