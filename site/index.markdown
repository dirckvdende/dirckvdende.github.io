---
layout: home
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

Both for university and in personal projects I make use of Python or C++, in addition to web development. Below are some of the technologies that I use regularly.
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
    {%- for project in site.data.project-links limit:3 -%}
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
<div class="center-link-button">
    <a href="/projects/" class="center-link-button">View all projects</a>
</div>

## Blog

<div>
    {%- for post in site.posts limit: 3 -%}
        <div class="image-card">
            {%- assign date_format = "%B %-d, %Y" -%}
            <div class="image-card-text">
                <a class="image-card-title" href="{{ post.url | relative_url }}">{{ post.title | escape }}</a>
                {%- if site.show_excerpts -%}
                    <p>{{ post.excerpt }}</p>
                {%- endif -%}
            </div>
            <div class="image-card-meta">{{ post.date | date: date_format }}</div>
        </div>
    {%- endfor -%}
</div>
<div class="center-link-button">
    <a href="/blog/" class="center-link-button">View all posts</a>
</div>

## Milestones

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
            <div class="milestone-meta">{{ milestone.date | date: date_format }}</div>
            {%- if milestone.major -%}
                <div class="timepoint-major"></div>
            {%- else -%}
                <div class="timepoint-minor"></div>
            {%- endif -%}
        </div>
    {%- endfor -%}
</div>