---
layout: post
title: 行列演算(Matrix)
date: 2018-08-30
category: 数学
tags: 行列
---

## 説明
行列を扱うためのライブラリ。

## 計算量
* 和, 差: $O(N^2)$
* 積: $O(N^3)$
* 行列累乗: $O(N^3 \log k)$
* 行列式(determinant): $O(N^3)$

## 実装例

{% include read.html  code="math/matrix.cpp" %}
