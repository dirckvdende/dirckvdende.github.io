---
layout: article
title: Blog
permalink: /blog/
---

<div class="horizontal-card-container">
    {%- for post in site.posts -%}
        {%- include blog_card.html post=post -%}
    {%- endfor -%}
</div>