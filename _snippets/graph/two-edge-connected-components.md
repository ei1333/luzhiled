---
layout: post
title: 二辺連結成分分解(Two-Edge-Connected-Components)
date: 2018-04-15
category: グラフ
---

## 説明
二辺連結成分(2-edge connected component) とは, $1$ 個の辺を取り除いても連結である部分グラフである。つまり橋を含まないような部分グラフなので, 橋を列挙することで二辺連結成分を列挙できる。

## 計算量
* $O(V)$

## 実装例
依存ライブラリ [LowLink](lowlink.html)

* TwoEdgeConnectedComponents($g$):= グラフ $g$ で初期化する。
* build($t$):= 二辺連結成分をする。$t$ には二辺連結成分ごとに縮約したグラフが格納される(橋のみからなるグラフ)。
* \[$k$\]:= 頂点 $k$ が属する二辺連結成分の番号を返す。


{% include read.html  code="graph/two-edge-connected-components.cpp" %}

## 検証

[AtCoder ARC_039_D 旅行会社高橋君](https://beta.atcoder.jp/contests/arc039/tasks/arc039_d)
{% include read.html code="graph/verify/atcoder-arc-039-d.cpp" %}
