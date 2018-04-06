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
