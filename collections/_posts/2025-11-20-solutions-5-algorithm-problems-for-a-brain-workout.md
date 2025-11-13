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

This the only problem that can be reasonably solved without programming. It is possible to reason what the weights of all of the fruits are as follows:

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

In this problem we need to calculate the probability of getting 30 heads in a row when tossing a billion coins. We can model this as an [absorbing Markov chain](https://en.wikipedia.org/wiki/Absorbing_Markov_chain) with 31 states. Each state represents the number of heads in a row we've seen at this point. For example, if we have the sequence HTTHTHHH, we would be in state 3 (for having seen 3 heads in a row). If we have a sequence ending in tails, we are in state 0. For every state there are two transitions:

1. There is a 50% probability that we throw tails next, which means we go back to state 0.
2. There is a 50% probability that we throw heads next. If we are in state $n$, we'll go to state $n + 1$.

The exception to this is state 30, which we'll never leave, because once we've seen 30 heads in a row it doesn't matter what happens next. We want to know the probability of being in state 30 after a billion iterations of the Markov chain.

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

The matrix $P^{10^9}$ can be calculated in logarithmic time by using [exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring). The NumPy matrix class already implements this. The probability we're looking for is in the bottom left corner of this matrix, which turns out to be 37.228...%.

**Complexity:** $O(n^3 \log m)$, where $n$ is the number of heads we need to get in a row and $m$ is the total number of throws.

## Repeating Digits - ★★★★★

The problem is to find the length of the repeating digits in the decimal expansion of the following fraction:

$$
    \begin{aligned}
        \frac{1\ 213\ 432\ 333\ 743\ 539\ 155}{5\ 923\ 746\ 191\ 783\ 711\ 543}
    \end{aligned}
$$

I will give you the answer first, which is 2,518,577,681,506,866. Clearly, we can't simply generate the digits of the fraction and detect when they're repeating. However, it is useful to look at how these digits can be generated for smaller fractions. Suppose we want to calculate the decimal expansion of $\frac17$. We'll perform [long division](https://en.wikipedia.org/wiki/Long_division#Method):

1. First check how many times 7 fits in 1. This is zero (remainder 1), so we start with **0.**
2. Multiply 1 by 10 to get 10. 7 fits in 10 once (remainder 3), so the next digit is **1**
3. Multiply 3 by 10 to get 30. 7 fits in 30 four times (remainder 2), so the next digit is **4**
4. Multiply 2 by 10 to get 20. 7 fits in 20 twice (remainder 6), so the next digit is **2**
5. ...

We can continue this procedure indefinitely. At every step we take the remainder of the previous division, multiply it by 10, check how many times 7 (the denominator of the fraction) fits in this number. This will be the next digit. Written out in code we can generate the digits as follows:

```py
enum, denom = 1, 7
remainder = enum
while remainder > 0:
    remainder *= 10
    print("Next digit =", remainder // denom)
    remainder %= denom
```

In the case of $\frac17$ this procedure will continue forever. For fractions like $\frac14$ the process will stop when the remainder is zero. The digits loop when the remainder is a number we've already seen before.

At every iteration of the loop we assentially perform the following operation on the remainder $r$ given the denominator $d$:

$$
    r \rightarrow 10 r \mod d
$$

Looping $n$ times can be written as

$$
    r \rightarrow 10^n r \mod d
$$

Remember we want to find the moment the remainder loops, which happens when

$$
    r \equiv 10^n r \mod d
$$

In our case 10 and $d$ are coprime (the denominator is not divisible by 2 or 5), which means the only way this equality can hold is if

$$
    10^n \equiv 1 \mod d
$$

In other words, the solution will be the lowest $n > 0$ for which the above equality holds. We already know that this answer will be very large, so iterating over $n$ is not an option. We do, however, have a good starting point: [Euler's theorem](https://en.wikipedia.org/wiki/Euler%27s_theorem). Since 10 and $d$ are coprime, we have

$$
    10^{\varphi(d)} \equiv 1 \mod d
$$

Where $\varphi(d)$ is [Euler's totient function](https://en.wikipedia.org/wiki/Euler%27s_totient_function), which can be calculated quickly.

$$
    \phi(d) = 5\ 077\ 452\ 605\ 917\ 841\ 856
$$

We don't necessarily know if $\varphi(d)$ is the lowest number for which the equality holds. However, we do know that the lowest number will be a divisor of $\varphi(d)$, which means we can find the answer by checking all divisors. A naive method would be to iterate over all numbers lower than $\varphi(d)$ and check if they're divisors, but this is too slow. Even the smarter method of checking numbers up to $\sqrt{\varphi(d)}$ fails here because the number is too large. To find the divisors quickly, factorize $\phi(d)$ into primes:

$$
    \phi(d) = 2^6 \cdot 3^4 \cdot 7^2 \cdot 71 \cdot 577 \cdot 5\ 407 \cdot 90\ 239
$$

To find all divisors, determine all subsets (with duplicates) of prime factors and multiply the factors per subset. There are $7 \cdot 5 \cdot 3 \cdot 2 \cdot 2 \cdot 2 \cdot 2 = 1\ 680$ such subsets. Checking all of them yields that the lowest divisor for which $10^n \equiv 1 \mod d$ holds is

$$
    2\ 518\ 577\ 681\ 506\ 866
$$

This is the final answer.

Found any mistakes or have comments? Contact me on [LinkedIn](https://www.linkedin.com/in/dirck).