---
layout: post
title: 最大流(Ford-Fulkerson)
date: 2018-03-23
category: グラフ
tags: 最大流
---

## 説明
最大流を求める。増加パスをDFSで探して、そこにフローを流していくことを繰り返す。容量が無理数の場合, 有限回の操作で終了しないことがある。

## 計算量
* $O(F E)$

## 実装例

* FordFulkerson($V$):= 頂点数 $V$ で初期化する。
* add_edge($from$, $to$, $cap$):= 頂点 $from$ から $to$ に容量 $cap$ の辺を張る。
* max_flow($s$, $t$, $f$):= 頂点 $s$ から $t$ に最大流を流し、その流量を返す。

{% include read.html  code="graph/ford-fulkerson.cpp" %}

## 検証

[AOJ GRL_6_A 最大流](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-6-a-2.test.cpp" %}
