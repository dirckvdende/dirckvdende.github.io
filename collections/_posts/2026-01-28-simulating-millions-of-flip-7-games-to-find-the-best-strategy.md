---
layout: post
title: Simulating Millions of Flip 7 Games to Find the Best Strategy
date: 2026-01-28 09:00:00 +0100
tags: Game Strategy Simulation
accent_color: "#cd2a9c"
front_image: /assets/code/flip-7-part-2/flip_7.jpg
thumbnail: /assets/code/flip-7-part-2/flip_7.jpg
head: <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
---

A few months ago, I wrote a blog post about a simple but very fun game called [Flip 7](https://boardgamegeek.com/boardgame/420087/flip-7). In the last post, we discussed some possible strategies and ran experiments on a simplified version of the game. Today, I want to improve on that analysis by truly simulating entire games, including action cards and opponents!

If you'd like to read up on the rules of the game, you can find them on [BoardGameGeek](https://boardgamegeek.com/boardgame/420087/flip-7/files), or you can read the overview in [my last post](/blog/exploring-flip-7-strategies/).

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

## Drawing Until Reaching a Target Score

A simple strategy we discussed last time is drawing cards until you've reached some score that round. Without action cards, the expected score in a single round was highest when targeting a score between 20 and 27.

We'll expand on that strategy by always giving Flip 3 and Freeze cards to the opponent with the highest score. Of course, we take the Second Chance card ourselves if possible. We'll also not stop drawing if we have a Second Chance card (since we'd almost never bust).

I simulated a player with a specific target score playing 100,000 games. Each time, they played against three players with random target scores between 1 and 50. The number of games the player won (per target score) is shown below.

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

Another strategy discussed in the previous post is the following: If the expected score of our hand after a draw is higher than our current score, we draw another card. This strategy keeps track of which cards are still in the draw pile. We'll ignore the effects of Freeze and Flip 3 cards, since they can be quite complicated. The strategy already ensures that we don't pass if we have a Second Chance card.

I simulated a million games of someone using this strategy playing against two players who draw until 25, and one who never passes. Unlike last time, there is quite a big improvement compared to the "draw until 25" strategy!

<div class="chart"><canvas id="chart2"></canvas></div>

<script>
const chart2data = [354983, 306116, 304258, 34643]
new Chart(document.getElementById("chart2"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Until 25", "Draw Until 25", "Draw Until Bust"],
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

The problem with highly effective strategies like this is that they can realistically only be executed by a computer. You'd have to remember all of the cards that are still in the draw pile, determine the score you'd get after drawing each card, then add all of those scores up &mdash; every single turn!

This is a bit difficult, so we'll explore some alternatives, and see how they perform against this "near-perfect" strategy.

## Catching Up with the Leader

A strategy I've seen used in practice quite a lot is to draw more or fewer cards based on the scores of your opponents. If the leader is very far ahead, it may be beneficial to draw more cards to try to catch up. What we'll try next is based on that idea.

Instead of always targeting a score of 25, we'll add some offset based on how far ahead the leading opponent is (or behind, if you're leading). We'll add some fixed amount $\Delta$ to the target score for each point the opponent is ahead. The formula for determining the new target score $T$, given the best opponent score $S_o$ and our score $S$, is

$$
    T = 25 + \Delta \times (S_o - S)
$$

Now the question is: Which value of $\Delta$ works best? Letting a player with differing values of $\Delta$ play against players who simply target a score of 25 gave the results shown in the chart below.

If you look carefully, you can see the peak (i.e., the optimal strategy) is around 0.1. So using a value of 0.1 for $\Delta$ works *slightly* better than simply targeting 25.

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

When we compare this to the other strategies by simulating a million games, we get the results shown below. The advantage is only 2.7% over drawing until 25, but it is an advantage nonetheless! And unlike the "expected score" strategy, this one is relatively easy to execute.

<div class="chart"><canvas id="chart4"></canvas></div>

<script>
const chart4data = [350759, 311245, 302907, 35089]
new Chart(document.getElementById("chart4"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Until 25 + Delta", "Draw Until 25", "Draw Until Bust"],
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

I was curious about the effect the action cards actually have on the game, so I simulated games where three opponents would always target one opponent with Flip 3 and Freeze cards. It turns out this has quite a significant effect. In a game with four players, the player who was targeted won a little over half as many games as the other players.

I think this highlights a big part of the game we haven't discussed yet: the psychology of the other players. Players may give you Flip 3 and Freeze cards when you attack them, or they'll just take different actions than would be optimal. After all, it's about having fun playing a game, not perfecting a strategy :)

<div class="chart"><canvas id="chart5"></canvas></div>

<script>
const chart5data = [156768, 281270, 280688, 281274]
new Chart(document.getElementById("chart5"), {
    type: "bar",
    data: {
        labels: ["Draw Until 25 (targeted)", "Draw Until 25", "Draw Until 25", "Draw Until 25"],
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

## Tuning the Strategy

I've tried many other strategies: counting the number of high cards, estimating the expected score with simpler formulas, etc. None of them seemed to work any better than the "draw until 25" strategy (with the difference to the leader taken into account). That's why we'll now tune this strategy with some extra rules that should be easy to apply.

### Giving the Flip 3 Card to Yourself

If you get a Flip 3 card at the start of the game, it may be beneficial to give it to yourself. The chance of busting at this point is still quite low, and this way you increase your score before someone freezes you!

It turns out this only helps a little bit. The improvement over the original strategy is about 1%. Nevertheless, we'll include it while tuning the strategy further.

<div class="chart"><canvas id="chart6"></canvas></div>

<script>
const chart6data = [276685, 245910, 243638, 233767]
new Chart(document.getElementById("chart6"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Until 25 + Tuned (1)", "Draw Until 25 + Delta", "Draw Until 25"],
        datasets: [{
            label: "Number of games won",
            borderColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            backgroundColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            data: chart6data,
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

### The Endgame

There is also an edge case where you definitely want to draw past your target score: when the game is about the end and you're behind. When another player has more than 200 points (including the current hand), it's pretty certain the game will end soon. The only way you can win now is to keep drawing cards until you're ahead.

It turns out that adding this to the strategy actually makes quite a big difference! It even works better than the "expected score" strategy (of course, that one could be updated to include this strategy as well).

<div class="chart"><canvas id="chart7"></canvas></div>

<script>
const chart7data = [264197, 282998, 231065, 221740]
new Chart(document.getElementById("chart7"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Until 25 + Tuned (2)", "Draw Until 25 + Delta", "Draw Until 25"],
        datasets: [{
            label: "Number of games won",
            borderColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            backgroundColor: ["#cd2a9c", "#d663b4", "#df91c7", "#e4a7d2"],
            data: chart7data,
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

## Conclusion

At this point, we've found a pretty good strategy. Of course, better strategies can probably be found. However, this would also make it more difficult to remember what to do, and the advantage may be small. That's why we'll leave it here for now.

To summarize, a pretty good strategy in Flip 7 is the following:

- While drawing, calculate the value of $25 + 0.1 \times (S_o - S)$, where $S_o$ is the (total) score of the highest opponent, and $S$ is our own score. If your current hand score is higher than this value, stop drawing.
- There is one exception to this rule: When another player's combined score (their already acquired score plus their hand score) is higher than 200, and higher than yours, keep drawing.
- When you receive a Second Chance card and you already have one, give it to the player with the lowest score.
- Give Freeze cards to the player with the highest score.
- Give Flip 3 cards to the player with the highest score, unless you don't have any cards yet. In that case, give it to yourself.

Another big factor that can come into play is how other people play. For example, if one of your opponents always gives Flip 3 cards to the people giving them Flip 3 cards, you may not want to target that player &mdash; even if they're in the lead. On the other hand, some players may not be very good at the game and therefore not worth targeting either. The psychology of your opponents can play a crucial role in your victory! Just remember to have fun every now and then too...

Oh and by the way: There's an [expansion](https://www.youtube.com/watch?v=5aKmiqpM9lE) of Flip 7 planned! It looks like I may have to do some more analysis later.

*Note: All of the code I used to generate the statistics in this post are available on [GitHub](https://github.com/dirckvdende/dirckvdende.github.io/tree/main/assets/code/flip-7-part-2).*