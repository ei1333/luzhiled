---
layout: post
title: ローリングハッシュ(Rolling-Hash)
date: 2018-03-31
category: 文字列
tags: ハッシュ
---

## 説明
文字列の一致判定や最長共通接頭辞の長さを求めることをハッシュを用いて高速に行うもの。

## 計算量
* 構築 $O(N)$
* get, connect $O(1)$
* LCP $O(\log N)$

## 実装例

* RollingHash($s$, $base$):= 文字列 $s$ のハッシュテーブルを構築する。
* get($l$, $r$):= 区間 $[l, r)$ のハッシュ値を求める。
* connect($h1$, $h2$, $h2len$):= ハッシュ値 $h1$ と, 長さ $h2len$ のハッシュ値 $h2$ を結合する。
* LCP($b$, $l1$, $r1$, $l2$, $r2$):= 区間 $[l1, r1)$ と, ハッシュテーブルが $b$ からなる区間 $[l2, r2)$ の文字列の最長共通接頭辞の長さを求める。

{% include read.html code="string/rolling-hash.cpp" %}

## 検証

[AOJ ALDS_1_14_B 文字列検索](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B&lang=jp)

{% include read.html code="string/verify/aoj-alds-1-14-b.test.cpp" %}
