---
layout: post
title: 最小全域木(Kruskal)
date: 2018-03-25
category: グラフ
tags: 最小全域木
---

## 説明
最小全域木(全域木のうち、その辺群の重みの総和が最小になる木)を求めるアルゴリズム。Union-Findを用いて辺集合にある辺を加えて閉路を作らないか判定しながら、辺を重みが小さい順に走査する。

## 計算量
* $O(E \log V)$

## 実装例

依存ライブラリ [Union-Find](../structure/union-find.html)

* kruskal($edges$, $V$):= $V$ 頂点の重み付き辺集合 $edges$ からなる連結グラフの最小全域木を求める。

{% include read.html  code="graph/kruskal.cpp" %}

## 検証

[AOJ GRL_2_A 最小全域木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-2-a-2.test.cpp" %}
