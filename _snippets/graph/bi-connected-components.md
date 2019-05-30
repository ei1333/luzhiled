---
layout: post
title: 二重頂点連結成分分解(Bi-Connected-Components)
date: 2019-05-31
category: グラフ
---

## 説明
二重連結成分分解とも。二重頂点連結成分とは、$1$ 個の頂点を取り除いても連結である部分グラフである。これは、がんばるとできる。

## 計算量
* $O(E + V)$

## 実装例
依存ライブラリ [LowLink](lowlink.html)

* BiConnectedComponents($g$):= グラフ $g$ で初期化する。
* build():= 二重頂点連結成分分解をする。$bc$ に二重頂点連結成分が格納される。

{% include read.html  code="graph/bi-connected-components.cpp" %}

## 検証

[AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り / Painting Graphs with AtCoDeer](https://atcoder.jp/contests/arc062/tasks/arc062_d)
{% include read.html code="graph/verify/atcoder-arc-062-f.cpp" %}
