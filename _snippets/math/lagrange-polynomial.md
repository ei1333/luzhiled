---
layout: post
title: ラグランジュ補完(Lagrange-Polynomial)
date: 2019-04-05
category: 数学
---

## 説明
$N$ 次多項式 $f(x)$ があって、$f(0), f(1), \cdots, f(N)$ がわかっているとする。このとき任意の値 $t$ に対して $f(t)$ がラグランジュ補完により復元可能。

## 計算量
* $O(N \log mod)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)
[Combination](../math/combination.html)


* lagrange_polynomial($y$, $t$)

{% include read.html  code="math/lagrange-polynomial.cpp" %}
