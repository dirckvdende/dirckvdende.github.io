
from typing import Iterable, Iterator
from PIL import Image, ImageDraw
import os
import random

DRAW_COLOR = (34, 34, 34, 255)
BG_COLOR = (255, 255, 255, 255)
CELL_SIZE = 40
EXTRA_EDGE_CHANCE = 0.5
MAZE_SIZE = 21
WATER_FIRE_COUNT = 60

random.seed(42)

class DisjointUnion:
    """ Disjoint union data structure """

    def __init__(self, n: int):
        """ Constructor, given the size of the disjoint union """
        self._sizes = [1] * n
        self._parent = [-1] * n

    def find(self, x: int) -> int:
        """ Find the representative of an element x from the interval [0, n) """
        if self._parent[x] < 0:
            return x
        self._parent[x] = self.find(self._parent[x])
        return self._parent[x]

    def combine(self, x: int, y: int) -> None:
        """ Combine the two partitions that x and y are contained in, x and y
            given in the interval [0, n) """
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self._sizes[x] < self._sizes[y]:
            x, y = y, x
        self._parent[y] = x
        self._sizes[x] += self._sizes[y]

def generate_maze(size: int) -> list[list[bool]]:
    """ Generate a maze of the given size (should be an odd number > 2). Returns
        a 2D list of zeros and ones, where ones are walls. Maze is generated
        using randomized Kruskal """
    assert size % 2 == 1
    grid_size = size // 2
    edges: list[tuple[int, int]] = []
    for i in range(grid_size):
        for j in range(grid_size):
            if i + 1 < grid_size:
                edges.append((grid_size * i + j, grid_size * (i + 1) + j))
            if j + 1 < grid_size:
                edges.append((grid_size * i + j, grid_size * i + j + 1))
    grid = [[i % 2 != 1 or j % 2 != 1 for j in range(size)] for i in
    range(size)]
    for x, y in random_kruskal(grid_size ** 2, edges, EXTRA_EDGE_CHANCE):
        ix, jx = x // grid_size, x % grid_size
        iy, jy = y // grid_size, y % grid_size
        for i in range(min(ix, iy) * 2 + 1, max(ix, iy) * 2 + 2):
            for j in range(min(jx, jy) * 2 + 1, max(jx, jy) * 2 + 2):
                grid[i][j] = False
    return grid

def random_kruskal(size: int, edges: Iterable[tuple[int, int]],
extra_chance: float = 0.0) -> Iterator[tuple[int, int]]:
    """ Perform randomized kruskal on a graph of the given size with a list of
        edges. Returns a list of edges to include in the spanning tree. If
        extra_chance is given, extra edges can be added, even if two nodes are
        already in the same connected component """
    edges = list(edges)
    random.shuffle(edges)
    dsu = DisjointUnion(size)
    for x, y in edges:
        if dsu.find(x) != dsu.find(y) or random.random() < extra_chance:
            dsu.combine(x, y)
            yield x, y

def maze_to_image(maze: list[list[int]], output_file: str) -> None:
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
    img.save(output_file)

def maze_to_file(maze: list[list[int]], output_file: str) -> None:
    """ Store the maze in a file with . and X indicating empty cells and
        walls """
    with open(output_file, "w") as f:
        for row in maze:
            f.write("".join(" XWF"[cell] for cell in row) + "\n")

def remove_single_dots(maze: list[list[bool]]) -> None:
    for i in range(1, len(maze) - 1):
        for j in range(1, len(maze) - 1):
            if (not maze[i - 1][j] and not maze[i + 1][j] and not maze[i][j - 1]
            and not maze[i][j + 1]):
                maze[i][j] = False

def random_empty_location(maze: list[list[int]]) -> tuple[int, int]:
    i, j = 0, 0
    while maze[i][j] != 0:
        i, j = random.randrange(len(maze)), random.randrange(len(maze))
    return i, j

def add_random_water_fire(maze: list[list[int]], count: int) -> None:
    for _ in range(count):
        wi, wj = random_empty_location(maze)
        maze[wi][wj] = 2
        fi, fj = random_empty_location(maze)
        maze[fi][fj] = 3

maze = generate_maze(MAZE_SIZE)
remove_single_dots(maze)
if not os.path.exists("out"):
    os.mkdir("out")
maze = [[1 if cell else 0 for cell in row] for row in maze]
add_random_water_fire(maze, WATER_FIRE_COUNT)
maze_to_image(maze, "out/maze.png")
maze_to_file(maze, "out/maze.txt")
