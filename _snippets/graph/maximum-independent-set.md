---
layout: post
title: 最大独立集合(Maximum-Independent-Set)
date: 2018-06-15
category: グラフ
---

## 説明
グラフの最大独立集合を求める。一般グラフに対する最大独立集合を求める問題はNP困難である。

補グラフに対する最大クリーク問題と等価である。

乱択でもつよい　よわかったらほかの強い人のライブラリを使うべき

## 計算量
うく

## 実装例
* maximum_independent_set($g$, $trial=1000000$):= 隣接行列 $g$ で表されるグラフの最大独立集合を求める。

{% include read.html  code="graph/maximum-independent-set.cpp" %}

## 検証

[AtCoder CODE THANKS FESTIVAL 2017 G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g)
{% include read.html code="graph/verify/atcoder-code-thanks-festival-2017-g.cpp" %}
