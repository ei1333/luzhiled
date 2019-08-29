---
layout: post
title: 木の直径(Tree-Diameter)
date: 2018-03-31
category: 木
tags: 直径
---

## 説明
非負の重み付き無向木の直径を求める。適当な頂点 $s$ から最も遠い頂点 $u$ を求める。次に $u$ から最も遠い頂点 $v$ を求める。このとき、($u$, $v$) が最遠頂点対であり、すなわち木の直径である。

## 計算量
* $O(N)$

## 実装例
* tree_diameter($g$):= 重み付き無向木 $g$ の直径を求める。

{% include read.html code="tree/tree-diameter.cpp" %}

## 検証

[AOJ GRL_5_A 木の直径](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A&lang=jp)
{% include read.html code="tree/verify/aoj-grl-5-a.test.cpp" %}
