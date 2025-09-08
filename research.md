---
layout: article
title: Theses
permalink: /research/
---

<div class="horizontal-card-container">
{% for page in site.research %}
    {% include project_card.html page=page %}
{% endfor %}
</div>