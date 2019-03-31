---
layout: post
title: 組合せ(Combination)
date: 2018-11-21
category: 数学
tags: 組合せ
---

## 説明
${}_n \mathrm{C} _r$ などを求める。

## 計算量
* 前計算 $O(N)$
* クエリ $O(1)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)

テンプレート引数としてMod-Intが渡されることを想定している。

{% include read.html  code="math/combination.cpp" %}
