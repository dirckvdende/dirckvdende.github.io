---
layout: page
title: My Projects
permalink: /projects/
---

<div>
    {%- for project in site.data.project-links -%}
        <div class="image-card">
            <div class="image-card-image">
                <img src="{{ project.img | relative_url }}">
            </div>
            <div class="image-card-text">
                <a class="image-card-title" href="{{ project.url | relative_url }}">{{ project.title }}</a>
                <p>{{ project.description }}</p>
            </div>
        </div>
    {%- endfor -%}
</div>