---
layout: post
title: 根付き木に変換(Convert-Rooted-Tree)
date: 2019-08-02
category: 木
---

## 説明
木 $g$ を根 $r$ から遠ざかる辺のみからなる根付き木に変換する。

## 計算量
* $O(N)$

## 実装例
* convert_rooted_tree($g$, $r=0$):= 木 $g$ を根 $r$ から遠ざかる辺のみからなる根付き木に変換したものを返す

{% include read.html code="tree/convert-rooted-tree.cpp" %}
