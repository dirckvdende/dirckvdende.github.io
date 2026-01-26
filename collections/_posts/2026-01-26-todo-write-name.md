---
layout: post
# TODO: Update
title: "[TODO WRITE TITLE]"
# TODO: Update
date: 2026-01-26 00:00:00 +0100
tags: Game Strategy Simulation
accent_color: "#cd2a9c"
front_image: /assets/code/exploring-flip-7-strategies/flip_7.jpg
thumbnail: /assets/code/exploring-flip-7-strategies/flip_7.jpg
head: <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
---

<style>
    .chart {
        aspect-ratio: 2 / 1;
        position: relative;
    }

    .chart > canvas {
        position: absolute;
    }
</style>

<script>
    Chart.defaults.font.size = 10
</script>

hufiwehg fweh xwefhx nxf sdlxnj fhix qweio hxfjnk asdxnb fiuhx a kxfe nxuiah xifudsh fxkfj xbenqfhgx ghix fb jkdasx bhjxfashui xf huixwe hxufh xakhxf axg huie fxh uaixef hiujkx

<div class="chart"><canvas id="chart1"></canvas></div>

<script>
const data = [
    59, 49, 77, 89, 170, 223, 341, 535, 747, 1072, 1520, 2108, 2685, 2938, 3188,
    3536, 3651, 3884, 4157, 4294, 4426, 4568, 4675, 4604, 4639, 4579, 4601,
    4524, 4309, 4364, 4164, 4058, 3833, 3741, 3560, 3463, 3235, 3087, 2910,
    2751, 2632, 2376, 2272, 2144, 2065, 1963, 1799, 1736, 1680, 1638,
]
new Chart(document.getElementById("chart1"), {
    type: "line",
    data: {
        labels: data.map((_, index) => index + 1),
        datasets: [{
            label: "Number of games won",
            data,
            borderColor: "#cd2a9c",
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
                    text: "Games won (out of 10,000)",
                }
            },
        }
    },
})
</script>