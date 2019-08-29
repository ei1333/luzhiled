---
layout: post
title: 第2種スターリング数(Stirling-Number-Of-The-Second-Kind)
date: 2019-04-08
category: 数学
---

## 説明
第2種スターリング数 $\\{ {n \atop k} \\}$ を求める。

区別できる $n$ 個のボールを区別できない $k$ 個の箱に分割する方法の数を与える。

計算方法は包除原理の考え方に基づく。$k$ 個の箱のうち空箱があったら違反。違反する個数で包除する。具体的には $k$ 個の箱から $k-i$ 個選んだとして、それらの箱にボールを入れない方法の数 $({k \atop i})i^{n}$ を足し引きする。

$\\{ {n \atop k} \\} = { \frac {1}{k!} }  \sum_{i=0}^{k} {(-1)^{k-i} ({k \atop i})i^{n} }$

## 計算量
* $O(K \log N)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)
[Combination](../math/combination.html)


* stirling_number_second($n$):= $\\{ \textstyle {n \atop k} \\}$ を返す

{% include read.html  code="math/stirling-number-second.cpp" %}

## 検証
[AOJ DPL_5_I ボールと箱 9](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_I&lang=jp)

{% include read.html code="math/verify/aoj-dpl-5-i.test.cpp" %}
