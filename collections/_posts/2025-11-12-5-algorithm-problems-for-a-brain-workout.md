---
layout: post
title: "5 Algorithm Problems for a Brain Workout"
date: 2025-11-12 11:00:00 +0200
tags: Game Strategy Simulation
accent_color: "#4ec7adff"
front_image: /assets/code/5-algorithm-problems-to-get-your-brain-working/puzzle-pieces.jpg
thumbnail: /assets/code/5-algorithm-problems-to-get-your-brain-working/puzzle-pieces.jpg
---

Do you want a brain workout? Look no further. I've created five algorithmic puzzles for you to solve using your reasoning and programming skills. At the bottom of the page you'll find answers so you can check your own solutions. You can use the internet if you want, but it may be more fun to try it with as little help as possible! All problems can be solved by writing code that runs in less than one minute on any modern computer.

## Weighing Fruit - ★

Find out what the weight of an apple (🍎) is using the formulas below. There is exactly one possible solution.

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

## Fewest Left Turns - ★★

Given is the maze below. Find a path from start to finish that minimizes the number of left turns you take. You're not allowed to turn around on the spot, but you're allowed to visit the same square multiple times. A left turn still counts if you're in a hallway and there is no other direction to go.

The maze can be downloaded as a <a href="{{ '/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/data.txt' | relative_url }}" download>text file</a>. Keep in mind that you start on the left of the bottom row and end on the right of the top row.

![Maze with start and finish](/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/image-small.png)

## Putting Out the Fire - ★★★

There are 60 firefighters in a building with 60 fires (see the visualization below). At every water drop icon there's a firefighter. Each firefighter is carrying enough water with them to put out exactly one fire. Each firefighter also moves exactly one grid square per minute (vertically or horizontally, not diagonally). When a firefighter reaches a fire, they put it out instantly. By assigning the firefighters to the fires, what's the minimum amount of time it will take for them to put out all of the fires?

All firefighters work fully independently. They don't have to wait on each other, and they can occupy the same spot at the same time.

The map can be downloaded as a <a href="{{ '/assets/code/5-algorithm-problems-to-get-your-brain-working/putting-out-the-fire/data.txt' | relative_url }}" download>text file</a>. The Xs represent the walls, the Ws are firefighters, and the Fs are fires. Spaces are places the firefighters can move between. Note that the only squares the firefighters are not able to move through are the walls.

![Map with the fires and firefighters](/assets/code/5-algorithm-problems-to-get-your-brain-working/putting-out-the-fire/image-small.png)

## One Billion Coins - ★★★★

Suppose you toss a billion (1,000,000,000) coins in sequence, with a 50/50 chance of it landing on heads/tails. What is the chance the coins will land on heads 30 times in a row, at some point during all of your throws?

Note that the probability of two heads in a row when tossing three coins is 3/8, since there are three combinations where two heads land in a row: HHH, HHT, THH.

## Answers

Click the boxes below to reveal the answers of the problems. Detailed explanations will be in a separate blog post next week.

Weighing Fruit: {% include hidden_text.html id="weighing-fruit-hidden" text="The apple weighs 2 kg. The other fruits have the following weights: Lemon = 2 kg, Melon = 4 kg, Coconut = 10 kg, Banana = 3 kg, Grape = 1 kg" %}<br>
Fewest Left Turns: {% include hidden_text.html id="fewest-left-turns-hidden" text="11 left turns" %}<br>
Putting Out the Fire: {% include hidden_text.html id="putting-out-the-fire-hidden" text="7 minutes" %}<br>
One Billion Coins: {% include hidden_text.html id="one-billion-coins-hidden" text="37.22801307691707... %" %}<br>

Found an error? Let me know on [LinkedIn](https://www.linkedin.com/in/dirck).