
from queue import PriorityQueue
from itertools import product
from PIL import Image, ImageDraw
import os

CELL_SIZE = 20
MAZE_SIZE = 41
DRAW_COLOR = (34, 34, 34, 255)
BG_COLOR = (255, 255, 255, 255)
PATH_COLOR = (245, 188, 66, 255)

# directions: 0 = up, 1 = right, 2 = down, 3 = left

with open("out/maze.txt") as f:
    grid = [[cell == "X" for cell in row] for row in
    f.read().strip().split("\n")]

def to_graph_index(i: int, j: int, direction: int) -> int:
    return i * MAZE_SIZE * 4 + j * 4 + direction

def from_graph_index(index: int) -> tuple[int, int, int]:
    return (
        index // 4 // MAZE_SIZE,
        index // 4 % MAZE_SIZE,
        index % 4,
    )

def dijkstra(graph: list[list[tuple[int, int]]], s: int) -> tuple[list[int],
list[int]]:
    dist = [10 ** 10] * len(graph)
    prev = [-1] * len(graph)
    # (dist, node)
    q: PriorityQueue[tuple[int, int]] = PriorityQueue()
    removed: set[tuple[int, int]] = set()
    q.put((0, s))
    dist[s] = 0
    while not q.empty():
        d, v = q.get()
        if (d, v) in removed:
            continue
        for e, d in graph[v]:
            if dist[v] + d < dist[e]:
                removed.add((dist[e], e))
                dist[e] = dist[v] + d
                q.put((dist[e], e))
                prev[e] = v
    return dist, prev

def get_direction(i: int, j: int, direction: int) -> tuple[int, int]:
    match direction:
        case 0: return i - 1, j
        case 1: return i, j + 1
        case 2: return i + 1, j
        case 3: return i, j - 1

def maze_to_image(maze: list[list[int]], output_file: str) -> None:
    """ Convert the given maze to an image and save it at the given output
        location """
    size = len(maze)
    img = Image.new("RGBA", (size * CELL_SIZE, size * CELL_SIZE), BG_COLOR)
    draw = ImageDraw.Draw(img)
    for i, row in enumerate(maze):
        for j, cell in enumerate(row):
            if cell > 0:
                draw.rectangle((i * CELL_SIZE, j * CELL_SIZE,
                (i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE), DRAW_COLOR if
                cell == 1 else PATH_COLOR)
    img.save(output_file)

graph = [[] for _ in range(MAZE_SIZE ** 2 * 4)]
for i, j, direction in product(range(MAZE_SIZE), range(MAZE_SIZE), range(4)):
    for diff in (3, 4, 5):
        new_direction = (direction + diff) % 4
        ti, tj = get_direction(i, j, new_direction)
        if ti < 0 or ti >= MAZE_SIZE or tj < 0 or tj >= MAZE_SIZE:
            continue
        wall = grid[ti][tj]
        if wall:
            continue
        graph[to_graph_index(i, j, direction)].append((
            to_graph_index(ti, tj, new_direction),
            1 if diff == 3 else 0,
        ))

start = to_graph_index(39, 1, 1)
end = to_graph_index(1, 39, 0)

dist, prev = dijkstra(graph, start)
print("Minimum left turns:", dist[end])
path: list[tuple[int, int]] = []
path_grid = [[int(cell) for cell in row] for row in grid]
cur = end
while cur >= 0:
    i, j, _ = from_graph_index(cur)
    path_grid[i][j] = 2
    path.append((i, j))
    cur = prev[cur]
print("Path:", *reversed(path))
if not os.path.exists("out"):
    os.mkdir("out")
maze_to_image(path_grid, "out/maze_solution.png")