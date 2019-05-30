---
layout: post
title: 二重辺連結成分分解(Two-Edge-Connected-Components)
date: 2018-04-15
category: グラフ
---

## 説明
二辺連結成分分解とも。二重辺連結成分(2-edge connected component) とは, $1$ 個の辺を取り除いても連結である部分グラフである。つまり橋を含まないような部分グラフなので, 橋を列挙することで二重辺連結成分を列挙できる。

## 計算量
* $O(E + V)$

## 実装例
依存ライブラリ [LowLink](lowlink.html)

* TwoEdgeConnectedComponents($g$):= グラフ $g$ で初期化する。
* build($t$):= 二重辺連結成分分解をする。$t$ には二重辺連結成分ごとに縮約したグラフが格納される(橋のみからなるグラフ)。
* \[$k$\]:= 頂点 $k$ が属する二重辺連結成分の番号を返す。

{% include read.html  code="graph/two-edge-connected-components.cpp" %}

## 検証

[AtCoder Regular Contest 039 - D 旅行会社高橋君](https://beta.atcoder.jp/contests/arc039/tasks/arc039_d)
{% include read.html code="graph/verify/atcoder-arc-039-d.cpp" %}
