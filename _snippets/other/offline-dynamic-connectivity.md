---
layout: post
title: Offline-Dynamic-Connectivity
date: 2019-05-21
category: その他
---

## 説明
[ちょっと変わったセグメント木の使い方 - ei1333の日記](https://ei1333.hateblo.jp/entry/2017/12/14/000000)

辺の追加削除クエリがオフラインで与えられる場合は、Undo可能Union-Findを用いることで効率的に処理できる。

## 計算量
* $O(Q \log Q \log N)$

## 実装例
依存ライブラリ [Undo可能Union-Find](../structure/union-find.html)

* Offline-Dynamic-Connectivity($V$, $Q$):= 頂点数 $V$, $Q$ 個のクエリで初期化する。
* insert($idx$, $s$, $t$):= 時刻 $idx$ に辺 $s-t$ を追加する。
* erase($idx$, $s$, $t$):= 時刻 $idx$ に辺 $s-t$ を削除する。
* build():= クエリを全て与えた後に呼び出す。
* run($f$):= build() を実行後に呼び出す。各 $i(0 \leq i \lt Q)$ について $f(i)$ が呼び出される。

{% include read.html  code="other/offline-dynamic-connectivity.cpp" %}

## 検証

[Codeforces Dynamic connectivity contest A - Connect and Disconnect](https://codeforces.com/gym/100551/problem/A)

{% include read.html code="other/verify/codeforces-dynamic-connectivity-contest-a.cpp" %}
