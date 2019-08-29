---
layout: post
title: 二部グラフの最大マッチング(Bipartite-Matching)
date: 2018-03-31
category: グラフ
tags: 二部グラフの最大マッチング
---

## 説明
グラフ $G=(V, E)$ において、 $V$ が $2$ つの部分集合 $X$ と $Y$ に分割され、 $E$ のどの辺も一方の端点は $X$ に、 もう一方の端点は $Y$ に属しているとき、 $G$ を二部グラフという。

グラフ $G=(V, E)$ において、 $M$ が $E$ の部分集合でかつ $M$ のどの $2$ 辺も共通の端点をもたないとき、 $M$ を $G$ のマッチングといい、 辺の本数が最大であるマッチングを最大マッチングという。

ここでは, 二部グラフの最大マッチングを最大流のアルゴリズムを利用して求める。


## 計算量
* $O(V E)$

## 実装例

* BipartiteMatching($n$):= 全体のグラフの頂点数を $n$ で初期化する。
* add_edge($u$, $v$):= 頂点 $u, v$ 間に辺を張る。
* bipartite_matching():= 二部グラフの最大マッチングを返す。

{% include read.html  code="graph/bipartite-matching.cpp" %}

## 検証

[AOJ GRL_7_A 2部マッチング](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-7-a.test.cpp" %}
