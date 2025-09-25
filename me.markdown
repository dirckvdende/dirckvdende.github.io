---
layout: article
title: About Me
permalink: /me/
technologies:
    regular:
        - name: Python
          icon: devicon-python-plain
        - name: C++
          icon: devicon-cplusplus-plain
        - name: Bash
          icon: devicon-bash-plain
        - name: Ubuntu
          icon: devicon-ubuntu-plain
        - name: Git
          icon: devicon-git-plain
        - name: GitHub
          icon: devicon-github-original
        - name: HTML
          icon: devicon-html5-plain
        - name: JavaScript
          icon: devicon-javascript-plain
        - name: TypeScript
          icon: devicon-typescript-plain
        - name: CSS
          icon: devicon-css3-plain
        - name: Sass
          icon: devicon-sass-original
        - name: LaTeX
          icon: devicon-latex-original
        - name: Markdown
          icon: devicon-markdown-original
        - name: Visual Studio Code
          icon: devicon-vscode-plain
    other:
        - name: C
          icon: devicon-c-original
        - name: Java
          icon: devicon-java-plain
        - name: C#
          icon: devicon-csharp-plain
        - name: npm
          icon: devicon-npm-original-wordmark
        - name: NumPy
          icon: devicon-numpy-plain
        - name: Godot
          icon: devicon-godot-plain
        - name: jQuery
          icon: devicon-jquery-plain
        - name: Raspberry Pi
          icon: devicon-raspberrypi-plain
        - name: Jupyter Notebooks
          icon: devicon-jupyter-plain
        - name: Docker
          icon: devicon-docker-plain
        - name: Matplotlib
          icon: devicon-matplotlib-plain
        - name: TensorFlow
          icon: devicon-tensorflow-original
        - name: Keras
          icon: devicon-keras-plain
        - name: Haskell
          icon: devicon-haskell-plain
        - name: Visual Studio
          icon: devicon-visualstudio-plain
        - name: scikit-learn
          icon: devicon-scikitlearn-plain
        - name: Jekyll
          icon: devicon-jekyll-plain
        - name: MATLAB
          icon: devicon-matlab-plain
        - name: Flask
          icon: devicon-flask-original
        - name: MySQL
          icon: devicon-mysql-original
        - name: R
          icon: devicon-r-plain
        - name: RStudio
          icon: devicon-rstudio-plain
        - name: Pandas
          icon: devicon-pandas-plain
        - name: SQLite
          icon: devicon-sqlite-plain
        - name: Julia
          icon: devicon-julia-plain
        - name: PHP
          icon: devicon-php-plain
        - name: Unity
          icon: devicon-unity-plain
        - name: Blender
          icon: devicon-blender-original
        - name: OpenCV
          icon: devicon-opencv-plain
        - name: Apache HTTP Server
          icon: devicon-apache-plain
        - name: Maven
          icon: devicon-maven-plain
        - name: MonoGame
          icon: devicon-monogame-original
        - name: PyPI
          icon: devicon-pypi-plain
accent_color: "#3f8de0"
front_image: /assets/img/nwerc-2024.jpg
thumbnail: /assets/img/profile-picture_800.jpg
head: <link rel="stylesheet" type="text/css" href="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/devicon.min.css" />
---

Hi! I'm Dirck. I'm a recent Computer Science Master graduate from Leiden University. I love solving (and creating) puzzles. For university and my personal projects I often use Python, C++, and TypeScript, though I've worked with much more.

{% if site.data.home_notifications %}
{% for notification in site.data.home_notifications %}
{% include notification_card.html text=notification.text color=notification.color icon=notification.icon %}
{% endfor %}
{% endif %}

## Education

For my master's I followed the "Foundations of Computing" track, which focuses on theoretical Computer Science and is very math-heavy. I also followed some courses on AI and machine learning. My master's thesis is on weighted model counting and quantum computing. Read more about it [here](/research/master-thesis).

I completed two bachelor's degrees at Leiden University in 2023, one in Mathematics and one in Computer Science. I did a joint thesis on partial differential equations and analog computers. Read more about this thesis [here](/research/bachelor-thesis).

## Work experience

During my time at Leiden University, I've been a student assistant for courses for 3.5 years. Below is a list of all of the course I've assisted for:

| Course | Study programme | Semester |
| --- | --- |
| Complex Analysis | Mathematics | Spring 2022 |
| Automata Theory | Computer Science | Fall 2022 |
| Computer Architecture | Computer Science | Fall 2022 |
| Dynamics and Chaos | Mathematics | Spring 2023 |
| Automata Theory | Computer Science | Fall 2023 |
| Compiler Construction | Computer Science | Fall 2023 |
| Program Correctness | Computer Science | Spring 2024 |
| Automata Theory | Computer Science | Fall 2024 |
| Program Correctness | Computer Science | Spring 2025 |
| Algorithms | Computer Science | Spring 2025 |

## Programming Competitions

I've competed in the BAPC and NWERC programming competitions in 2022, 2023, and 2024. In each year my team won the BAPC preliminary round in Leiden. I created a reference document for my team to use between the 2022 and 2023 competitions. You can read more about this document and my participation in programming competitions [here](/projects/competition-reference).

## Stuff I've used

I've listed some of the technologies I use on a regular basis:

<ul class="icon-listing">
    {%- for technology in page.technologies.regular -%}
        <li><i class="{{ technology.icon }}" title="{{ technology.name | escape }}"></i></li>
    {%- endfor -%}
</ul>

Stuff I've worked with in the past includes:

<ul class="icon-listing">
    {%- for technology in page.technologies.other -%}
        <li><i class="{{ technology.icon }}" title="{{ technology.name | escape }}"></i></li>
    {%- endfor -%}
</ul>

## Timeline

{% include timeline.html milestones=site.data.milestones %}