---
layout: post
title: Li-Chao-Tree
date: 2018-09-10
category: データ構造
---

## 説明
直線 $ax + b$ の追加クエリと, ある点 $x$ での最小値クエリを効率的に処理する。

## 計算量
* クエリ $O(\log N)$

## 実装例
* update($a$, $b$):= 直線 $ax + b$ を追加する。
* query($k$):= $x=k$ での $ax + b$ の最小値を求める。

{% include read.html  code="structure/li-chao-tree.cpp" %}

