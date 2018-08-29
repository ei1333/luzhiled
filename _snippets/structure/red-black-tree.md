---
layout: post
title: 平衡二分探索木(Red-Black-Tree)
date: 2018-08-29
category: データ構造
---

## 説明
Red-Black-Tree(赤黒木)は平衡二分探索木の一種。
RBSTとは異なり葉にデータを持たせる実装なので注意。具体的にはpoolの大きさを2倍とる必要がある。

ArrayPoolは使用可能なノードを管理する構造体である。木を分割するときに節ノードを捨てることがあるので, これを回収している。

## 計算量
* 構築 $O(N)$
* クエリ $O(\log N)$

## 実装例
* RedBlackTree($n$, $M1$, $OM0$):= ノードを $n$ 個用意する。$M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
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

{% include read.html  code="structure/red-black-tree.cpp" %}

## 検証

[AtCoder SoundHound Programming Contest 2018 Masters Tournament 本戦 E - Hash Swapping](https://beta.atcoder.jp/contests/soundhound2018-summer-final-open/tasks/soundhound2018_summer_final_e)
{% include read.html code="structure/verify/atcoder-shpc-2018-final-e-2.cpp" %}

## 応用: 永続赤黒木
やばいね(やばいので

RBSTは永続できない(参考: [RBSTはコピー可能は嘘 - よすぽの日記](http://yosupo.hatenablog.com/entry/2015/10/30/115910))ので, 永続するならこちらを使うべき。

{% include read.html  code="structure/persistent-red-black-tree.cpp" %}

[AtCoder ARC_030_D - グラフではない](https://arc030.contest.atcoder.jp/tasks/arc030_4)
{% include read.html code="structure/verify/atcoder-arc-030-d.cpp" %}
