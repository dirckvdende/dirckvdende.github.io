
import numpy as np

# [Lemon, Melon, Coconut, Banana, Grape, Apple]
a = np.array([
    [2, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 0],
    [1, 0, 1, 0, 1, 0],
    [0, 1, 0, 2, 0, 1],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 3, 0],
])
b = np.array([8, 5, 13, 12, 13, 3])
x = np.linalg.solve(a, b)
print("Apple =", x[1])
print("[Lemon, Melon, Coconut, Banana, Grape, Apple] =", x)