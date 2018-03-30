---
layout: post
title: 単一始点最短路(Bellman-Ford)
date: 2018-03-23
category: グラフ
tags: 単一始点最短路
---

## 説明
単一始点全点間最短路を求めるアルゴリズム。単一始点全点間最短路を求めるアルゴリズム。負辺があっても動作する。また負閉路も検出する。

## 計算量
* $O(VE)$

## 実装例

* bellman_ford($edges$, $V$, $s$):= $V$ 頂点の重み付き辺集合 $edges$ 上で、頂点 $s$ から全点間の最短コストを求める。到達できないとき, 型の最大値が格納される。負閉路を検出した時空列を返す。

{% include read.html  code="graph/bellman-ford.cpp" %}

## 検証

[AOJ DSL_1_B 単一始点最短経路（負の重みをもつ辺を含む](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=jp)
{% include read.html code="graph/verify/aoj-grl-1-b.cpp" %}

## 応用 1: 牛ゲー
単一始点最短路は特殊な線形計画問題の双対である(いわゆる牛ゲー)。

頂点 $s$ から頂点 $v$ までの最短経路を $f(v)$ とする。グラフに負閉路がなければ $f(s) = 0$ である。また頂点 $u$ から $v$ へ向かう重み $w$ の辺が存在するとき $f(u) + w \ge f(v)$ が成立する。言い換えれば, 頂点 $v$ には最大でも $f(u) + w$ のコストで到達可能を意味している。

最短路問題を解くことで各 $v$ について $f(v)$ がとりうる最大の値を求めることができる。つまり $f(v)$ の最大値を求める問題が最短路問題に対応する。

すべての制約が 変数+定数≧変数 の形で表される線形計画問題は, 対応するグラフ上での最短路問題を解くことで求めることが出来る。$f(u) + w \ge f(v)$ が成立するとき, 頂点 $u$ から頂点 $v$ へ向かう重み $w$ の辺を張れば良い。

例: [AOJ0304 学食](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0304)
{% include read.html code="graph/verify/aoj0304.cpp" %}

