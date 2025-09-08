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
---

Hi! My name is Dirck. I recently completed a Master in Computer Science at Leiden University. On this website you can find of the projects I've worked, both for university and outside. I'll also post the occasional blog post here. Both for university and for personal projects I often make use of Python, C++, and TypeScript.

I've also done a Bachelor in Mathetics, mainly focusing on analysis. By Bachelor thesis was about partial differential equations and analog computer. You can read it [here](https://theses.liacs.nl/2706). My master thesis will be made available soon.

## Stuff I use regularly

<ul class="icon-listing">
    {%- for name in page.technologies.regular -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{ name | escape }}" alt="{{ name | escape }}"></li>
    {%- endfor -%}
</ul>

## Stuff I have experience with

<ul class="icon-listing">
    {%- for name in page.technologies.other -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{ name | escape }}" alt="{{ name | escape }}"></li>
    {%- endfor -%}
</ul>

## History & Experience

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