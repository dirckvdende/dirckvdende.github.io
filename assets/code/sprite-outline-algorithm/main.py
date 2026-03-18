
from PIL import Image
from typing import Callable
from itertools import product
import math

# Width to give the outlines of the output images
OUTLINE_WIDTH = 10

def get_adjacent(
    image: Image.Image,
    neighbours: Callable[[int, int], tuple[int, int]]
) -> list[tuple[int, int]]:
    """ Get all empty pixels in an image that are next to a non-empty pixel,
        given some function that yields a pixel's neighbours """
    cells: list[tuple[int, int]] = []
    for x, y in product(range(image.width), range(image.height)):
        if image.getpixel((x, y))[3] != 0:
            continue
        found_different = False
        for nx, ny in neighbours(x, y):
            if nx < 0 or nx >= image.width or ny < 0 or ny >= image.height:
                continue
            if image.getpixel((nx, ny))[3] != 0:
                found_different = True
                break
        if found_different:
            cells.append((x, y))
    return cells

def flood_fill(
    image: Image.Image,
    neighbours: Callable[[int, int], tuple[int, int]],
    iterations: int,
) -> None:
    """ Apply flood-fill outline effect to an image, given a function that
        yields the neighbours of a pixels and the number of iterations """
    if iterations < 1:
        return
    current_cells = get_adjacent(image, neighbours)
    next_cells: list[tuple[int, int]] = []
    for x, y in current_cells:
        image.putpixel((x, y), (0, 0, 0, 255))
    for _ in range(iterations - 1):
        for x, y in current_cells:
            for nx, ny in neighbours(x, y):
                if nx < 0 or nx >= image.width or ny < 0 or ny >= image.height:
                    continue
                if image.getpixel((nx, ny))[3] != 0:
                    continue
                image.putpixel((nx, ny), (0, 0, 0, 255))
                next_cells.append((nx, ny))
        current_cells = next_cells
        next_cells = []



# 4 neighbours (diamond)
with Image.open("sprite.png") as sprite:
    sprite = sprite.convert("RGBA")
    flood_fill(
        sprite,
        lambda x, y: [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)],
        10
    )
    sprite.save("4-neighbours.png")

# 8 neighbours (square)
with Image.open("sprite.png") as sprite:
    sprite = sprite.convert("RGBA")
    flood_fill(
        sprite,
        lambda x, y: [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1),
            (x + 1, y + 1), (x - 1, y + 1), (x + 1, y - 1), (x - 1, y - 1)],
        10
    )
    sprite.save("8-neighbours.png")

# Octagon
with Image.open("sprite.png") as sprite:
    side_length = OUTLINE_WIDTH / 2 * math.sin(math.pi / 8)
    diagonal_length = side_length / math.sqrt(2)
    sprite = sprite.convert("RGBA")
    # First apply 8 neighbours
    flood_fill(
        sprite,
        lambda x, y: [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1),
            (x + 1, y + 1), (x - 1, y + 1), (x + 1, y - 1), (x - 1, y - 1)],
        math.ceil(side_length)
    )
    # First apply 4 neighbours
    flood_fill(
        sprite,
        lambda x, y: [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)],
        math.ceil(diagonal_length)
    )
    sprite.save("octagon.png")