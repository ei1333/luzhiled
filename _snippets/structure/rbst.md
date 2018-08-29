---
layout: post
title: 平衡二分探索木(RBST)
date: 2018-08-07
category: データ構造
---

## 説明
RBST(Randomized Binary Search Tree)は平衡二分探索木の一種。ランダムなノードを根にして期待値的に木の高さを $O(\log N)$ に抑える。

## 計算量
* 構築 $O(N)$
* クエリ $O(\log N)$

## 実装例
* RandomizedBinarySearchTree($n$, $f$, $M1$):= ノードを $n$ 個用意する。ここで $f$  は2つの区間の要素をマージする二項演算, $M1$ はモノイドの単位元である。
* RandomizedBinarySearchTree($n$, $f$, $g$, $h$, $M1$, $OM0$):= ノードを $n$ 個用意する。ここで $f$ は2つの区間の要素をマージする二項演算, $g$ は要素と作用素をマージする二項演算(第三引数は対応する区間の長さ), $h$ は作用素同士をマージする二項演算, $M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
* merge($l$, $r$):= 木 $l$ と木 $r$ を併合する。
* split($t$, $k$):= 木 $t$ を $[0, k)[k, n)$ で分割する。
* build($v$):= 配列 $v$ をもとに木を構築する($O(n)$)。
* dump($r$):= 木 $r$ の各ノードを通りがけ順に格納したものを返す($O(n)$)。
* insert($t$, $k$, $v$):= 木 $t$ の位置 $k$ にノード $v$ を挿入する。
* erase($t$, $k$):= 木 $t$ の位置 $k$ のノードを削除する。
* query($t$, $l$, $r$):= 木 $t$ の区間 $[l, r)$ の値を二項演算した結果を返す。
* set_propagate($t$, $a$, $b$, $p$):= 木 $t$ の区間 $[a, b)$ に作用素 $p$ を適用する。
* set_element($t$, $k$, $x$):= 木 $t$ の $k$ 番目の値を $x$ に変更する。
* size($t$):= 木 $t$ のノード数を返す。
* makeset():= 空木を返す。

{% include read.html  code="structure/randomized-binary-search-tree.cpp" %}

## 検証

[AtCoder SoundHound Programming Contest 2018 Masters Tournament 本戦 E - Hash Swapping](https://beta.atcoder.jp/contests/soundhound2018-summer-final-open/tasks/soundhound2018_summer_final_e)
{% include read.html code="structure/verify/atcoder-shpc-2018-final-e.cpp" %}

## 応用: Multiset, Set
既に実装した機能に加えて, lower_bound() などを実装することで Multisetや Set として利用することができる。

kth_element は k(0-indeed) 番目に小さい値を返す。

{% include read.html  code="structure/randomized-binary-search-tree-set.cpp" %}
