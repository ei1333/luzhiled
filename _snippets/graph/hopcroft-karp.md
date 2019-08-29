---
layout: post
title: 二部グラフの最大マッチング(Hopcroft-Karp)
date: 2018-03-31
category: グラフ
tags: 二部グラフの最大マッチング
---

## 説明
二部グラフの最大マッチングを求める。

## 計算量
* $O(E \sqrt V)$

## 実装例

* HopcroftKarp($n$, $m$):= 一方の頂点数を $n$, もう一方の頂点数を $m$ で初期化する。
* add_edge($u$, $v$):= 頂点 $u, v$ 間に辺を張る。
* bipartite_matching():= 二部グラフの最大マッチングを返す。

{% include read.html  code="graph/hopcroft-karp.cpp" %}

## 検証

[AOJ GRL_7_A 2部マッチング](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-7-a-2.test.cpp" %}
