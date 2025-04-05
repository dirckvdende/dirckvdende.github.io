---
layout: home
title: Home
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

## About Me

...

...

...

<div>
    {%- for x in site.data.project-links.hello -%}
        <b>{{ x }}</b>
    {%- endfor -%}
</div>

Both for university and in personal projects I make use of Python or C++, in addition to web development. Below are some of the technologies that I use very regularly.
<ul class="icon-listing">
    {%- for name in page.technologies.regular -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escpae}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>
I've listed some of the technologies I've worked with in the past below. These are ordered from most to least familiarity.
<ul class="icon-listing">
    {%- for name in page.technologies.other -%}
        <li><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/{{name | escape}}/{{name | escpae}}-original.svg" title="{{name | escape}}"></li>
    {%- endfor -%}
</ul>

## My Projects

<div>
    {%- for project in site.data.project-links -%}
        <div class="image-card">
            <div class="image-card-image">
                <img src="{{ project.img }}">
            </div>
            <div class="image-card-text">
                <a class="image-card-title" href="{{ project.url }}">{{ project.title }}</a>
                <p>{{ project.description }}</p>
            </div>
        </div>
    {%- endfor -%}
</div>