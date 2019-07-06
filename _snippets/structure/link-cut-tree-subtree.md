---
layout: post
title: 部分木クエリを扱うLink-Cut木(Link-Cut-Tree-Subtree)
date: 2019-07-06
category: データ構造
---

## 説明
がんばると、Link-Cut木で部分木に対するクエリも処理できるようになる。

## 計算量
* クエリ $O(\log N)$

## 実装例
ポインタベースの実装

テンプレート引数には、載せたいデータを定義した構造体を渡す。構造体では、以下の関数を定義すること。基本的にメンバ変数には、そのノードの key、部分木全体のdata、Light-Edgeのみのdata(これとkeyと$parent$と$child$を使ってマージしたものが部分木全体のdataとなる) が必要。

* コンストラクタ := 単位元
* set($k$) := そのノードに値 $k$ を持たせる。
* merge($parent$, $child$) := そのノードと、$parent$(親, 左部分木), $child$(子, 右部分木) をマージする。
* reverse() := そのノードの親と子を入れ替える。
* insert_light($child$) := $child$ をLight-Edgeでそのノードに繋ぐ
* erase_light($child$) := Light-Edge で繋がっていた $child$ をそのノードから削除する

{% include read.html  code="structure/link-cut-tree-subtree.cpp" %}

## 検証

[Codeforces Round #564 (Div. 1) E. Nauuo and ODT](https://codeforces.com/contest/1172/problem/E)
{% include read.html  code="structure/verify/codeforces-564-e.cpp" %}

[技術室奥プログラミングコンテスト J - 仕事をしよう！ (Working!)](https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j)  
TLEします！！！！　抽象化せずにベタで書くと間に合います　たぶん単位元を返すところが重そう
{% include read.html  code="structure/verify/atcoder-tkppc-2015-j.cpp" %}

## 参考
[Link Cut Treeで部分木の情報を管理する - beet's soil](http://beet-aizu.hatenablog.com/entry/2019/06/08/221833)
