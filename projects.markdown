---
layout: page
title: Projects
permalink: /projects/
---

<div class="image-card-container wrapped">
    {%- for project in site.data.project-links -%}
        <a class="image-card" href="{{ project.url }}">
            <div class="image-card-image">
                {%- if project.imgset -%}
                    <img
                        srcset="{{ project.imgset }}"
                        src="{{ project.img | relative_url }}"
                        alt="{{ project.title | escape }}">
                {%- else -%}
                    <img src="{{ project.img | relative_url }}" alt="{{ project.title | escape }}">
                {%- endif -%}
            </div>
            <div class="image-card-text">
                <h2 class="image-card-title">{{ project.title }}</h2>
                <p>{{ project.description }}</p>
            </div>
        </a>
    {%- endfor -%}
</div>