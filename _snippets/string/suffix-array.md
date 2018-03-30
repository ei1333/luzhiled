---
layout: post
title: 接尾辞配列(Suffix-Array)
date: 2018-03-31
category: 文字列
tags: 接尾辞配列
---

## 説明
接尾辞配列を構築する。

## 計算量
* 接尾辞配列構築 $O(N \log N)$
* 文字列検索 $O(M \log N)$

* 高さ配列構築 $O(N)$

## 実装例

* SuffixArray($str$):= 文字列 $str$ の接尾辞配列を構築する。
* lower_upper_bound($t$):= 文字列 $t$ を含む接尾辞のindexの下限と上限を返す。

空文字列が入っていない実装なので注意すること。

{% include read.html code="string/suffix-array.cpp" %}

* LongestCommonPrefixArray($SA$):= 接尾辞配列 $SA$ をもとに高さ配列を構築する。

{% include read.html code="string/longest-common-prefix-array.cpp" %}
## 検証
