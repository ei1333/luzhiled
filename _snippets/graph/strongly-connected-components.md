---
layout: post
title: 強連結成分分解(Strongly-Connected-Components)
date: 2018-03-31
category: グラフ
tags: 強連結成分分解
---

## 説明
強連結成分分解をする。

## 計算量
* $O(V + E)$

## 実装例

* StronglyConnectedComponents($g$):= グラフ $g$ で初期化する。
* build($t$):= 強連結成分分解をする。強連結成分の番号はトポロジカル順に昇順にふられる。 $t$ には強連結成分ごとに縮約したグラフが格納される(多重辺が生えるので注意)。
* \[$k$\] := 頂点 $k$ が属する強連結成分の番号を返す。

{% include read.html  code="graph/strongly-connected-components.cpp" %}

## 検証

[AOJ GRL_3_C 強連結成分分解](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp)
{% include read.html code="graph/verify/aoj-grl-3-c.test.cpp" %}
