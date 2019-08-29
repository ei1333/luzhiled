---
layout: post
title: 最小全域有向木(Chu-Liu/Edmond)
date: 2018-03-25
category: グラフ
tags: 最小全域有向木
---

## 説明
頂点 $r$ を根とする最小全域有向木を求めるアルゴリズム。頂点 $r$ から全ての頂点への経路が存在する木のうち最小コストのものを求める。

基本的には各頂点に入る辺のうち最小コストの辺を選ぶ。これらの辺からなるグラフが木ならそれが解。それ以外なら有向閉路が含まれているので閉路を縮約して適切に処理して, 閉路がなくなるまで再帰的に呼び出すことを繰り返す。

## 計算量
* $O(E \log V)$

## 実装例
依存ライブラリ [Skew-Heap](../structure/skew-heap.html)

* MinimumSpanningTreeArborescence($es$, $V$):= 頂点数 $V$ 重み付き辺集合 $es$ のグラフで初期化する。
* build($start)$:= 頂点 $start$ を根とする最小全域有向木のコストを返す。全域有向木が存在しない時 $-1$ を返す。

{% include read.html  code="graph/chu-liu-edmond.cpp" %}

## 検証

[AOJ GRL_2_A 最小全域有向木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B&lang=jp)
{% include read.html code="graph/verify/aoj-grl-2-b.test.cpp" %}
