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
* RandomizedBinarySearchTree($f$, $M1$):= コンストラクタ。ここで $f$  は2つの区間の要素をマージする二項演算, $M1$ はモノイドの単位元である。
* RandomizedBinarySearchTree($f$, $g$, $h$, $M1$, $OM0$):= コンストラクタ。ここで $f$ は2つの区間の要素をマージする二項演算, $g$ は要素と作用素をマージする二項演算(第三引数は対応する区間の長さ), $h$ は作用素同士をマージする二項演算, $M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
* make_node($idx$, $v$) : ID が $idx$, 値に $v$ を入れたノードを新しく生成する。
* expose(t) : $t$ と根との間を Heavy-edge でつなげて, $t$ を Heavy-edge の Splay 木の根にする.
* link(child, parent) : child の親を parent にする(もともと parent の連結成分に child がつながってたらこわれるので注意すること)。
* cut(child) : child の親と child を切り離す。
* evert($t$) : $t$ をもともとの木の根にする。
* lca($u$, $v$) : $u$ と $v$ のLCAを返す。
* get_path($t$) : $t$ から根までのパスに出現する頂点を返す($O(n)$)。
* set_propagate($t$, $x$) : 根からノード $t$ までのパスに作用素 $x$ を適用する。

{% include read.html  code="structure/linkcuttree.cpp" %}

