---
layout: post
title: Link-Cut木(Link-Cut-Tree)
date: 2018-08-10
category: データ構造
---

## 説明
動的木のひとつ。こわい。

## 計算量
* クエリ $O(\log N)$

## 実装例
* LinkCutTree($f$, $t$, $M1$):= コンストラクタ。ここで $f$  は2つの区間の要素をマージする二項演算, $t$ は要素を反転する演算, $M1$ はモノイドの単位元である。
* LinkCutTree($f$, $g$, $h$, $t$, $M1$, $OM0$):= コンストラクタ。ここで $f$ は2つの区間の要素をマージする二項演算, $g$ は要素と作用素をマージする二項演算(第三引数は対応する区間の長さ), $h$ は作用素同士をマージする二項演算, $t$ は要素の向きを反転する演算, $M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
* make_node($idx$, $v$) : ID が $idx$, 値に $v$ を入れたノードを新しく生成する。
* expose($t$) : $t$ と根との間を Heavy-edge でつなげて, $t$ を Heavy-edge の Splay 木の根にする。戻り値は $t$ ではないので注意。
* link($child$, $parent$) : child の親を parent にする(もともと parent の連結成分に child がつながってたらこわれるので注意すること)。もともとの $child$ は木の根である必要がある(根ではない場合は事前に expose($child$) を呼び出すこと)。
* cut($child$) : child の親と child を切り離す。
* evert($t$) : $t$ をもともとの木の根にする。
* lca($u$, $v$) : $u$ と $v$ のLCAを返す。
* get_path($t$) : $t$ から根までのパスに出現する頂点を返す($O(n)$)。
* set_propagate($t$, $x$) : 根からノード $t$ までのパスに作用素 $x$ を適用する。
* get_kth($x$, $k$) := $x$ から根までのパスに出現する頂点を並べたときの $k$ 番目の頂点を返す(0-indexed, つまり $x$ が $0$ 番目)。
* get_root($x$):= $x$ の根を返す。

{% include read.html  code="structure/link-cut-tree.cpp" %}

## 検証
[AOJ 2450 Do use segment tree](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450)
{% include read.html  code="structure/verify/aoj-2450.cpp" %}

[JOI春合宿2015 G - 道路整備](https://atcoder.jp/contests/joisc2015/tasks/joisc2015_g)
辺属性のクエリを処理したいときは、辺にも頂点を生やしてあげると実装が楽になる。

{% include read.html  code="structure/verify/atcoder-joisc-2015-g.cpp" %}

## 参考
[Link-Cut 木 - ei1333の日記](https://ei1333.hateblo.jp/entry/2018/05/29/011140)
