---
layout: post
title: 平衡二分探索木(RBST)
date: 2018-08-07
category: データ構造
---

## 説明
RBST(Randomized Binary Search Tree)は平衡二分探索木の一種。ランダムなノードを根にして期待値的に木の高さを $O(\log N)$ に抑える。

## 計算量
* 構築 $O(N)$
* クエリ $O(\log N)$

## 実装例

{% include read.html  code="structure/randomized-binary-search-tree.cpp" %}

## 検証
