---
layout: post
title: 二次元累積和(Cumulative-Sum-2D)
date: 2018-08-30
category: 動的計画法
---

## 説明
$2$ 次元の累積和。前計算として事前に累積和をとることで, 矩形和を $O(1)$ で求めることが出来る。

## 計算量
* 構築 $O(WH)$
* クエリ $O(1)$

## 実装例
* add($x$, $y$, $z$): 要素 $($x$, $y$)$ に値 $z$ を加える
* build(): 累積和を構築する
* query($sx$, $sy$, $gx$, $gy$): 左下 $(sx, sy)$, 右上 $(gx, gy)$ の矩形内の和を求める(半開区間で与えることに注意すること。具体的には列 $gx$ と行 $gy$ は含まない)

{% include read.html  code="dp/cumulative-sum-2d.cpp" %}
