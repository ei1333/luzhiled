---
layout: post
title: ベル数(Bell-Number)
date: 2019-03-31
category: 数学
---
## 説明
ベル数 $B(n,k)$ を求める。

区別できる $n$ 個のボールを区別できない $k$ 個以下の箱に分割する方法の数を与える。

特に $B(n,n)$ は $n$ 個のボールを任意個のグループに分割する方法の数である。

## 計算量
* $O(\min(n, k) \log n)$

## 実装例

依存ライブラリ [Mod-Int](../math/mod-int.html)
[Combination](../math/combination.html)

* bell_number($n$, $k$):= $B(n,k)$ を返す
{% include read.html  code="math/bell-number.cpp" %}

## 検証
[AOJ DPL_5_G ボールと箱 7](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G&lang=jp)

{% include read.html code="math/verify/aoj-dpl-5-g.test.cpp" %}
