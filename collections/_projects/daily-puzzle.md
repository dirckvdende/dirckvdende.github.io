---
layout: project
title: Daily Puzzle
front_image:
  - url: /assets/img/projects/daily-puzzle_300.jpg
  - url: /assets/img/projects/daily-puzzle_600.jpg
    scale: 2
  - url: /assets/img/projects/daily-puzzle_1200.jpg
    scale: 4
accent_color: "#8b43c0"
tags:
  - Puzzle
  - Algorithm
  - Web app
---

A daily puzzle web-app that has a different type of puzzle for every day of the week. Puzzles are randomly generated. The puzzles are rougly ordered from easy to hard from Monday till Sunday. Each puzzles requires a different way of thinking to solve. Try today's puzzle by clicking below:

{% include center-button.html href="https://dirck.dev/daily-puzzle/" text="Daily puzzle web app" icon="link" %}

Each puzzle can be solved in a certain minimum number of moves, which is calculated using dynamic programming or brute force, depending on the puzzle. The source code is run completely in the user's browser, which allowed me to host it using GitHub pages. This was accomplished by writing a custom random number generator in JavaScript, which uses the current date as the initial seed. This way the puzzle is the same for everyone without the need for a server.