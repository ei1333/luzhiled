---
layout: post
title: 全方位木DP(ReRooting)
date: 2018-12-28
category: 木
tags: 全方位木DP
---

## 説明
全方位木DPの抽象化。

使い方などは [もうひとつの全方位木DP](https://ei1333.hateblo.jp/entry/2018/12/21/004022) を参照。

## 計算量
* $O(V)$

定数倍が重め。

## 実装例

* ReRooting($N$, $f1$, $f2$, $ident$):= $N$ 頂点の木で初期化する。
* add_edge($u$, $v$, $d$):= 頂点 $u, v$ を結ぶ重み $d$ の辺を追加する。
* solve():= 全方位木DPをしてその結果を返す。

{% include read.html  code="tree/rerooting.cpp" %}
