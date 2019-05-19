---
layout: post
title: 最大クリーク(Maximum-Clique)
date: 2019-05-14
category: グラフ
---

## 説明
グラフの最大クリークを求める。一般グラフに対する最大クリークを求める問題はNP困難である。

補グラフに対する最大独立集合問題と等価である。


## 計算量
* $O(2^{\sqrt {2M}} N)$

## 実装例
* maximum_clique($g$, $f$):= 隣接行列 $g$ で表されるグラフのクリークを全列挙する。$f$ がクリークごとに呼び出され, そのとき渡されるvectorにはそのクリークを構成する頂点が格納されている。最終的に $f$ の戻り値のmaxが返される(verifyコード参照)。

{% include read.html  code="graph/maximum-clique.cpp" %}

## 検証
[AtCoder Beginner Contest 002 D - 派閥](https://atcoder.jp/contests/abc002/tasks/abc002_4)
{% include read.html code="graph/verify/atcoder-abc-002-d.cpp" %}

[AOJ 2306 Rabbit Party](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306)
{% include read.html code="graph/verify/aoj-2306.cpp" %}

## 参考
[指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)
