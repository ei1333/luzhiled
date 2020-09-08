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


<blockquote class="twitter-tweet"><p lang="ja" dir="ltr">有名事実なんですけど、Luzhiled&#39;s memoは最新じゃない(理由:うしですら更新できなくなっているため)ので説明文としての価値があるものだと思った方がよさそう</p>&mdash; 年金 レジ (@Luzhiled) <a href="https://twitter.com/Luzhiled/status/1303288370685067265?ref_src=twsrc%5Etfw">September 8, 2020</a></blockquote> <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>

！！！最新はこちら！！！！　[Luzhiled's Library](https://ei1333.github.io/library/)

{% assign mydocs = site.snippets | group_by: 'category' %}
{% for cat in mydocs %}
## {{ cat.name }}
  {% assign items = cat.items | sort: 'title' %}
  {% for item in items %}
* [{{item.title}}]({{ item.url | relative_url }})
  {% endfor %}
{% endfor %}

