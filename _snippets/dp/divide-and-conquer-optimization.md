---
layout: post
title: Divide-And-Conquer-Optimization 
date: 2019-05-29
category: 動的計画法
---

## 説明
$dp[i][j] = \min_{0 \leq k \lt j}\\{dp[i-1][k]+f(k,j)\\}$

各行について Monotone-Minima

うく

説明を書く

## 計算量
* $O(HW \log W)$

## 実装例
依存ライブラリ [Monotone-Minima](../dp/monotone-minima.html)

* divide_and_conquer_optimization($H$, $W$, $INF$, $f$): dp 配列を返す。$f(i, j)$ は区間 $[i, j)$ のコスト。

{% include read.html  code="dp/divide-and-conquer-optimization.cpp" %}

## 検証
[Codeforces Codeforces Round #438 F - Yet Another Minimization Problem](https://codeforces.com/contest/868/problem/F)
{% include read.html code="dp/verify/codeforces-438-f.cpp" %}
