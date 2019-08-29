---
layout: post
title: 全点対間最短路(Warshall-Floyd)
date: 2018-04-15
category: グラフ
tags: 全点対間最短路
---

## 説明
隣接行列で表されるグラフの全点間最短路を求めるアルゴリズム。負辺があっても動作する。負閉路が存在する場合はそれも検出する(ある頂点 $k$ から $k$ への最短路が負ならば負閉路が存在)。

## 計算量
* $O(V^3)$

## 実装例

* warshall_floyd($g$, $INF$):= 隣接行列 $g$ で表されるグラフの全点間最短路を求める。ここで到達できない要素には $INF$ が格納されている。

{% include read.html  code="graph/warshall-floyd.cpp" %}

## 検証

[AOJ GRL_1_C 全点対間最短経路](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp)
{% include read.html code="graph/verify/aoj-grl-1-c.test.cpp" %}
