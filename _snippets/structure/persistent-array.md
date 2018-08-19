---
layout: post
title: 永続配列(Persistent-Array)
date: 2018-08-19
category: データ構造
---

## 説明
$N$ 分木による永続配列。

## 計算量
$O(\log_{\mathrm{LOG}} N)$

## 実装例
* PersistentArray< T, LOG >(): LOG 分木の型 T の永続配列を宣言する
* get($k$): 現在の配列の $k$ 番目の要素を返す
* mutable_get($k$): 現在の配列の $k$ 番目の要素へのポインタを返す
* build($v$): $v$ をもとに永続配列を構築する

{% include read.html  code="structure/persistent-array.cpp" %}


