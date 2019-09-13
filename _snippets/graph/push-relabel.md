---
layout: post
title: 最大流(Push-Relabel)
date: 2019-09-14
category: グラフ
tags: 最大流
---

## 説明
最大流を求める。Dinicと同等以上のはやさがある。

## 計算量
* $O(V^2 \sqrt {E})$

## 実装例

* PushRelabel($V$):= 頂点数 $V$ で初期化する。
* add_edge($from$, $to$, $cap$):= 頂点 $from$ から $to$ に容量 $cap$ の辺を張る。
* max_flow($s$, $t$, $f$):= 頂点 $s$ から $t$ に最大流を流し、その流量を返す。

{% include read.html  code="graph/push-relabel.cpp" %}

## 検証

[AOJ GRL_6_A 最大流](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-6-a-3.test.cpp" %}
