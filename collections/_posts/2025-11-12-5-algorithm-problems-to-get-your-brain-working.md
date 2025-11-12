---
layout: post
title: "5 Algorithm Problems to Get Your Brain Working"
date: 2025-11-12 11:00:00 +0200
tags: Game Strategy Simulation
accent_color: "#4ec7adff"
# front_image: /assets/code/exploring-flip-7-strategies/flip_7.jpg
# thumbnail: /assets/code/exploring-flip-7-strategies/flip_7.jpg
---

## Weighing Fruit - ★

Find out what the weight of an apple (🍎) is using the formulas below. There is exactly one possible solution.

![Maze with start and finish](/assets/code/5-algorithm-problems-to-get-your-brain-working/weighing-fruit/image-small.png)

## Fewest Left Turns - ★★

Given is the maze below. Find a path from start to finish that minimizes the number of left turns you take. You're not allowed to turn around on the spot, but you're allowed to visit the same square multiple times. A left turn still counts if you're in a hallway and there is no other direction to go.

The maze can be downloaded as a <a href="{{ '/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/data.txt' | relative_url }}" download>text file</a>. Keep in mind that you start on the left of the bottom row and end on the right of the top row.

![Maze with start and finish](/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/image-small.png)

## One Billion Coins - ★★★★

Suppose you toss a billion (1,000,000,000) coins in sequence, with a 50/50 chance of it landing on heads/tails. What is the chance the coins will land on heads 30 times in a row, at some point during all of your throws?

Note that the probability of two heads in a row when tossing three coins is 3/8, since there are three combinations where two heads land in a row: HHH, HHT, THH.

## Answers

Click the boxes below to reveal the answers of the problems. Detailed explanations will be in a separate blog post next week.

Weighing Fruit: {% include hidden_text.html id="weighing-fruit-hidden" text="The apple weighs 4 kg. The other fruits have the following weights: Lemon = 2 kg, Coconut = 10 kg, Banana = 3 kg, Grape = 1 kg, Apple = 2 kg" %}<br>
Fewest Left Turns: {% include hidden_text.html id="fewest-left-turns-hidden" text="11 left turns" %}<br>
One Billion Coins: {% include hidden_text.html id="one-billion-coins-hidden" text="37.22801307691707... %" %}<br>
