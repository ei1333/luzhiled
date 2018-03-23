---
layout: post
title: 最小費用流(Primal-Dual)
date: 2018-03-22
author: ei1333
category: グラフ
tags: 最小費用流
---

## 説明
最小費用流を最短路反復で解くアルゴリズム。始点から終点までの重みの最短路を求め、そこに流せる限り流す。これを流したい分だけ流しきるまで繰り返す。最短路の計算は、ポテンシャル $h$ を用いて負辺がないように変換して Dijkstra法 で求める。

## 計算量
* $O(FE \log V)$

## 実装例

{% include read.html  code="graph/primal-dual.cpp" %}
