---
layout: post
title: スライド区間の昇順k個の和
date: 2018-08-19
category: データ構造
---

## 説明
スライドする区間の昇順(降順) $k$ 個の総和を効率良く求めるデータ構造。

## 計算量
* クエリ $O(\log N)$

## 実装例

* $\mathrm{PrioritySumStructure}(k, order = \mathrm{INCREASE})$: 昇順(降順) $k$ 個に指定
* $\mathrm{add\\_element}(k, x)$: $k$ 番目の要素 $x$ を追加する
* $\mathrm{delete\\_element}(k)$: $k$ 番目の要素を削除する
* $\mathrm{get\\_sum}()$: 昇順 $k$ 個の和を返す
* $\mathrm{increment\\_size}()$: $k$ を $1$ 増やす
* $\mathrm{decrement\\_size}()$: $k$ を $1$ 減らす


{% include read.html  code="structure/priority-sum-structure.cpp" %}
