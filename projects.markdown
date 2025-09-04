---
layout: listing
title: Projects
permalink: /projects/
---

<div class="card-container">
    {% for project in site.projects %}
        {% assign excerpt = project.excerpt | strip_html %}
        {% include card.html url=project.url title=project.title description=excerpt imgset=project.front_image accent_color=project.accent_color tags=project.tags %}
    {% endfor %}
</div>