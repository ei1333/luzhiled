---
# You don't need to edit this file, it's empty on purpose.
# Edit theme's home layout instead if you wanna make some changes
# See: https://jekyllrb.com/docs/themes/#overriding-theme-defaults
layout: home
---
<style>
ul li p {
  margin-bottom: 0.25em;
}
</style>

ぽよぽよぷりん

ここにのっているソースコードは自由に使って頂いて構いませんが、バグっている可能性があります。よく使いそうなライブラリほど信頼度が高めです。

{% assign mydocs = site.snippets | group_by: 'category' %}
{% for cat in mydocs %}
## {{ cat.name }}
  {% assign items = cat.items | sort: 'title' %}
  {% for item in items %}
* [{{item.title}}]({{ item.url | relative_url }})
  {% endfor %}
{% endfor %}

