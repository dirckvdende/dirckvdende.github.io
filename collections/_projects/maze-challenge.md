---
layout: project
title: Minimum Memory Maze Challenge
front_image: /assets/img/projects/maze-challenge.png
accent_color: "#727272"
tags:
  - Challenge
  - Algorithm
  - Random
  - Web app
thumbnail: /assets/img/projects/maze-challenge.png
---

I made a small challenge to solve a maze while keeping as little memory as possible between steps. I may write a blog post about this later describing some of my own strategies. For now, have fun puzzling!

{% include center-button.html href="https://dirck.dev/maze-challenge/" text="Maze challenge web app" icon="link" %}

Different algorithms are used to generate the mazes. Some will generate mazes with loops, making a "hug the left wall" strategy unfeasible. Below is a video showing a fairly simple DFS method passing the challenge. For every cell a bit in memory is reserved to indicate if it has been visited or not. Another two bits per cell are used to indicate the path to follow backward if all adjacent cells have been visited.

<iframe style="width: 100%; aspect-ratio: 16 / 9" src="https://www.youtube-nocookie.com/embed/4QofZBiB_E0?si=SLlsHj8vC2hRv7Oi" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>