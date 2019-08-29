---
layout: post
title: 素因数分解(Prime-Factor)
date: 2018-04-06
category: 数学
tags: 素因数分解
---

## 説明
素因数分解を行う。

## 計算量
* $O(\sqrt N)$

## 実装例

* prime_factor($n$):= 自然数 $n$ を素因数分解した結果を返す。

{% include read.html  code="math/prime-factor.cpp" %}

## 検証

[AOJ NTL_1_A 素因数分解](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=jp)
{% include read.html code="math/verify/aoj-ntl-1-a.test.cpp" %}
