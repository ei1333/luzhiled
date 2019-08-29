---
layout: post
title: 素集合データ構造(Union-Find)
date: 2018-03-25
category: データ構造
---

## 説明
集合を高速に扱うためのデータ構造。集合を合併する操作(unite), ある要素がどの集合に属しているか(find)を問い合わせる操作を行うことが出来る。

## 計算量
* $O(\alpha(n))$

$\alpha$ はアッカーマンの逆関数。

## 実装例

* $\mathrm{unite}(x, y)$: 集合 $x$ と $y$ を併合する. 併合済のとき $\mathrm{false}$, 未併合のとき $\mathrm{true}$ が返される
* $\mathrm{find(k)}$: 要素 $k$ が属する集合を求める
* $\mathrm{size(k)}$: 要素 $k$ が属する集合の要素の数を求める

{% include read.html  code="structure/union-find.cpp" %}

## 検証

[AOJ DSL_1_A 互いに素な集合](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp)
{% include read.html code="structure/verify/aoj-dsl-1-a.test.cpp" %}

## 応用1: 2部グラフの頂点彩色
Union-Find を用いると $2$ 部グラフ判定とその副作用として彩色が可能。頂点を倍長して偶奇に分ける。隣接頂点を同じ色にするときは, $\mathrm{unite}(u, v)$ と $\mathrm{unite}(u+N, v+N)$, 異なる色にするときは $\mathrm{unite}(u+N, v)$ と $\mathrm{unite}(u, v+N)$ をする。

* bipartite_coloring(): 2部グラフの頂点彩色をする。2部グラフであるとき true, そうではないとき false を返す。
* \[$k$\]: 頂点 $k$ の色を返す。

{% include read.html  code="structure/bipartite-graph.cpp" %}

## 応用2: 部分永続Union-Find

$t$ 番目のクエリを処理した時点における頂点 $x$ が含まれる連結成分の根や大きさを求めるクエリを $O(log N)$ で行うことができる。

{% include read.html  code="structure/partially-persistent-union-find.cpp" %}

## 応用2: 完全永続Union-Find
永続配列を使うことで, Union-Find を完全永続させられる。メモリを結構消費するので注意。

依存ライブラリ [Persistent-Array](persistent-array.html)

{% include read.html  code="structure/persistent-union-find.cpp" %}

## 応用3: Undo可能Union-Find

{% include read.html  code="structure/union-find-undo.cpp" %}

## 応用4: 重み付きUnion-Find

{% include read.html  code="structure/weighted-union-find.cpp" %}

[AOJ DSL_1_B 重み付きUnion Find木](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=jp)
{% include read.html code="structure/verify/aoj-dsl-1-b.test.cpp" %}
