---
layout: page
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
---

I'm a Computer Science Master student at Leiden Univerity. On this website you can find some of the projects I've worked on, as well as the occasional blog post. I also work on hobby projects on an irregular basis. Some of which you can find below! Both for university and for personal projects I make use of Python or C++. I also make websites sometimes.
<h2 class="center-title">Stuff I use regularly</h2>
<ul class="large-icon-listing">
    {%- for name in page.technologies.regular -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>
<h2 class="center-title">Stuff I have experience with</h2>
<ul class="large-icon-listing">
    {%- for name in page.technologies.other -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escape}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>

<h2 class="center-title">History</h2>

<div class="milestones">
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