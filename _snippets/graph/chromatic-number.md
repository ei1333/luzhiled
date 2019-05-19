---
layout: post
title: 彩色数(Chromatic-Number)
date: 2019-05-19
category: グラフ
---

## 説明
グラフの彩色数を求める。

彩色数とは、隣接する頂点が異なる色となるように彩色するために必要な最小色数である。


## 計算量
* $O(2^{N} N)$

## 実装例
* chromatic_number($g$):= 隣接行列 $g$ で表されるグラフの彩色数を返す。

{% include read.html  code="graph/chromatic-number.cpp" %}

## 参考
[指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)
