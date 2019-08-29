---
layout: post
title: 素数テーブル(Prime-Table)
date: 2018-04-06
category: 数学
tags: 素数
---

## 説明
素数テーブルを求める。

## 計算量
* $O(N \log \log N)$

## 実装例

* prime_table($n$):= $n$ 以下の素数テーブルを返す。$i$ 番目の要素が $true$ のとき $i$ が素数であることを表す。

{% include read.html  code="math/prime-table.cpp" %}

## 検証
[AOJ ALDS_1_1_C 素数](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=jp)

{% include read.html code="math/verify/aoj-alds-1-1-c-2.test.cpp" %}

