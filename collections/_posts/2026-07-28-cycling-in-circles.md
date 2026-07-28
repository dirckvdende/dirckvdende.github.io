---
layout: post
title: "Cycling in Circles"
date: 2026-07-28 21:00:00 +0200
tags:
  - Puzzle
  - Math
  - Cycling
accent_color: "#ffb721"
front_image: /assets/posts/cycling-in-circles/circle_colored.png
thumbnail: /assets/posts/cycling-in-circles/circle_colored.png
---

I love cycling. Recently, on a late afternoon while I was cycling I got the feeling that I had to put in more effort than usual. Since I usually cycle in a big loop, this does not make much sense: For all of the effort you have to put in to cycle agaist the wind, you get rewarded by being able to cycle with a tailwind just as much, right? Well, not exactly. There is one factor that can play quite a big role: Areas where the wind is blocked by buildings. My usual route is quite varied in this aspect, so it can swing quite a bit depending on wind direction.

This got me thinking: What is the optimal wind direction, in the sense that I would have to put in as little effort as possible? I decided to model this mathematically. And as you'll see in this post, the problem is easier to solve than you might think.

## Modeling the Problem

Let's first model our problem as simple as possible. Suppose we're cycling in a circle, where some areas of the circle are covered by buildings. In these areas there won't be any wind. In all other areas there will be wind, which is coming from a constant direction with constant force.

![Illustration of the problem](/assets/posts/cycling-in-circles/circle_annotated.png)

We'll model the wind direction as an angle $\alpha \in [0, 2\pi)$ and the areas without any buildings (so the areas *with* wind) as intervals $[\theta_1, \theta_1'], \dots, [\theta_n, \theta_n']$. It is reasonable to assume the force we're experiencing from the wind at some point on the circle $t$ is equal to $\cos(t + \alpha)$.

This is all we need to formulate our problem. After this I'll outline my solution to this problem. If you'd like to have a tackle at this yourself, stop reading and grab some pen and paper :)

## Solution

To start solving this problem, we first need to determine the energy that is expended when cycling in this circle. Since we're interested in minimizing our effort, we only need to calculate the total *extra* energy expended in the areas where there are no buildings. This is proportional to the following quantity, which we'll call $E_\alpha$:

$$
  \begin{align}
    &E_{extra}\ \propto\ E_\alpha \\
    &=\ \int_0^{2\pi} \cos(t + \alpha) \cdot 1\{t \in [\theta_i, \theta_i]\}\ dt
  \end{align}
$$

We integrate over the force that we're experiencing in the direction that we're cycling, at each point along the circle. This is proportional to $\cos(t + \alpha)$ when we're in an open area with wind, and $0$ in areas with buildings. If we assume all of the intervals $[\theta_i, \theta_i']$ are disjoint, we can write this as

$$
  E_\alpha = \sum_i \int_{\theta_i}^{\theta_i'} \cos(t + \alpha)\ dt
$$

This is a pretty easy intergral to solve, since we can use the primitive of $\cos(t + \alpha)$, which is $\sin(t + \alpha)$.

$$
  \begin{align}
    E_\alpha &= \sum_i \left(\sin(\theta_i' + \alpha) - \sin(\theta_i + \alpha)\right) \\
    &= \sum_i \left(\sin(\theta_i' + \alpha) + \sin(\theta_i + \alpha + \pi)\right) \\
    &= \sum_i (\cos(\theta_i' + \alpha - \pi/2) \\
    & \quad +\ \cos(\theta_i + \alpha + \pi/2))
  \end{align}
$$

To make things a bit easier in the next step, we'll denote $\delta_1 = \theta_1 + \pi/2$, $\delta_2 = \theta_1' - \pi/2$, $\delta_3 = \theta_2 + \pi/2$, $\delta_4 = \theta_2' - \pi/2$, $\dots$ This makes the above sum a lot nicer:

$$
  E_\alpha = \sum_i \sin(\delta_i + \alpha)
$$

## A Nice Theorem

After getting to this part I was a bit stuck: Adding abitrary sine waves does not usually yield a nice expression. However, these sine waves all have the frequency! This means that adding up these sine waves will result in another pure sine wave, again with the same frequency! This is known as the [Harmonic Addition Theorem](https://mathworld.wolfram.com/HarmonicAdditionTheorem.html). It states that the sum of sine waves above can be written as the following pure sine wave:

$$
  E_\alpha = A \cos(\delta + \alpha)
$$

where

$$
  \begin{align}
    A &= \sqrt{\sum_i \sum_j \cos(\delta_i - \delta_j)} \\
    \delta &= \tan^{-1} \frac{\sum_i \sin \delta_i}{\sum_i \cos(\delta_i)}
  \end{align}
$$

If we know the value of $\delta$, we know the minimum of $E_\alpha$ will be attained at $\alpha = \pi - \delta$. This is the wind angle where we have to expend the least amount of energy.

And there you have it! Calculate $\pi - \delta$ using the procedure above and you'll know the optimal wind angle!

## Conclusion

Obviously, modeling the cycling route as a circle is not quite accurate to real life. Let alone assuming there are areas where there is absolutely no wind and others where wind is constant. Even assuming a constant wind direction is not accurate... Depite this, I thought this was quite interesting. And who knows, maybe some day I'll try to optimize my routes using Harmonic Addition Theorem.
