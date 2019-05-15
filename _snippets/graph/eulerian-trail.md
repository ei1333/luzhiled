---
layout: post
title: オイラー路(Eulerian-Trail)
date: 2019-05-15
category: グラフ
tags: オイラー路
---

## 説明
有向/無向グラフが与えられたときに、グラフの全ての辺をちょうど $1$ 回ずつ通る路を求める。

## 計算量
* $O(E)$

## 実装例

* eulerian-trail($es$, $s$, $directed$):= 辺集合 $es$ 上で、頂点 $s$ から始まるオイラー路を求める。$directed = false$ のとき無向、$true$ のとき有向グラフとして扱う。

{% include read.html  code="graph/eulerian-trail.cpp" %}

