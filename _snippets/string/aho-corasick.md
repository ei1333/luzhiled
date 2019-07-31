---
layout: post
title: 複数文字列検索(Aho-Corasick)
date: 2018-08-19
category: 文字列
---

## 説明
複数文字列に対するパターンマッチングオートマトンを構築する。

## 計算量
* 構築 $O(\sum \|S_i\|)$

$S_i$ はAho-Corasickに追加した文字列

## 実装例
依存ライブラリ [Trie](../structure/trie.html)

* build(): パターンマッチングオートマトンを構築する
* match($S$): 文字列 $S$ がパターンにマッチした回数を返す。パターンのidと一致回数をmapで返す。
* move($c$, now): ノード now で文字 $c$ が出現したときに, パターンにはじめてマッチした個数と, nowの移動先のノードをpairで返す。

{% include read.html  code="string/aho-corasick.cpp" %}
