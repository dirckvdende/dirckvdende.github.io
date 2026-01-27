---
layout: post
# TODO: Update
title: "[TODO WRITE TITLE]"
# TODO: Update
date: 2026-01-26 00:00:00 +0100
tags: Game Strategy Simulation
accent_color: "#cd2a9c"
front_image: /assets/code/flip-7-part-2/flip_7.jpg
thumbnail: /assets/code/flip-7-part-2/flip_7.jpg
head: <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
---

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

hufiwehg fweh xwefhx nxf sdlxnj fhix qweio hxfjnk asdxnb fiuhx a kxfe nxuiah xifudsh fxkfj xbenqfhgx ghix fb jkdasx bhjxfashui xf huixwe hxufh xakhxf axg huie fxh uaixef hiujkx

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

<div class="chart"><canvas id="chart2"></canvas></div>

<script>
const chart2data = [354983, 306116, 304258, 34643]
new Chart(document.getElementById("chart2"), {
    type: "bar",
    data: {
        labels: ["Expected Score", "Draw Till Score 25", "Draw Till Score 25", "Draw Till Bust"],
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