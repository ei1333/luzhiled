---
layout: post
title: 最小共通祖先(Doubling-Lowest-Common-Ancestor)
date: 2018-04-15
category: 木
tags: 最小共通祖先
---

## 説明
ダブリングによるLCA。

頂点 $u, v$ のLCAを求める。ここで $d_i$ を頂点 $i$ の深さとし, $d_u \le d_v$ を仮定する($d_u \gt d_v$ のときは swap すればよい)。まず $d_v$ を $d_v - d_u$ 個だけ親に遡らせて深さを合わせる。ここで $d_v$ が $d_u$ と一致したらそれが LCA。それ以外のときは, 上位bit から $u, v$ 双方の $2^k$ 先の親が異なれば共に遡ることを繰り返して, 双方の親ではない直前の頂点を求める。するとその親がLCAとなる。

## 計算量
* 構築 $O(V \log V)$
* クエリ $O(\log V)$

## 実装例
* DoublingLowestCommonAncestor($g$):= 木 $g$ で初期化する。
* build():= 構築する。
* query($u$, $v$):= 頂点 $u$ と $v$ の最小共通祖先を返す。

{% include read.html code="tree/doubling-lowest-common-ancestor.cpp" %}

## 検証

[AOJ GRL_5_C LCA: Lowest Common Ancestor](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp)
{% include read.html code="tree/verify/aoj-grl-5-c.test.cpp" %}
