
from queue import Queue
import igraph as ig
from typing import Any
from PIL import Image, ImageDraw

GRID_SIZE = 21
DRAW_COLOR = (34, 34, 34, 255)
BG_COLOR = (255, 255, 255, 255)
CELL_SIZE = 40
LINE_COLOR = (255, 0, 0, 255)
LINE_WIDTH = 5

# 0 = empty, 1 = wall, 2 = water, 3 = fire

with open("out/maze.txt") as f:
    grid = [[" XWF".index(cell) for cell in row] for row in
    f.read().strip().split("\n")]

water: list[tuple[int, int]] = []
fire: list[tuple[int, int]] = []

for i in range(GRID_SIZE):
    for j in range(GRID_SIZE):
        if grid[i][j] == 2:
            water.append((i, j))
        if grid[i][j] == 3:
            fire.append((i, j))

dist: list[list[int]] = [[-1] * len(fire) for _ in water]
for i, (x, y) in enumerate(water):
    q: Queue[tuple[int, int]] = Queue()
    cur_dist = [[-1] * GRID_SIZE for _ in range(GRID_SIZE)]
    cur_dist[x][y] = 0
    q.put((x, y))
    while not q.empty():
        cx, cy = q.get()
        for dx, dy in (0, 1), (0, -1), (1, 0), (-1, 0):
            tx, ty = cx + dx, cy + dy
            if tx < 0 or tx >= GRID_SIZE or ty < 0 or ty >= GRID_SIZE:
                continue
            if cur_dist[tx][ty] != -1 or grid[tx][ty] == 1:
                continue
            cur_dist[tx][ty] = cur_dist[cx][cy] + 1
            q.put((tx, ty))
            if grid[tx][ty] == 3:
                dist[i][fire.index((tx, ty))] = cur_dist[tx][ty]

def get_full_matching(max_dist: int) -> Any | None:
    edges: list[tuple[int, int]] = []
    for i, dist_row in enumerate(dist):
        for j, d in enumerate(dist_row):
            if d <= max_dist:
                edges.append((i, len(water) + j))
    g = ig.Graph.Bipartite([0] * len(water) + [1] * len(fire), edges)
    matching = g.maximum_bipartite_matching()
    if all([matching.match_of(i) is not None for i, _ in enumerate(water)]):
        return matching
    return None

def maze_to_image(maze: list[list[int]], edges: list[tuple[tuple[int, int],
tuple[int, int]]], output_file: str) -> None:
    """ Convert the given maze to an image and save it at the given output
        location """
    size = len(maze)
    img = Image.new("RGBA", (size * CELL_SIZE, size * CELL_SIZE), BG_COLOR)
    draw = ImageDraw.Draw(img)
    water = Image.open("./putting-out-the-fire/water.png")
    water = water.resize((CELL_SIZE - 1, CELL_SIZE - 1))
    fire = Image.open("./putting-out-the-fire/fire.png")
    fire = fire.resize((CELL_SIZE - 1, CELL_SIZE - 1))
    for i, row in enumerate(maze):
        for j, cell in enumerate(row):
            if cell == 1:
                draw.rectangle((i * CELL_SIZE, j * CELL_SIZE,
                (i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE), DRAW_COLOR)
            if cell == 2:
                img.paste(water, (i * CELL_SIZE + 1, j * CELL_SIZE + 1))
            if cell == 3:
                img.paste(fire, (i * CELL_SIZE + 1, j * CELL_SIZE + 1))
    for (ix, iy), (jx, jy) in edges:
        draw.line((
            ix * CELL_SIZE + CELL_SIZE // 2,
            iy * CELL_SIZE + CELL_SIZE // 2,
            jx * CELL_SIZE + CELL_SIZE // 2,
            jy * CELL_SIZE + CELL_SIZE // 2,
        ), fill=LINE_COLOR, width=LINE_WIDTH)
    img.save(output_file)

lo, hi = 0, 2 * GRID_SIZE
while lo < hi:
    m = (lo + hi) // 2
    matching = get_full_matching(m)
    if matching is not None:
        hi = m
    else:
        lo = m + 1

print("Matching:")
matching = get_full_matching(lo)
edges: list[tuple[tuple[int, int], tuple[int, int]]] = []
for i, w in enumerate(water):
    edge = w, fire[matching.match_of(i) - len(water)]
    print(f"    {edge[0]} -- {edge[1]}")
    edges.append(edge)
print("Minimum time:", lo, "minutes")
maze_to_image(grid, edges, "out/maze_solution.png")