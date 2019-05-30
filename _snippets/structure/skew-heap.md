---
layout: post
title: マージ可能ヒープ(Skew-Heap)
date: 2019-05-30
category: データ構造
---

## 説明
$2$ つのヒープをマージ可能なヒープである。

## 計算量
* top $O(1)$
* pop, push, merge $O(\log N)$

## 実装例
* SkewHeap($g$, $h$, $rev$):= $g$ は作用素と要素をマージする関数、$h$ は作用素同士をマージする関数。$rev$ を true にすると key の降順に pop されるようになる。
* merge($x$, $y$):= 2 つのヒープ $x$ と $y$ をマージしたものを返す。
* push($root$, $key$):= $root$ に $key$ を push する。
* top($root$):= $root$ の先頭の key を返す。
* pop($root$):= $root$ から pop し、pop した key を返す。
* empty($root$):= $root$ が空かどうか判定する。
* add($root$, $lazy$):= $root$ 全体に作用素 $lazy$ を適用する。
* makeheap():= 空ヒープを返す。


{% include read.html  code="structure/skew-heap.cpp" %}
