---
layout: post
title: 最小全域木(Prim)
date: 2018-03-25
category: グラフ
tags: 最小全域木
---

## 説明
最小全域木(全域木のうち、その辺群の重みの総和が最小になる木)を求めるアルゴリズム。既に到達した頂点集合からまだ到達していない頂点集合への辺のうち、コストが最小のものを選んでいくことによって、最小全域木を構成している。

## 計算量
* $O(E \log V)$

## 実装例

* prim($g$):= 連結な重み付きグラフ $g$ の最小全域木を求める。

{% include read.html  code="graph/prim.cpp" %}

## 検証

[AOJ GRL_2_A 最小全域木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-2-a.test.cpp" %}
