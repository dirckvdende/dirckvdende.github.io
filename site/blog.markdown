---
layout: page
title: Blog
permalink: /blog/
---

<div>
    {%- for post in site.posts -%}
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