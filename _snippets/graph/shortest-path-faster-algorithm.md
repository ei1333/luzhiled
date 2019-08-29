---
layout: post
title: 単一始点最短路(SPFA)
date: 2018-03-23
category: グラフ
tags: 単一始点最短路
---

## 説明
単一始点全点間最短路を求めるアルゴリズム。単一始点全点間最短路を求めるアルゴリズム。負辺があっても動作する。また負閉路も検出する。

## 計算量
* $O(VE)$

実用上はBellman-Fordよりも高速に動作する。

## 実装例

* shortest_path_faster_algorithm($g$, $s$):= 重み付きグラフ $g$ 上で、頂点 $s$ から全点間の最短コストを求める。到達できないとき, 型の最大値が格納される。負閉路を検出した時空列を返す。

{% include read.html  code="graph/shortest-path-faster-algorithm.cpp" %}

## 検証

[AOJ gRL_1_B 単一始点最短経路（負の重みをもつ辺を含む](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp)
{% include read.html code="graph/verify/aoj-grl-1-b-2.test.cpp" %}
