---
layout: post
title: "5 Algorithm Problems to Get Your Brain Working"
date: 2025-11-12 11:00:00 +0200
tags: Game Strategy Simulation
accent_color: "#4ec7adff"
# front_image: /assets/code/exploring-flip-7-strategies/flip_7.jpg
# thumbnail: /assets/code/exploring-flip-7-strategies/flip_7.jpg
---

## Fewest Left Turns - ★★

Given is the maze below. Find a path from start to finish that minimizes the number of left turns you take. You're not allowed to turn around on the spot, but you're allowed to visit the same square multiple times.

The maze can be downloaded as a <a href="{{ '/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/data.txt' | relative_url }}" download>text file</a>. Keep in mind that you start on the left of the bottom row and end on the right of the top row.

![Maze with start and finish](/assets/code/5-algorithm-problems-to-get-your-brain-working/fewest-left-turns/image-small.png)

## One Billion Coins - ★★★★

Suppose you toss a billion (1,000,000,000) coins in sequence, with a 50/50 chance of it landing on heads/tails. What is the chance the coins will land on heads 30 times in a row, at some point during all of your throws?

Note that the probability of two heads in a row when tossing three coins is 3/8, since there are three combinations where two heads land in a row: HHH, HHT, THH.

## Answers

Click the boxes below to reveal the answers of the problems. Detailed explanations will be in a separate blog post next week.

Fewest Left Turns: {% include hidden_text.html id="fewest-left-turns-hidden" text="11 left turns" %}<br>
One Billion Coins: {% include hidden_text.html id="one-billion-coins-hidden" text="0.3722801307691707..." %}
