---
layout: article
title: About Me
permalink: /me/
technologies:
    regular:
        - python
        - cplusplus
        - bash
        - ubuntu
        - git
        - github
        - html5
        - javascript
        - css3
        - latex
        - markdown
        - numpy
        - vscode
    other:
        - c
        - godot
        - jquery
        - raspberrypi
        - jupyter
        - docker
        - matplotlib
        - tensorflow
        - keras
        - csharp
        - haskell
        - visualstudio
        - scikitlearn
        - jekyll
        - matlab
        - flask
        - mysql
        - rstudio
        - pandas
        - sqlite
        - julia
        - php
        - unity
        - blender
        - opencv
accent_color: "#3f8de0"
front_image: /assets/img/nwerc-2024.jpg
thumbnail: /assets/img/profile-picture_800.jpg
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
    {%- for name in page.technologies.regular -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{ name | escape }}" alt="{{ name | escape }}"></li>
    {%- endfor -%}
</ul>

Stuff I've worked with in the past includes:

<ul class="icon-listing">
    {%- for name in page.technologies.other -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{ name | escape }}" alt="{{ name | escape }}"></li>
    {%- endfor -%}
</ul>

## Timeline

<div class="milestones" style="--accent-color: {{ page.accent_color }};">
    {%- for milestone in site.data.milestones reversed -%}
        {%- assign date_format = "%B %Y" -%}
        {%- if milestone.major -%}
        <div class="milestone milestone-major">
        {%- else -%}
        <div class="milestone">
        {%- endif -%}
            <div class="milestone-text">
                <h2 class="milestone-title">{{ milestone.title | escape }}</h2>
                <p>{{ milestone.description }}</p>
            </div>
            <div class="milestone-meta"><span>{{ milestone.date | date: date_format }}{%- if milestone.end_date -%}&nbsp;&mdash;&nbsp;{{milestone.end_date | date: date_format }}{%- endif -%}</span></div>
            {%- if milestone.major -%}
                <div class="timepoint-major"></div>
            {%- else -%}
                <div class="timepoint-minor"></div>
            {%- endif -%}
        </div>
    {%- endfor -%}
</div>