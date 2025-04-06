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

I'm a Computer Science Master student at Leiden Univerity. On this website you can find some of the projects I've worked on, as well as the occasional blog post. I also work on hobby projects on an irregular basis. Some of which you can find below! Both for university and for personal projects I make use of Python or C++. I also make websites sometimes. Below are some of the technologies that I use regularly.
<ul class="icon-listing">
    {%- for name in page.technologies.regular -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escpae}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>
I've listed some of the technologies I've worked with in the past below, ordered from most to least familiarity.
<ul class="icon-listing">
    {%- for name in page.technologies.other -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escpae}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>

## History

<div class="milestones">
    {%- for milestone in site.data.milestones reversed -%}
        {%- assign date_format = "%B %-d, %Y" -%}
        {%- if milestone.major -%}
        <div class="milestone milestone-major">
        {%- else -%}
        <div class="milestone">
        {%- endif -%}
            <div class="milestone-text">
                <h2 class="milestone-title">{{ milestone.title | escape }}</h2>
                <p>{{ milestone.description }}</p>
            </div>
            <div class="milestone-meta"><span>{{ milestone.date | date: date_format }}</span></div>
            {%- if milestone.major -%}
                <div class="timepoint-major"></div>
            {%- else -%}
                <div class="timepoint-minor"></div>
            {%- endif -%}
        </div>
    {%- endfor -%}
</div>