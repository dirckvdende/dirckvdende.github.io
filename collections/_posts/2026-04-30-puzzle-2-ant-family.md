---
layout: post
title: "Puzzle #2: Ant Family"
date: 2026-04-30 20:30:00 +0200
tags:
  - Puzzle
accent_color: "#5eb277"
front_image: /assets/img/puzzle-piece.png
thumbnail: /assets/img/puzzle-piece.png
redirect_from:
  - /p/2/
---

Another puzzle today! And this one's all about ants, or more specifically, their genes! Suppose we have a collection of ants we know are all related to each other in some way. In our fictional universe, each ant has 6 genes. Every ant shares exactly 3 genes with its parent (we'll also pretend ants have one parent). Specifically this means that if we have two ants with ordered lists of genes, then one ant can only be the parent of the other if these lists are equal at exactly 3 positions. For example, ATGGCG can be a parent of ATCTAG, but not of TACGGG. Note that the converse does not have to be true: Two ants that share 3 genes don't necessarily have to be parent and child.

Place the ants on the family trees such that every ant is placed directly below an ant it shares exactly 3 genes with. There can be multiple solutions.

![Puzzle image](/assets/puzzles/2/puzzle.png)

If you'd like to download or print the puzzle. I've made the puzzle available as a PDF:

{% assign printable_url = "/assets/puzzles/2/puzzle.pdf" | relative_url %}
{% include center-button.html href=printable_url text="Download as PDF" icon="download" download="" %}