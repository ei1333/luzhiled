---
layout: post
title: ラグランジュ補間(Lagrange-Polynomial)
date: 2019-04-05
category: 数学
---

## 説明
$N$ 次多項式 $f(x)$ があって、$f(0), f(1), \cdots, f(N)$ がわかっているとする。このとき任意の値 $t$ に対して $f(t)$ がラグランジュ補完により復元可能。

## 計算量
* $O(N + \log mod)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)
[Combination](../math/combination.html)


* lagrange_polynomial($y$, $t$)

{% include read.html  code="math/lagrange-polynomial.cpp" %}

## 検証
[AtCoder ARC_033_D - 見たことのない多項式](https://atcoder.jp/contests/arc033/tasks/arc033_4)

{% include read.html code="math/verify/atcoder-arc-033-d.cpp" %}
