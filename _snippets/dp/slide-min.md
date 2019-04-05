---
layout: post
title: スライド最小値(Slide-Min)
date: 2018-12-28
category: 動的計画法
---

## 説明
スライドする区間の最小値を求める。

## 計算量
* $O(N)$

## 実装例
* slide_min($v$, $k$): 配列 $v$ の幅 $k$(1-indexed) の各連続区間についての最小値を返す。
{% include read.html  code="dp/slide-min.cpp" %}

## 検証
[AtCoder CODE FESTIVAL 2016 Tournament Round 3 A - ストラックアウト](https://atcoder.jp/contests/cf16-tournament-round3-open/tasks/asaporo_d)
{% include read.html code="dp/verify/atcoder-cf16-tournament-round3-a.cpp" %}
