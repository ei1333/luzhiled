---
layout: post
title: 単一始点最短路(Dijkstra)
date: 2018-03-23
category: グラフ
tags: 単一始点最短路
---

## 説明
負辺のない単一始点全点間最短路を求めるアルゴリズム。負辺が無いと仮定すると、各地点でもっとも近いところから距離が確定していく。距離順でソートされたヒープを用いると、効率よく距離を確定していくことができる。


## 計算量
* $O(E \log V)$

## 実装例

* dijkstra($g$, $s$):= 重み付きグラフ $g$ 上で、頂点 $s$ から全点間の最短コストを求める。到達できないとき, 型の最大値が格納される。

{% include read.html  code="graph/dijkstra.cpp" %}

## 検証

[AOJ GRL_1_A 単一始点最短経路](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-1-a.test.cpp" %}
