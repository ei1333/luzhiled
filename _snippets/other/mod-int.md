---
layout: post
title: Mod-Int
date: 2018-12-28
category: その他
---

## 説明
mod M での四則演算を行う構造体である。

## 計算量
* 加減乗算 $O(1)$
* 除算 $O(\log N)$ ($M$ は素数)

## 実装例
{% include read.html  code="other/mod-int.cpp" %}
