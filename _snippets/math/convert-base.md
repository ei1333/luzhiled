---
layout: post
title: 進数変換(Convert-Base)
date: 2018-11-21
category: 数学
tags: 素数
---

## 説明
10進数 $x$ を $b$ 進数に変換する。

## 計算量
* $O(\log x)$

## 実装例

* convert_base($x$, $b$):= 10進数 $x$ を $b$ 進数に変換した結果を返す。

{% include read.html  code="math/convert-base.cpp" %}
