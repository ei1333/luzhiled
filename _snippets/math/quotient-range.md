---
layout: post
title: 商列挙(Quotient-Range)
date: 2019-06-30
category: 数学
---

## 説明
毎回困るので

自然数 $N$ が与えられる。このとき商 ($\lfloor \frac N i \rfloor$) ($1 \leq i \leq N$) の値の種類数は $O(\sqrt N)$ 個で抑えられる。

特に $\lfloor \frac N i \rfloor = k$ となる最左の $i$ を $l$, 最右の $i$ を $r$ とする。このとき $[l, r]$ で $\frac N i$ の余りを並べると等差数列になっている。

## 計算量
* $O(\sqrt N)$

## 実装例

* quotient_range($N$):= 戻り値の各要素を \{\{$x$,$y$\},$z$\} とする。$x \leq i \leq y$ を満たす整数の商($\lfloor \frac N i \rfloor$) が $z$ であることを意味する。$x$ の昇順で返す。

{% include read.html  code="math/quotient-range.cpp" %}

## 検証
[AtCoder Beginner Contest 132 F - Small Products](https://atcoder.jp/contests/abc132/tasks/abc132_f)
{% include read.html code="math/verify/atcoder-abc-132-f.cpp" %}

