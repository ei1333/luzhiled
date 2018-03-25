---
layout: post
title: 素集合データ構造(Union-Find)
date: 2018-03-25
category: データ構造
---

## 説明
集合を高速に扱うためのデータ構造。集合を合併する操作(unite), ある要素がどの集合に属しているか(find)を問い合わせる操作を行うことが出来る。

## 計算量
* $O(\alpha(n))$

$\alpha$ はアッカーマンの逆関数。

## 実装例

* $\mathrm{unite}(x, y)$: 集合 $x$ と $y$ を併合する. 併合済のとき $\mathrm{false}$, 未併合のとき $\mathrm{true}$ が返される
* $\mathrm{find(k)}$: 要素 $k$ が属する集合を求める
* $\mathrm{size(k)}$: 要素 $k$ が属する集合の要素の数を求める

{% include read.html  code="structure/union-find.cpp" %}

## 検証

[AOJ DSL_1_A 互いに素な集合](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp)
{% include read.html code="structure/verify/aoj-dsl-1-a.cpp" %}
