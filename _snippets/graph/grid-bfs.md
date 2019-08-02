---
layout: post
title: グリッド上の幅優先探索(Grid-BFS)
date: 2018-03-25
category: グラフ
---

## 説明
二次元格子上の幅優先探索。

## 計算量
* $O(HW)$

## 実装例

* grid_bfs($s$, $start$, $wall$):= グリッド $s$ 上にある文字 $start$ からすべてのマスへの最短距離を求める。$wall$ には移動できない。到達できるマスには最短距離、できないマスには $-1$ が格納される。

{% include read.html  code="graph/grid-bfs.cpp" %}
