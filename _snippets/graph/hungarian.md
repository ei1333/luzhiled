---
layout: post
title: ハンガリアン法(Hungarian)
date: 2018-06-15
category: グラフ
---

## 説明
二部グラフの最小重み最大マッチングを求める。

## 計算量
* $O(N^2 M)$

## 実装例
* hungarian($A$):= 重み行列 $A$ の最小重み最大マッチングを返す。最大重みを求めたいときは重み行列の重みを $-1$ 倍する。行列 $A$ は 1-indexed で $N \le M$ を満たす必要があることに注意すること。

{% include read.html  code="graph/hungarian.cpp" %}

## 検証

[AOJ 1163 Cards](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1163)
{% include read.html code="graph/verify/aoj1163.cpp" %}
