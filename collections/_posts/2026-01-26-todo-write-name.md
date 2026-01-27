---
layout: post
title: Simulating Millions of Flip 7 Games to Find the Best Strategy
# TODO: Update
date: 2026-01-26 00:00:00 +0100
tags: Game Strategy Simulation
accent_color: "#cd2a9c"
front_image: /assets/code/flip-7-part-2/flip_7.jpg
thumbnail: /assets/code/flip-7-part-2/flip_7.jpg
head: <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
---

A few months ago, I wrote a blog post about a simple but very fun game called [Flip 7](https://boardgamegeek.com/boardgame/420087/flip-7). In the last post we discussed some possible strategies and ran experiments on a simplified version of the game. Today I want to improve on that analysis by truly simulating entire games, including action cards and opponents!

If you'd like to read up on the rules of the game, you can find them on [Board Game Geek](https://boardgamegeek.com/boardgame/420087/flip-7/files) or you can read the overview in [my last post](/blog/exploring-flip-7-strategies/).

<style>
    .chart {
        aspect-ratio: 2 / 1;
        position: relative;
    }

    @media screen and (max-width: 500px) {
        .chart {
            aspect-ratio: 3 / 2;
        }
    }

    .chart > canvas {
        position: absolute;
    }
</style>

<script>
    function setChartFont() {
        Chart.defaults.font.size = window.innerWidth <= 500 ? 9 : 12
        Chart.defaults.font.family = "'Ubuntu', sans-serif"
    }

    setChartFont()
    window.addEventListener("resize", setChartFont)
</script>

## Drawing until Reaching a Target Score

A simple strategy we discussed last time is drawing cards until you've reached some score that round. Without action cards, the expected score in a single round was highest when targeting a score between 20 and 27.

We'll expand on that strategy by always giving flip 3 and freeze cards to the opponent with the highest score. Of course, we take the second chance card ourselves if possible. We'll also not stop drawing if we have a second chance card (since we'd almost never bust). I simulated a player with a specific target score playing 100,000 games. Each time they play against three players which have random target scores between 1 and 50. The number of games the player won (per target score) is shown below.

It seems the analysis from last time is indeed correct! Targeting a score between 20 and 27 still works best. The optimal value seems to be 25, so we'll use that to compare other strategies next.

<div class="chart"><canvas id="chart1"></canvas></div>

<script>
const chart1data = [1200, 1216, 1632, 2028, 2655, 3591, 5344, 7018, 10210, 13725, 18695, 24122, 30150, 31908, 34429, 36968, 38880, 40798, 42729, 43738, 44993, 45757, 45904, 45871, 46299, 45511, 45028, 44078, 43096, 41747, 40653, 39092, 37399, 35517, 34228, 32796, 31074, 29562, 27769, 25789, 24374, 23058, 21514, 20343, 19305, 17943, 17075, 16258, 15180, 14476, ]
new Chart(document.getElementById("chart1"), {
    type: "line",
    data: {
        labels: chart1data.map((_, index) => index + 1),
        datasets: [{
            label: "Number of games won",
            borderColor: "#cd2a9c",
            backgroundColor: "#cd2a9c",
            data: chart1data,
        }]
    },
    options: {
        maintainAspectRatio: false,
        plugins: {
            legend: { display: false },
        },
        scales: {
            x: {
                title: {
                    display: true,
                    text: "Target score",
                }
            },
            y: {
                title: {
                    display: true,
                    text: "Games won (out of 100,000)",
                }
            },
        }
    },
})
</script>

## Calculating the Expected Score

Another strategy discussed in the previous post is this: If the expected score of our hand after a draw is higher than our current score, we draw another card. This strategy keeps track of which cards are still in the draw pile. We'll ignore the effects of freeze and flip 3 cards, since they can be quite complicated. The strategy already ensures that we don't pass if we have a second chance card.

I simulated a million games of someone with this strategy playing against two players who draw until 25, and one which never passes. Unlike last time, there is quite a big improvement compared to the "draw until 25" strategy!

<div class="chart"><canvas id="chart2"></canvas></div>

<script>
const chart2data = [354983, 306116, 304258, 34643]
new Chart(document.getElementById("chart2"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Till 25", "Draw Till 25", "Draw Till Bust"],
        datasets: [{
            label: "Number of games won",
            borderColor: ["#cd2a9c", "#d663b4", "#d663b4", "#df91c7"],
            backgroundColor: ["#cd2a9c", "#d663b4", "#d663b4", "#df91c7"],
            data: chart2data,
        }]
    },
    options: {
        maintainAspectRatio: false,
        plugins: {
            legend: { display: false },
        },
        scales: {
            x: {
                title: {
                    display: true,
                    text: "Strategy",
                }
            },
            y: {
                title: {
                    display: true,
                    text: "Games won (out of 1,000,000)",
                }
            },
        }
    },
})
</script>

## The Problem with Complicated Strategies

The problem with highly effective strategies like this is that they can realistically only be executed by a computer. You'd have to remember all of the cards that are still in the draw pile, determine the score you'd get after drawing each card, then add all of those scores up, every single turn!

This is a bit difficult, so we'll explore some alternatives, and see how they perform against this "near-perfect" strategy.

## Catching Up with the Leader

A strategy I've seen used in practise a lot is to draw more or fewer cards based on the scores of your opponents. If the leader is very far ahead, it may be beneficial to draw more cards to try to catch up. What we'll try next is based on that.

Instead of always targeting a score of 25, we'll add some offset based on how far ahead the leading opponent is (or behind, if you're leading). We'll add some fixed amount $\delta$ to the target score for each point the opponent is ahead. The formula for determining the new target score $T$, given the best opponent score $BS$ and our score $OS$, is

$$
    T = 25 + \delta \times (BS - OS)
$$

Now the question is: Which value of $\delta$ works best? Letting a player with differing values of $\delta$ play against players who simply target a score of 25 gave the results shown in the chart below.

If you look carefully, you can see the peak (i.e. the optimal strategy) is around 0.1. So using a value of 0.1 for delta work *slightly* better than simply targeting 25.

This is a lot of math, so let me summarize: A good strategy is to stop drawing cards after reaching a score of 25 plus 10% of the difference between the score of your best opponent and your own score. If you're the leader, this difference is subtracted.

<div class="chart"><canvas id="chart3"></canvas></div>

<script>
const chart3data = [8867, 9627, 9942, 10672, 11123, 11736, 12303, 13114, 13818, 14494, 15447, 15945, 16784, 17737, 18455, 19223, 19901, 20727, 21481, 21804, 22932, 22937, 23664, 24386, 24544, 25099, 25503, 25323, 25780, 25570, 25657, 25758, 25553, 25445, 25434, 25165, 24915, 24823, 24624, 24374, 23984, 23293, 23135, 22588, 22140, 22080, 21641, 20877, 20506, 20235, ]
new Chart(document.getElementById("chart3"), {
    type: "line",
    data: {
        labels: chart3data.map((_, i) => (-.5 + .02 * i).toFixed(2)),
        datasets: [{
            label: "Number of games won",
            borderColor: "#cd2a9c",
            backgroundColor: "#cd2a9c",
            data: chart3data,
        }]
    },
    options: {
        maintainAspectRatio: false,
        plugins: {
            legend: { display: false },
        },
        scales: {
            x: {
                title: {
                    display: true,
                    text: "Added target score per difference to leader",
                }
            },
            y: {
                title: {
                    display: true,
                    text: "Games won (out of 100,000)",
                }
            },
        }
    },
})
</script>

When we compare this to the other strategies, simulating a million games, we get results shown below. The advantage is only 2.7% over drawing till 25, but it is an advantage nonetheless! And unlike the expected score strategy, this one is relatively easy to execute.

<div class="chart"><canvas id="chart4"></canvas></div>

<script>
const chart4data = [350759, 311245, 302907, 35089]
new Chart(document.getElementById("chart4"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Till 25 + Delta", "Draw Till 25", "Draw Till Bust"],
        datasets: [{
            label: "Number of games won",
            borderColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            backgroundColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            data: chart4data,
        }]
    },
    options: {
        maintainAspectRatio: false,
        plugins: {
            legend: { display: false },
        },
        scales: {
            x: {
                title: {
                    display: true,
                    text: "Strategy",
                }
            },
            y: {
                title: {
                    display: true,
                    text: "Games won (out of 1,000,000)",
                }
            },
        }
    },
})
</script>

## Interlude: Targeting a Player

I was curious about the effect the action cards actually have on the game, so I simulated games where three opponents would always target one opponent with flip 3 and freeze cards. It turns out this has quite a significant effect. In a game with four players, the player who was targeted won a little over half as many games as the other players.

I think this highlights a big part of the game we haven't discussed yet: the psychology of the other players. Players may give you flip 3 and freeze cards when you attack them, or they'll just take different actions than would be optimal. After all, it's about having fun playing a game, not perfecting a strategy :)

<div class="chart"><canvas id="chart5"></canvas></div>

<script>
const chart5data = [156768, 281270, 280688, 281274]
new Chart(document.getElementById("chart5"), {
    type: "bar",
    data: {
        labels: ["Draw Till 25 (targeted)", "Draw Till 25", "Draw Till 25", "Draw Till 25"],
        datasets: [{
            label: "Number of games won",
            borderColor: ["#cd2a9c", "#d663b4", "#d663b4", "#d663b4"],
            backgroundColor: ["#cd2a9c", "#d663b4", "#d663b4", "#d663b4"],
            data: chart5data,
        }]
    },
    options: {
        maintainAspectRatio: false,
        plugins: {
            legend: { display: false },
        },
        scales: {
            x: {
                title: {
                    display: true,
                    text: "Strategy",
                }
            },
            y: {
                title: {
                    display: true,
                    text: "Games won (out of 1,000,000)",
                }
            },
        }
    },
})
</script>