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
* lower_upper_bound($t$):= 文字列 $t$ を含む接尾辞のindexの下限と上限(半開区間)を返す。

空文字列が入っていない実装なので注意すること。

{% include read.html code="string/suffix-array.cpp" %}

* LongestCommonPrefixArray($SA$):= 接尾辞配列 $SA$ をもとに高さ配列を構築する。

{% include read.html code="string/longest-common-prefix-array.cpp" %}

例えば, <code>abracadabra</code> に対して接尾辞配列と高さ配列を構築し, output() をすると, 次のような実行結果になる。高さ配列には, ある接尾辞とその直前の接尾辞の最長共通接頭辞の長さが格納されている。

<pre>0: 0 a
1: 1 abra
2: 4 abracadabra
3: 1 acadabra
4: 1 adabra
5: 0 bra
6: 3 bracadabra
7: 0 cadabra
8: 0 dabra
9: 0 ra
10: 2 racadabra</pre>

## 検証

[AOJ ALDS_1_14_D 文字列検索](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D&lang=jp)

{% include read.html code="string/verify/aoj-alds-1-14-d.test.cpp" %}
