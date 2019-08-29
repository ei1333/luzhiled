---
layout: post
title: 分割数テーブル(Partition-Table)
date: 2019-04-15
category: 数学
---

## 説明
分割数 $P(n, k)$ は整数 $n$ をちょうど $k$ 個の非負整数の和で表す方法の数を与える。順序が異なるものは同一視する。

## 計算量
* $O(nk)$

## 実装例

* get_partition($n$, $k$):= 各 $i \leq n, j \leq k$ に対し分割数 $P(n, k)$ を求め、それを返す。

{% include read.html  code="math/partition-table.cpp" %}

## 検証
[AOJ DPL_5_J ボールと箱 10](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_J&lang=jp)

{% include read.html code="math/verify/aoj-dpl-5-j.test.cpp" %}

