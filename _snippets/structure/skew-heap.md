---
layout: post
title: マージ可能ヒープ(Skew-Heap)
date: 2018-04-16
category: データ構造
---

## 説明
$2$ つのヒープをマージ可能なヒープである。

## 計算量
* top $O(1)$
* pop, push, merge $O(\log N)$

## 実装例

{% include read.html  code="structure/skew-heap.cpp" %}
