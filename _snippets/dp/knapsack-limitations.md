---
layout: post
title: 個数制限付きナップサック(Knapsack-Limitations)
date: 2019-08-30
category: 動的計画法
---

## 説明
個数制限付きナップサック問題を解く。

$N$ を荷物の種類数, $W$ をナップサックの容量, $w_i$ を荷物の重さ, $m_i$ を荷物の個数, $v_i$ を荷物の価値とする。

この問題はスライド最大値を用いることで 「dp[重さの和]:= 価値の和の最大値」 を $O(NW)$ で解くことができる(a)。

またDPのkeyとvalueを入れ替えるテクも使えて, 「dp[価値の和]:= 重さの和の最小値」 を $O(N \sum {m_i v_i})$ で解ける。dp[$k$] が $W$ 以下となる最大の $k$ が答え(b)。

これらを解く実装例を、実装例1に示した。

また, がんばると $O(N^2 \max(v_i)^2)$ でも解ける。まず「dp[価値の和]:= 重さの和の最小値」をある程度の大きさ($N \max(v_i)^2$)まで (b) のDPを使って求める。残りの分は, 効率が良い順(価値/重さが大きい順)に貪欲にとってもいいことが示せて, なんかできる(c)。 実装例2に示した。

## 実装例1
$O(NW)$
* knapsack_limitations($w$, $m$, $v$, $W$, $NG$): 荷物のそれぞれの重さ, 個数, 価値がそれぞれ $w, m, v$ で, 重さの和が $W$ 以下のすべてについて価値の和の最大値を返す(a)。その重さに到達できないとき $NG$ が格納される。第 $6$ 引数に less を与えると最小値の場合を解く(b)。 
{% include read.html  code="dp/knapsack-limitations.cpp" %}

## 検証1
[AOJ DPL_1_G 個数制限付きナップザック問題](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G&lang=jp)
{% include read.html code="dp/verify/aoj-dpl-1-g.test.cpp" %}

## 実装例2
$O(N^2 \max(v_i)^2)$
* knapsack_limitations($w$, $m$, $v$, $W$, $NG$): 荷物のそれぞれの重さ, 個数, 価
値がそれぞれ $w, m, v$ で, 重さの和が $W$ 以下のすべてについて価値の和の最大値を返す(c)。 
{% include read.html  code="dp/knapsack-limitations-2.cpp" %}

## 検証2
[AOJ DPL_1_I 個数制限付きナップザック問題II](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_I&lang=jp)
{% include read.html code="dp/verify/aoj-dpl-1-i.test.cpp" %}

