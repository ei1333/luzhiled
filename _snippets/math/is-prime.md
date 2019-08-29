---
layout: post
title: 素数判定(Is-Prime)
date: 2018-11-21
category: 数学
tags: 素数
---

## 説明
素数判定

## 計算量
* $O(\sqrt N)$

## 実装例

* is_prime($x$):= $x$ が素数なら $true$、それ以外なら $false$ を返す。

{% include read.html  code="math/is-prime.cpp" %}

## 検証
[AOJ ALDS_1_1_C 素数](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp)

{% include read.html code="math/verify/aoj-alds-1-1-c.test.cpp" %}

