---
layout: post
title: HL分解(Heavy-Light-Decomposition)
date: 2018-09-17
category: 木
tags: HL分解
---

## 説明
木をHL分解する。

TODO: 説明

## 計算量
* 構築 $O(V)$
* クエリ $O(\log V)$

## 実装例
* HeavyLightDecomposition($g$):= 木 $g$ で初期化する。
* build():= 構築する。
* query($u$, $v$, $ti$, $q$, $f$, $edge$):= 頂点 $u$ と $v$ を通るパスに対する取得クエリを処理する。$ti$ は単位元, $q$ は列に対するクエリを返す演算で, $f$ は列とは列同士の演算結果をマージする演算である。$edge$ を true にした場合, 頂点クエリではなく辺クエリとして処理する。$q$ や $f$ は非可換演算でもよいが最後に $l, r$ をマージするときにどちらかを反転する必要があることに注意。
* add($u$, $v$, $q$, $edge$):= 頂点 $u$ と $v$ を通るパスに対する更新クエリを処理する。
* lca($u$, $v$):= 頂点 $u$ と $v$ の最小共通祖先を返す。
* la($v$, $k$):= 頂点 $v$ から頂点 $0$ 方向に $k$ 個だけ遡った頂点を返す。
{% include read.html code="tree/heavy-light-decomposition.cpp" %}

## 検証

[AOJ GRL_5_C LCA: Lowest Common Ancestor](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=jp)
{% include read.html code="tree/verify/aoj-grl-5-c-2.test.cpp" %}

[AOJ 2450 Do use segment tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450)
{% include read.html code="tree/verify/aoj-2450.cpp" %}
