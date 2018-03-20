---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: home
---

ぽよぽよぷりん

{% assign mydocs = site.snippets | group_by: 'category' %}
{% for cat in mydocs %}
## {{ cat.name | capitalize }}
  {% assign items = cat.items | sort: 'order' %}
  {% for item in items %}
  * [{{item.title}}]({{ item.url | relative_url }})
  {% endfor %}
{% endfor %}

