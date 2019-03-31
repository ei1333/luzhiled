---
layout: post
title: ベル数(Bell-Number)
date: 2019-03-31
category: 数学
tags: べき乗
---

## 説明
$N$ 番目のベル数 $B_N$ を求める。

[きりかしゃんのツイート](https://twitter.com/kirika_comp/status/953991620990390272)


## 計算量
* $O(N \log N)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)
[Combination](../math/combination.html)


* bell($n$):= $n$ 番目のベル数を返す

{% include read.html  code="math/bell-number.cpp" %}
