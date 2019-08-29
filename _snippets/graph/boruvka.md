---
layout: post
title: 最小全域木(Borůvka)
date: 2018-12-28
category: グラフ
tags: 最小全域木
---

## 説明
最小全域木(全域木のうち、その辺群の重みの総和が最小になる木)を求めるアルゴリズム。

それぞれの連結成分について、他の連結成分を結ぶ重みが最小の辺を求めて縮約を繰り返すことにより最小全域木を求める。繰り返し回数は $O(\log V)$ 回なので、普通の最小全域木であれば $O(E \log V)$ で求めることができる。

特殊な重みの場合でも解けることが多いのが強みである。

## 計算量
* $O(E \log V)$

## 実装例

依存ライブラリ [Union-Find](../structure/union-find.html)

* boruvka($N$, $f$):= $N$ 頂点のグラフについて、最小全域木を求める。$f$ は、第一引数が連結成分の個数、第二引数がそれぞれの頂点が所属する連結成分の番号が渡されて、それぞれの連結成分について他の連結成分を結ぶ重みが最小の辺を返す関数である。

{% include read.html  code="graph/boruvka.cpp" %}

## 検証

[AOJ GRL_2_A 最小全域木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp)
{% include read.html code="graph/verify/aoj-grl-2-a-3.test.cpp" %}
