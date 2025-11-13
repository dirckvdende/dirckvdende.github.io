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
    \begin{pmatrix}
        2 & 1 & 0 & 0 & 0 & 0 \\
        1 & 1 & 0 & 0 & 1 & 0 \\
        1 & 0 & 1 & 0 & 1 & 0 \\
        0 & 1 & 0 & 2 & 0 & 1 \\
        0 & 1 & 1 & 1 & 0 & 0 \\
        0 & 0 & 1 & 0 & 3 & 0
    \end{pmatrix} \begin{pmatrix}
        Lemon \\ Melon \\ Coconut \\ Banana \\ Grape \\ Apple
    \end{pmatrix} = \begin{pmatrix}
        8 \\ 7 \\ 13 \\ 12 \\ 17 \\ 13
    \end{pmatrix}
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

**Complexity:** $O(n^3)$, where $n$ is the number of different fruits (better when using a better matrix inversion algorithm).

## Fewest Left Turns - ★★

This problem asked to find the route from the start to the end of a maze using as few left turns as possible. Note that we can model the maze as a graph with connections between adjacent squares. To keep track of our current orientation (and with that whether we're turning left or not), we copy the graph 4 times, each representing a different direction that we're currently facing (up, down, left, right). Then we connect between the 4 graphs depending on which way we turn, and if we turn left the length of the edge will be 1, otherwise it will be 0. Now we can run [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) on this new graph to find the shortest route, the length of which will be the number of left turns taken. This turns out to be 11.

**Complexity:** $O(n \log n)$, where $n$ is the number of squares in the maze. An $O(n)$ solution is possible.

## Putting Out the Fire - ★★★

The problem asks to match firefighters with fires, such that the maximum distance between any firefighter and their fire is minimized. We can solve this in two steps.

First, determine the distance from every firefighter to every fire. For every firefighter this can be done using a breath first search. This way, the distances to all of the fires can be determined at once. Use these distances to create a weighted bipartite graph. Each firefighter is connected to every fire through an edge with a weight equal to the distance between the firefighter and the fire.

To determine the lowest maximum distance, we can do a binary search. Now we need to answer the question "Is possible to match firefighers with fires such that all distances are less than $D$?". We can answer this by using the graph we made, and removing all edges with a weight higher than $D$. If this new graph has a [perfect matching](https://en.wikipedia.org/wiki/Perfect_matching), we can match the firefighters with fires. Since this graph is bipartite, this can be checked efficiently (see also [this Wikipedia page](https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm)).

**Complexity:** $O(kn + k^2\sqrt{k}\log n)$, where $k$ is the number of firefighters/fires and $n$ is the number of squares in the maze.

## One Billion Coins - ★★★★

In this problem we need to calculate the probability of getting 30 heads in a row when tossing a billion coins. We can model this as an [absorbing Markov chain](https://en.wikipedia.org/wiki/Absorbing_Markov_chain) with 31 states. Each state represents the number of heads in a row we've seen at this point. For example, if we have the sequence HTTHTHHH, we would be in the state corresponding with having seen three heads. If we have a sequence ending in tails, we are in the state corresponding with zero heads. For every state there are two transitions:

1. There is a 50% probability that we throw tails next, which means we go back to state zero.
2. There is a 50% probability that we throw heads next. If we are in state $n$, we'll go to state $n + 1$.

The exception to this is state 30, which we'll never leave, because once we've seen 30 heads in a row it doesn't matter what happens next. After a billion iterations of the Markov chain, we want to know the probability of being in state 30.

The transitions of the Markov chain can be written as a $31 \times 31$ matrix:

$$
    P = \begin{pmatrix}
        \frac12 & \frac12 & \frac12 & \dots & \frac12 & \frac12 & 0 \\
        \frac12 & 0 & 0 & \dots & 0 & 0 & 0 \\
        0 & \frac12 & 0 & \dots & 0 & 0 & 0 \\
        \vdots & \vdots & \vdots & \ddots & \vdots & \vdots & \vdots \\
        0 & 0 & 0 & \dots & 0 & 0 & 0 \\
        0 & 0 & 0 & \dots & \frac12 & 0 & 0 \\
        0 & 0 & 0 & \dots & 0 & \frac12 & 1
    \end{pmatrix}
$$

To find the probability of ending up in state 30 after a billion iterations, we want to know the last entry in the following vector (note that we start in state 0):

$$
    P^{10^9}\begin{pmatrix}
        1 \\ 0 \\ 0 \\ \vdots \\ 0
    \end{pmatrix}
$$

The matrix $P^{10^9}$ can be determined in logarithmic time by using [exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring). The NumPy matrix class already implements this. The probability we're looking for is in the bottom left corner of this matrix, which turns out to be 37.228...%.

**Complexity:** $O(n^3 \log m)$, where $n$ is the number of heads we need to get in a row and $m$ is the total number of throws.