---
layout: post
title: スライド区間の昇順k個の和(Priority-Sum-Structure)
date: 2019-06-24
category: データ構造
---

## 説明
スライドする区間の昇順(降順) $k$ 個の総和を効率良く求めるデータ構造。

priority_queue を 2 つ持てばできる。

要素の削除がある場合は priority_queue を multiset にして直接削除しても良いが, 削除用の priority_queue を用意して削除を遅延させると定数倍が軽い実装になる。

## 計算量
* query $O(1)$ 
* insert, erase $O(\log n)$ (ならし)
* set_k $((それ以前の $k$ との差) \log n)$

## 実装例

* $\mathrm{MinimumSum}(k)$: 昇順 $k$ 個に指定
* $\mathrm{MaximumSum}(k)$: 降順 $k$ 個に指定  
* $\mathrm{insert}(x)$: 要素 $x$ を追加する
* $\mathrm{erase}(x)$: 要素 $x$ を削除する
* $\mathrm{query}()$: 上位 $k$ 個の和(要素数が $k$ に満たないとき, 要素すべての和) を返す
* $\mathrm{set\\_k}()$: $k$ を指定しなおす
* $\mathrm{get\\_k}()$: $k$ を返す
* $\mathrm{size}()$: 全体の要素数を返す

{% include read.html  code="structure/priority-sum-structure.cpp" %}

## 検証

[AtCoder Grand Contest 034 C - Tests](https://atcoder.jp/contests/agc034/tasks/agc034_c)
{% include read.html  code="structure/verify/atcoder-agc-034-c.cpp" %}
