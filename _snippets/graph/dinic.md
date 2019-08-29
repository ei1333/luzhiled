---
layout: post
title: 最大流(Dinic)
date: 2018-03-23
category: グラフ
tags: 最大流
---

## 説明
最大流を求める。最短の増加パスを探して、そこにフローを流していくことを繰り返す。そのような経路がなくなったら残余パスでもう一度それを繰り返す。それでも、流せなくなったら終了する。

## 計算量
* $O(E V^2)$

ただしほとんどの場合、実際の計算量より高速に動作する。

## 実装例

* Dinic($V$):= 頂点数 $V$ で初期化する。
* add_edge($from$, $to$, $cap$):= 頂点 $from$ から $to$ に容量 $cap$ の辺を張る。
* max_flow($s$, $t$, $f$):= 頂点 $s$ から $t$ に最大流を流し、その流量を返す。

{% include read.html  code="graph/dinic.cpp" %}

## 検証

[AOJ GRL_6_A 最大流](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-6-a.test.cpp" %}
