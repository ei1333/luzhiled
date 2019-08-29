---
layout: post
title: BIT(Binary-Indexed-Tree)
date: 2018-04-15
category: データ構造
---

## 説明
Fenwick Tree とも呼ばれる。数列に対し, ある要素に値を加える操作と, 区間和を求める操作をそれぞれ対数時間で行うことが出来るデータ構造。セグメント木や平衡二分探索木の機能を制限したものであるが, 実装が非常に単純で定数倍も軽いなどの利点がある。

## 計算量
* クエリ $O(\log N)$

## 実装例

* BinaryIndexedTree($sz$): 長さ $sz$ で初期化する。
* sum($k$): 区間 $[0,k]$ の合計を求める(閉区間なので注意)。
* add($k$, $x$): 要素 $k$ に値 $x$ を加える。

{% include read.html  code="structure/binary-indexed-tree.cpp" %}

## 検証

[AOJ DSL_2_B Range Sum Query](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp)
{% include read.html code="structure/verify/aoj-dsl-2-b.test.cpp" %}
