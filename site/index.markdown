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

<div class="image-card">
    <div class="image-card-image">
        <img src="assets/img/daily-puzzle.png">
    </div>
    <div class="image-card-text">
        <a class="image-card-title" href="https://dirckvdende.github.io/daily-puzzle/">Daily Puzzles</a>
        <p>A daily puzzle web-app that has a different type of puzzle for every day of the week. Puzzles are randomly generated.</p>
    </div>
</div>
<div class="image-card">
    <div class="image-card-image">
        <img src="assets/img/reference-doc.png">
    </div>
    <div class="image-card-text">
        <a class="image-card-title" href="https://github.com/dirckvdende/competition-reference/blob/main/reference.pdf">Programming Competition Reference</a>
        <p>I participated in the BAPC and NWERC programming contests in 2022, 2023, and 2024. In these competitions a document of at most 25 pages can be used as reference material.</p>
    </div>
</div>
<div class="image-card">
    <div class="image-card-image">
        <img src="assets/img/thesis-preview.png">
    </div>
    <div class="image-card-text">
        <a class="image-card-title" href="https://theses.liacs.nl/2706">Bachelor's Thesis on PDEs and Analog Computers</a>
        <p>I finished my bachlor in Computer Science and my bachelor in Mathematics by doing a joint thesis on partial differential equation simulation on analog computers.</p>
    </div>
</div>
