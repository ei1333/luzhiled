---
layout: post
title: 一次元累積和(Cumulative-Sum)
date: 2018-08-30
category: 動的計画法
---

## 説明
$1$ 次元の累積和。前計算として事前に累積和をとることで, 区間の和を $O(1)$ で求めることが出来る。

## 計算量
* 構築 $O(N)$
* クエリ $O(1)$

## 実装例
* add($k$, $x$): 要素 $k$ に値 $x$ を加える
* build(): 累積和を構築する
* query($k$): 区間 $[0, k]$ の和を求める(閉区間なので注意)

{% include read.html  code="dp/cumulative-sum.cpp" %}
