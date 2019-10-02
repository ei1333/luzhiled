---
layout: post
title: Mod-Int
date: 2019-03-31
category: 数学
---

## 説明
mod M での四則演算を行う構造体である。

## 計算量
* 加減乗算 $O(1)$
* 除算 $O(\log N)$ ($M$ は素数)

## 実装例
{% include read.html  code="math/mod-int.cpp" %}

## 任意Mod-Int
その型を使う前に ArbitraryModInt::set_mod($md$) をすること.

{% include read.html  code="math/arbitrary-mod-int.cpp" %} 
