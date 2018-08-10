---
layout: post
title: スパーステーブル(Sparse-Table)
date: 2018-04-16
category: データ構造
---

## 説明
更新がない場合の区間の最小値を高速に求める。

## 計算量
* 構築 $O(N \log N)$
* クエリ $O(1)$

## 実装例

* SparseTable($v$): 配列 $v$ で初期化する。
* rmq($l$, $r$): 区間 $[l, r)$ の最小値を返す。

{% include read.html  code="structure/sparse-table.cpp" %}

## 検証

[SPOJ RMQSQ - Range Minimum Query](http://www.spoj.com/problems/RMQSQ/)
{% include read.html code="structure/verify/spoj-rmqsq.cpp" %}
