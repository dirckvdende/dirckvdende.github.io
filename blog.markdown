---
layout: page
title: Blog
permalink: /blog/
---

<div class="image-card-container wrapped">
    {%- for post in site.posts -%}
        <a class="image-card" href="{{ post.url }}">
            {%- if post.img -%}
                <div class="image-card-image">
                    <img src="{{ post.img }}" alt="{{ post.title | escape }}">
                </div>
            {%- endif -%}
            <div class="image-card-text">
                <p class="image-card-date">{{ post.date | date: "%B %-d, %Y" }}</p>
                <h2 class="image-card-title">{{ post.title | escape }}</h2>
                <p>{{ post.content | strip_html | escape | truncatewords: 70 }}</p>
            </div>
        </a>
    {%- endfor -%}
</div>