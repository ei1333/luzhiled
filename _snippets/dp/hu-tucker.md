---
layout: post
title: 最適二分探索木(Hu-Tucker)
date: 2019-05-30
category: 動的計画法
---

## 説明
長さ $N$ の数列 $w_i$ がある。

$\displaystyle \sum_{i=1}^{N} w_i \times depth(i)$ が最小となる二分探索木($N$ 個の葉を持つ)を最適二分探索木と呼ぶ。


## 計算量
* $O(N \log N)$

## 実装例
{% include read.html  code="dp/hu-tucker.cpp" %}

## 検証

[AtCoder Typical Contest 002 C - 最適二分探索木](https://atcoder.jp/contests/atc002/tasks/atc002_c)
{% include read.html code="dp/verify/atcoder-atc002-c.cpp" %}

