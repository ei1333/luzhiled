---
layout: post
title: 拡張ユークリッドの互除法(Extended-Euclidean-Algorithm)
date: 2019-04-05
category: 数学
---

## 説明
$ax+by=\gcd(a,b)$ なる $x,y$ をユークリッドの互除法の過程から計算する．

## 計算量
* $O(\log N)$

## 実装例

* extgcd($a$, $b$, $x$, $y$): $a$ と $b$ の最大公約数を返す。 $x, y$ には $ax+by=\gcd(a, b)$ なる $x, y$ が格納される。

{% include read.html  code="math/extgcd.cpp" %}

## 検証

[AOJ NTL_1_E 拡張ユークリッドの互除法](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp)
{% include read.html code="math/verify/aoj-ntl-1-e.test.cpp" %}
