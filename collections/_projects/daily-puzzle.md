---
layout: project
title: Daily Puzzle
front_image: /assets/img/projects/daily-puzzle.jpg
accent_color: "#8b43c0"
tags:
  - Puzzle
  - Algorithm
  - Web app
---

A daily puzzle web-app that has a different type of puzzle for every day of the week. Puzzles are randomly generated. The puzzles are rougly ordered from easy to hard from Monday till Sunday. Each puzzles requires a different way of thinking to solve. Try today's puzzle by clicking below:

{% include center-button.html href="https://dirck.dev/daily-puzzle/" text="Daily puzzle web app" icon="link" %}

Each puzzle can be solved in a certain minimum number of moves, which is calculated using dynamic programming or brute force, depending on the puzzle. The source code is run completely in the user's browser, which allowed me to host it using GitHub pages. This was accomplished by writing a custom random number generator in JavaScript, which uses the current date as the initial seed. This way the puzzle is the same for everyone without the need for a server.

## Overview of the puzzles

As mentioned, there is a different type of puzzle for every day of the week. If you'd like to try them all, you can click the history icon in the top right to view puzzles from previous days. Below follows a brief description of all of the puzzles and how the optimal solution is calculated.

### Monday: Light

The Monday puzzle is the easiest puzzle. It requires the solver to place lamps on a grid, and match the required luminocity at some of the marked positions. The minimum number of moves is calculated using brute-force over all 376,992 possible placements of 5 bulbs on a 6 by 6 grid. It could be further optimized by using backtracing, but I didn't implement this since the application was already fast enough.

### Tuesday: Salesman

This puzzle consists of a randomly generated graph, where the solver has to visit all nodes in as few moves as possible. The starting position is predetermined. The generated graph consists of 18 nodes. The minimum number of moves is calculated by using dynamic programming, by keeping track of a table with entries (current node, visited nodes). The visited nodes are represented using a bitset.

### Wednesday: Spread

Wednesday sees a more original puzzle. The solver has to place tiles on a 5 by 5 grid, then press a "play" button to let the tiles "spread". Each tiles has arrows on it indicating in which directions it spreads. For example there is a tile that has an up and a down arrow, which will duplicate to the cells above and below it while spreading, if those tiles are not occupied already. This process keeps repeating itself, meaning that during the next step the tiles 2 cells below or above the original cell can be filled. The process terminates once the grid no longer changes, which happens if the grid is full or there are empty cells which are "walled off".

Unlike the other puzzles, the minimum number of initial tile placements is always the same. The minimum number is always four, which can only be accomplished by placing one of each type of tile on the grid.

### Thursday: Switch

This is a variant of a classic puzzle where the solver clicks cells on a grid, which switches the cell between an "on" and an "off" state. The aim of the solver is to turn the entire 4 by 4 grid "off". This seems easy, but there is a twist: If the player clicks a cell, some of the surrounding cells will be switched as well! In the variant of the game I made the solver can choose between three different patterns of switching cells: A 3 by 3 block, an "X", and a "+" of cells.

The minimum number of solutions is calculated using a Python script that can be found in the [source code](https://github.com/dirckvdende/daily-puzzle/blob/main/src/puzzle/switch/optimal.py). The text file this Python code generates is used by the web app. The script itself calculates the minimum number of moves starting from an empty state and performing a breath-first search to every possible state. Already visited states are stored using dynamic programming, representing states as 16-bit bitstrings.

### Friday: Tower

This is another more original puzzle. The solver is presented with a tower of "blocks" of different colors, whichs they need to shrink down to a single block. This can be done by clicking one of the block, which will perform an action depending on the color of the block. Some examples of actions include making the color of the block above it warmer (red), swapping the blocks above and below the current block (cyan), and removing the current block from the tower (yellow).

The solution of the puzzle is again calculated using a breath-first search representing states using base-7 representations (because there are 7 colors/actions). Unlike the switch puzzle, however, the calculation happens in the user's browser and is not done beforehand.

### Saturday: Operator

In this puzzle the solver is presented with a list of three numbers, initially all set to zero. The solver can perform any of 6 actions to change these numbers, for example incrementing the last number with one, adding the first two numbers and storing the result in the third, etc. The user is presented with a "goal", which is a list of three numbers that they must transform the original list into. Numbers are limited between -99 and 99. This limit makes finding the minimum number of moves using a breath-first search and dynamic programming easy and quick.

### Sunday: Slide

A variant of the classic slide puzzle with one open hole on a 4 by 4 grid. It is made slightly more difficult (at least, I think it's more difficult) by the fact that some of the tiles are identical, making it unclear which tile needs to end up where (however, this does also create some freedom). The minimum number of moves is calculated using breath-first search and memoization, encoding states using base 4 numbers. Although the possible number of states to search through is quite high (3,603,600), the algorithm is generally finished relatively quickly because of the BFS approach.
