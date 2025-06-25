---
layout: home
---

<div class="profile-container">
    <div class="profile-picture-container">
        <img src="assets/img/profile-picture.jpg">
    </div>
    <div class="profile-name-container">
        <h1>Dirck van den Ende</h1>
    </div>
</div>

<blockquote class="center-quote">Hi, I'm Dirck! I'm a Master Computer Science student at Leiden University. I also work on a lot of projects outside of university. I love solving (and making) difficult puzzles. Occasionally I'll also write a blog about something interesting :)</blockquote>

<div class="vspace-empty"></div>

<h2 class="center-title">Projects</h2>

<div class="image-card-container">
    <a class="image-card-more-button invisible"><span>+</span></a>
    {%- for project in site.data.project-links limit:5 -%}
        <a class="image-card" href="{{ project.url }}">
            <div class="image-card-image">
                <img src="{{ project.img }}">
            </div>
            <div class="image-card-text">
                <h2 class="image-card-title">{{ project.title }}</h2>
                <p>{{ project.description }}</p>
            </div>
        </a>
    {%- endfor -%}
    <a class="image-card-more-button" href="/projects"><span>+</span></a>
</div>

<h2 class="center-title">Blog</h2>

<div class="image-card-container">
    <a class="image-card-more-button invisible"><span>+</span></a>
    {%- for post in site.posts limit:5 -%}
        <a class="image-card" href="{{ post.url }}">
            <div class="image-card-text">
                <p class="image-card-date">{{ post.date | date: "%B %-d, %Y" }}</p>
                <h2 class="image-card-title">{{ post.title | escape }}</h2>
                <p>{{ post.content | strip_html | escape | truncatewords: 70 }}</p>
            </div>
        </a>
    {%- endfor -%}
    <a class="image-card-more-button" href="/blog"><span>+</span></a>
</div>

<h2 class="center-title">Contact Me</h2>

<ul class="large-contact-list">
    {%- for social in site.socials -%}
        <li><a href="{{ social.url | escape }}"><svg class="icon" viewBox="0 0 16 16"><use xlink:href="{{ social.logo | relative_url }}"></use></svg> <span>{{ social.username | escape }}</span></a></li>
    {%- endfor -%}
</ul>

<!-- Hi, I'm Dirck. I'm a Computer Science Master student at Leiden Univerity. On this website you can find some of the projects I've worked on, as well as the occasional blog post. Read more about me [here](/me/).

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
</div> -->