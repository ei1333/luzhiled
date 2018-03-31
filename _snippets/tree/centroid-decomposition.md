---
layout: post
title: 木の重心分解(Centroid-Decomposition)
date: 2018-03-31
category: 木
tags: 重心分解
---

## 説明
木の重心分解を行う。

## 計算量
* $O(beet \log N)$

例えば $x$ 頂点を処理する $beet$ の計算量が $O(x)$ であれば, $O(N \log N)$。

## 実装例
* CentroidDecomposition($g$):= グラフ $g$ で初期化する。
* ceontroid_decomp($idx$, $beet$):= $idx$ はどこにしても動作は同じ。$beet$ は, 各重心ごとに呼び出される。ほとんどの重心分解では $beet$ により, その重心を通るパスを DFS などで処理する。
* killed($idx$):= 重心 $idx$ を通るパスが既に計算されていれば($beet(idx)$ が既に呼び出されている) true を返す。
{% include read.html code="tree/centroid-decomposition.cpp" %}

## 検証

[AtCoder「みんなのプロコン 2018」決勝 C 木の問題](https://beta.atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_c)

{% include read.html code="tree/verify/yahoo-procon2018-final-c.cpp" %}
