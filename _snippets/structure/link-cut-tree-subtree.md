---
layout: post
title: Link-Cut木 部分木クエリ(Link-Cut-Tree-Subtree)
date: 2019-07-20
category: データ構造
---

## 説明
がんばると、Link-Cut木で部分木に対するクエリも処理できるようになる。

普通のLink-Cut木と同様に遅延評価もできる気がするが, そのような問題を見たことないので未実装。

## 計算量
* クエリ $O(\log N)$

## 実装例
テンプレートの第一引数には、載せたいデータを定義した構造体を渡す。構造体では、以下の関数を定義すること。基本的にメンバ変数には部分木全体のdata、Light-Edgeのみのdata($key$とLight-Edgeのみのdataと$parent$と$child$を使ってマージしたものが部分木全体のdataとなるイメージ) が必要。

* merge($key$, $parent$, $child$) := そのノードの値 $key$ と、$parent$(親, 左部分木), $child$(子, 右部分木) をマージする。
* toggle() := そのノードの親と子を入れ替える。
* add($child$) := $child$ をLight-Edgeでそのノードに繋ぐ
* erase($child$) := Light-Edge で繋がっていた $child$ をそのノードから削除する

{% include read.html  code="structure/link-cut-tree-subtree.cpp" %}

## 検証

[Codeforces Round #564 (Div. 1) E. Nauuo and ODT](https://codeforces.com/contest/1172/problem/E)
{% include read.html  code="structure/verify/codeforces-564-e.cpp" %}

[技術室奥プログラミングコンテスト J - 仕事をしよう！ (Working!)](https://atcoder.jp/contests/tkppc/tasks/tkppc2015_j)  
{% include read.html  code="structure/verify/atcoder-tkppc-2015-j.cpp" %}

その他いろいろ
[QTREE LCT + Dynamic Distance Sum](https://ei1333.hateblo.jp/entry/2019/07/09/005011)

## 参考
[Link Cut Treeで部分木の情報を管理する - beet's soil](http://beet-aizu.hatenablog.com/entry/2019/06/08/221833)
