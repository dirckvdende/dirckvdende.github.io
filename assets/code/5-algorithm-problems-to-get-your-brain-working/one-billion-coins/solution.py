
import numpy as np

COINS = 1_000_000_000
IN_A_ROW = 30

m = np.zeros([IN_A_ROW + 1, IN_A_ROW + 1])
for i in range(IN_A_ROW):
    m[0, i] = .5
    m[i + 1, i] = .5
m[IN_A_ROW, IN_A_ROW] = 1.0
m = np.matrix(m)
final_matrix = m ** COINS
print(final_matrix[IN_A_ROW, 0])