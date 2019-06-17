---
layout: post
title: タイマー(Timer)
date: 2019-06-07
category: その他
---

## 説明
ある時点からの経過時間を観測する。

## 計算量
* $O(1)$

## 実装例
* reset():= タイマーをリセットする。
* elapsed():= リセットしてからの経過時間をミリ秒単位で返す。

{% include read.html  code="other/timer.cpp" %}
