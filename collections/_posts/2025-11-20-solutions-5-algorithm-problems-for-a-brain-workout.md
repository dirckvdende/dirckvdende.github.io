---
layout: post
title: "[SOLUTIONS] 5 Algorithm Problems for a Brain Workout"
date: 2025-11-13 11:00:00 +0200
tags: Algorithms Puzzles Math Solutions
accent_color: "#4ec7adff"
front_image: /assets/code/5-algorithm-problems-to-get-your-brain-working/puzzle-pieces.jpg
thumbnail: /assets/code/5-algorithm-problems-to-get-your-brain-working/puzzle-pieces.jpg
---

These are the solutions to the five algorithm problems I posted last week. If you haven't tried them yet, follow the link below:

{% include center-button.html icon="link" text="5 Algorithm Problems for a Brain Workout" href="/blog/5-algorithm-problems-for-a-brain-workout/" %}

All problem data and complete solution scripts can be found on [GitHub](https://github.com/dirckvdende/dirckvdende.github.io/blob/main/assets/code/5-algorithm-problems-to-get-your-brain-working).

## Weighing Fruit - ★

This problem asked to determine the weight of an apple, given the following combined weights:

$$
    {\Large \begin{aligned}
        🍊🍊🍉 &= 8 \text{ kg} \\
        🍊🍉🍇 &= 7 \text{ kg} \\
        🍊🥥🍇 &= 13 \text{ kg} \\
        🍉🍌🍌🍎 &= 12 \text{ kg} \\
        🍉🥥🍌 &= 17 \text{ kg} \\
        🍇🍇🍇🥥 &= 13 \text{ kg}
    \end{aligned}}
$$

The only problem that can be reasonably solved without programming. It is possible to reason what the weights of all of the fruits are as follows:

1. Using the third and last equation, we can reason that one lemon weighs the same as two blueberries, since the rest of the equation on the left and right is the same.
2. We can similarly determine that a lemon weighs 1 kg more than a blueberry, using the first two equations.
3. Putting these first two steps together, we already know that a blueberry weighs 1 kg and a lemon 2 kg.
4. From the first equation we now know that the melon weighs 4 kg.
5. In the third equation the only weight we don't know is that of the coconut, which has to be 10 kg.
6. The fifth equation gives us the weight of the banana, which is 3 kg.
7. Finally, we use the fourth equation to determine that the apple weighs 4 kg.

Solving this problem (or a larger variant) can be automated by writing it as a system of linear equations:

$$

$$

Then the weights of the fruits can be found by multiplying the vector on the right with the inverse of the matrix on the left. I used [NumPy](https://numpy.org/) for this:

```py
a = np.array([
    [2, 1, 0, 0, 0, 0],
    [1, 1, 0, 0, 1, 0],
    [1, 0, 1, 0, 1, 0],
    [0, 1, 0, 2, 0, 1],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 1, 0, 3, 0],
])
b = np.array([8, 7, 13, 12, 17, 13])
x = np.linalg.solve(a, b)
print("Apple =", x[5])
print("[Lemon, Melon, Coconut, Banana, Grape, Apple] =", x)
```

Note: Obviously, the weights of the fruits are not realistic :)