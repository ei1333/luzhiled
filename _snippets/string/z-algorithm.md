---
layout: post
title: 最長共通接頭辞(Z-Algorithm)
date: 2018-08-19
category: 文字列
---

## 説明
ある文字列 $S$ が与えられているとする。Z-Algorithm では, それぞれの $i$ について $S$ と $S[i,|S|]$ の最長共通接頭辞の長さを記録した配列を線形時間で構築するアルゴリズムである。

具体例を以下に示す。例えば $i = 5$ のときの最長共通接頭辞は "aaa", つまり $3$ 文字である。

<pre>
aaabaaaab
921034210
</pre>

## 計算量
* $O(\|S\|)$

## 実装例

{% include read.html code="string/z-algorithm.cpp" %}
