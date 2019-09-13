---
layout: post
title: 分割数(Partition)
date: 2019-09-12
category: 数学
---

## 説明
$n$ を順序を区別せずに自然数の和に分ける場合の数を $n$ の分割数 $p(n)$ と呼ぶ。

例えば $p(0) = 1$, $p(1) = 1$ ($1$), $p(2) = 2$ ($2, 1+1$), $p(3) = 3$ ($3, 2+1, 1+1+1$)
 
分割数の母関数は次のとおりである。

$ \displaystyle \sum_{n=0}^{\infty} p(n) t^n = \prod_{k=1}^{\infty} \frac {1} {1 - t^k} = \frac {1} {\prod_{k=1}^{\infty} {(1 - t^k)} }$

このままだとあまり役に立たないんですが, オイラーの五角数定理(Euler's pentagonal number theorem) を使うといい感じに計算できる。

オイラーの五角数定理では次を示す。

$ \displaystyle {\prod_{k=1}^{\infty} {(1 - t^k)} = 1 + \sum_{k=1}^{\infty} (-1)^{k} (x^{k(3k+1)/2}+x^{k(3k-1)/2})}$

この逆数を計算できれば良くて, FFTにより $O(n \log n)$ で計算できる。

## 計算量
* $O(n \log n)$

## 実装例
依存ライブラリ [Polynominal-Mod](../math/polynominal-mod.html)

* partition($n$): $[0, n]$ の分割数を返す。

{% include read.html  code="math/partition.cpp" %}

