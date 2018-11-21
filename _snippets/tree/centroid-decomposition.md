---
layout: post
title: 木の重心分解(Centroid-Decomposition)
date: 2018-11-21
category: 木
tags: 重心分解
---

## 説明
木の重心分解を行う。

## 計算量
* $O(N \log N)$

## 実装例
* CentroidDecomposition($g$):= グラフ $g$ で初期化する。
* build($t$):= 重心分解して重心を返す。$t$ には重心と、その重心を取り除いたときのサブグラフの重心たち同士を結んだ木(?)が格納される。またbelongには各頂点についてどの重心のサブグラフに所属するかが格納される。

{% include read.html code="tree/centroid-decomposition.cpp" %}

## 検証

[AtCoder「みんなのプロコン 2018」決勝 C 木の問題](https://beta.atcoder.jp/contests/yahoo-procon2018-final-open/tasks/yahoo_procon2018_final_c)

{% include read.html code="tree/verify/yahoo-procon2018-final-c.cpp" %}
