---
layout: post
title: 最長回文(Manacher)
date: 2018-08-19
category: 文字列
---

## 説明
ある文字列 $S$ が与えられているとする。Manacher では, それぞれの $i$ について文字 $i$ を中心とする最長回文の半径を記録した配列を線形時間で構築するアルゴリズムである。

具体例を以下に示す。例えば $i = 6$ を中心とする最長回文は "aba", つまり $2$ である。

<pre>
abaaababa
121412321
</pre>

## 計算量
* $O(\|S\|)$

## 実装例

{% include read.html code="string/manacher.cpp" %}
