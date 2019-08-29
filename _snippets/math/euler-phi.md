---
layout: post
title: オイラーのφ関数(Euler's-Phi-Function)
date: 2019-04-06
category: 数学
---

## 説明
正の整数 $n$ が与えられたとき, $1$ から $n$ までの自然数のうち $n$ と互いに素なものの個数 $\phi(n)$ を求める。

以下の式で効率的に求めることができる。

$\phi(n)=n\displaystyle\prod_{i=1}^k(1-\dfrac{1}{p_i})$ (ただし $p_i$ は $n$ の素因数)


## 計算量
* $O(\sqrt N)$

## 実装例

* euler_phi($n$): $\phi(n)$ を返す。

{% include read.html  code="math/euler-phi.cpp" %}

## 検証

[AOJ NTL_1_D オイラーのφ関数](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D&lang=jp)
{% include read.html code="math/verify/aoj-ntl-1-d.test.cpp" %}
