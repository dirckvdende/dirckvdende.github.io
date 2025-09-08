---
layout: article
title: Projects
permalink: /projects/
---

<div class="horizontal-card-container">
    {% for project in site.projects %}
        {% include project_card.html url=project.url page=project %}
    {% endfor %}
</div>