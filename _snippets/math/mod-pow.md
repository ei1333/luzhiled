---
layout: post
title: べき乗(Mod-Pow)
date: 2019-10-03
category: 数学
tags: べき乗
---

## 説明
ある数のべき乗を求める。

## 計算量
* $O(\log n)$

## 実装例

* power($x$, $n$, $mod$):= $x^n$ を $mod$ で割った余りで返す。

{% include read.html  code="math/mod-pow.cpp" %}

## 検証

[AOJ NTL_1_B べき乗](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp)
{% include read.html code="math/verify/aoj-ntl-1-b.test.cpp" %}
