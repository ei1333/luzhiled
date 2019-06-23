---
layout: post
title: Convex-Hull-Trick-Add-Monotone
date: 2019-06-24
category: データ構造
---

## 説明
直線 $ax + b$ の追加クエリと, ある点 $x$ での最小値クエリを効率的に処理する。

追加クエリの傾き $a$ が単調の場合に限定。

最小値クエリの $x$ が単調の時はクエリをならし $O(1)$ で処理できる。

## 計算量
* 追加 $O(1)$ (ならし)
* クエリ $O(\log N)$
* 単調なクエリ $O(1)$ (ならし)

## 実装例
テンプレートの isMin に false を与えると最大値クエリを処理する。

* empty():= 直線が空か判定する。
* clear():= 直線を全消しする。
* add($a$, $b$):= 直線 $ax + b$ を追加する。
* query($x$):= $ax + b$ の最小値を求める。
* query_monotone_inc($x$):= $x$ が単調増加する場合の $ax + b$ の最小値を求める。
* query_monotone_dec($x$):= $x$ が単調減少する場合の $ax + b$ の最小値を求める。

{% include read.html  code="structure/convex-hull-trick-add-monotone.cpp" %}

