---
layout: post
title: 最小費用流(Primal-Dual)
date: 2018-03-23
category: グラフ
tags: 最小費用流
---

## 説明
最小費用流を最短路反復で解くアルゴリズム。始点から終点までの重みの最短路を求め、そこに流せる限り流す。これを流したい分だけ流しきるまで繰り返す。最短路の計算は、ポテンシャル $h$ を用いて負辺がないように変換して Dijkstra法 で求める。

## 計算量
* $O(FE \log V)$

## 実装例

* PrimalDual($V$):= 頂点数 $V$ で初期化する。
* add_edge($from$, $to$, $cap$, $cost$):= 頂点 $from$ から $to$ に容量 $cap$, コスト $cost$ の辺を張る。
* min_cost_flow($s$, $t$, $f$):= 頂点 $s$ から $t$ に流量 $f$ の最小費用流を流す。流せた場合はそのコスト, 流せない場合は $-1$ を返す。

{% include read.html  code="graph/primal-dual.cpp" %}

## 検証

[AOJ GRL_6_B 最小費用流](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B&lang=jp)
{% include read.html code="graph/verify/aoj-grl-6-b.test.cpp" %}
