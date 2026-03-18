---
layout: post
title: A Simple Linear-Time Sprite Outline Algorithm
date: 2026-03-18 22:00:00 +0100
tags:
  - Image Processing
  - Algorithms
  - Graphics
accent_color: "#dc9212"
front_image: /assets/code/sprite-outline-algorithm/noise.jpg
thumbnail: /assets/code/sprite-outline-algorithm/noise.jpg
---

For a project I'm working on, I needed something very simple: A way to draw an outline around a sprite. To my surprise, I couldn't find much information on simple techniques to do this. Hence, here is the solution I went with. :)

## The Problem

In out problem we have an image, which is partially transparent. Let's use the following sprite as an example:

<img src="/assets/code/sprite-outline-algorithm/sprite.png" alt="Original sprite" class="center-image" style="image-rendering: pixelated; width: 16em;">

We want to draw a black outline around the part of the image that is not transparent. Ideally, in such a way that the thickness of the outline is the same everywhere. How do we do that?

## A Slow Solution

One solution is to go over every pixel. Then, if this pixel is on the edge of the sprite, draw a circle black circle around it. When you only color those pixels black that are transparent, you get a perfect outline effect.

The problem lies in this algorithm's complexity. Suppose we have an image of $n$ pixels and want to draw a border of width $w$. In total this algorithm requires $O(nw^2)$ operations, since we go over every pixel individually, and for every pixel we draw a circle of size $O(w^2)$. When you're not doing stuff in parallel, this can be very slow!

## Faster Alternatives

An alternative to this that runs in $O(n)$ time, is a [Breadth-First-Search](https://en.wikipedia.org/wiki/Breadth-first_search) algorithm. I won't go into detail here, but the algorithm essentially repeatedly paints the four direct neighbours of the currently painted cells. It allows us to determine the "distance" between every empty pixel and the sprite, in linear time!

However, notice how I mentioned "distance"? This isn't the usual "Euclidean" distance, this is the "Manhattan" distance, where a distance is measured as the sum of the distances along the x and y coordinates. This causes some funky results, where the outline appears much more thin along a diagonal part of the image:

<img src="/assets/code/sprite-outline-algorithm/4-neighbours.png" alt="4 Neighbours algorithm" class="center-image" style="image-rendering: pixelated; width: 16em;">

Instead of repeatedly painting the *four* direct neighbours, we could also paint all *eight* neighbours, including diagonals. This has the exact opposite effect, with the outline being thicker along diagonals:

<img src="/assets/code/sprite-outline-algorithm/8-neighbours.png" alt="8 Neighbours algorithm" class="center-image" style="image-rendering: pixelated; width: 16em;">

## A Nice Middle Ground

Here's the trick to make this look better: Use both algorithms! We can think of the "8 neighbours" algorithm as drawing squares around the sprite, while the "4 neighbours" algorithm draws diamonds. If we apply one first, and then the other, we're drawing octagons around the sprite. Again, I won't go into the details, but it turns out that if you want to draw an outline with width $w$, you need to apply the "8 neighbours" algorithm with this many iterations:

$$w \sin(\pi / 8)$$

The "4 neighbours" algorithm needs to be run with this many iterations:

$$\frac{w \sin(\pi / 8)}{\sqrt2}$$

This results in the following nice-looking image:

<img src="/assets/code/sprite-outline-algorithm/octagon.png" alt="Octagon algorithm" class="center-image" style="image-rendering: pixelated; width: 16em;">

## Conclusion

Of course there are still shortcomings to an algorithm like this. For one, you can still see that it is drawing an octagon when you create a very thick outline on a very small sprite. Another is that it is not parallelizable, unline the "slow solution" I described (which can make it faster in reality, on a GPU). However, I still thought this little algorithm was worth sharing!

*Note: All of the code I used to generate the images in this post can be found on [GitHub](https://github.com/dirckvdende/dirckvdende.github.io/tree/main/assets/code/sprite-outline-algorithm).*