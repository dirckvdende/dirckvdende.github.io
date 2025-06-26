---
layout: home
---

<div class="profile-container">
    <div class="profile-picture-container">
        <img
            srcset="assets/img/profile-picture_200.jpg, assets/img/profile-picture_400.jpg 2x, assets/img/profile-picture_800.jpg 4x"
            src="assets/img/profile-picture_800.jpg"
            alt="Profile picture">
    </div>
    <div class="profile-name-container">
        <h1>Dirck van den Ende</h1>
    </div>
</div>

<blockquote class="center-quote">Hi, I'm Dirck! I'm a Computer Science Master student at Leiden University. I have a bachelor in Mathematics and a bachelor in Computer Science. I also work on a lot of projects outside of university. I love solving (and making) difficult puzzles. I occasially write blogs here :) <a href="/me">Read more about me</a></blockquote>

<div class="vspace-empty"></div>

<h2 class="center-title">Projects</h2>

<div class="image-card-container">
    <a class="image-card-more-button invisible"><span>+</span></a>
    {%- for project in site.data.project-links limit:5 -%}
        <a class="image-card" href="{{ project.url }}">
            <div class="image-card-image">
                {%- if project.imgset -%}
                    <img
                        srcset="{{ project.imgset }}"
                        src="{{ project.img }}"
                        alt="{{ project.title | escape }}">
                {%- else -%}
                    <img src="{{ project.img }}" alt="{{ project.title | escape }}">
                {%- endif -%}
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

<h2 class="center-title">Find Me Here</h2>

<ul class="large-contact-list">
    {%- for social in site.socials -%}
        <li><a href="{{ social.url | escape }}"><svg class="icon" viewBox="0 0 16 16"><use xlink:href="{{ social.logo | relative_url }}"></use></svg> <span>{{ social.username | escape }}</span></a></li>
    {%- endfor -%}
</ul>