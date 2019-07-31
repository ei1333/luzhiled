---
layout: post
title: 二項係数(Binomial)
date: 2019-07-31
category: 数学
---

## 説明
二項係数 ${}_n \mathrm{C} _k$ を $\frac {k(k-1)\dots (n-k+1)} {k(k-1)\dots 1}$ を利用して求める。

この求め方は $k$ が小さい時に有効。テーブルを得たい場合はパスカルの三角形による [二項係数テーブル](../math/binomial-table.html)、$n$ が小さい場合は [組合せ](../math/combination.html) を用いると良い。

## 計算量
* $O(k)$

## 実装例

* binomial($n$, $k$):= ${}_n \mathrm{C} _k$ を返す。

{% include read.html  code="math/binomial.cpp" %}

