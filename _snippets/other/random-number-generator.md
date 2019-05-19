---
layout: post
title: 乱数生成器(Random-Number-Generator)
date: 2019-05-19
category: その他
---

## 説明
乱数を発生させる。

こどふぉで rand() や random_device を使うと危険。

## 計算量
* $O(1)$

## 実装例
* ($y$):= $[0, y)$ で発生させた乱数を返す。
* ($x$, $y$):= $[x, y)$ で発生させた乱数を返す。

{% include read.html  code="other/random-number-generator.cpp" %}

## 参考
* [Don't use rand(): a guide to random number generators in C++ - Codeforces](https://codeforces.com/blog/entry/61587)
