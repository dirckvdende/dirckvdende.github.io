---
layout: home
---

Hi, I'm Dirck. I'm a Computer Science Master student at Leiden Univerity. On this website you can find some of the projects I've worked on, as well as the occasional blog post. Read more about me [here](/me/).

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