---
layout: post
title: Binary-Trie
date: 2019-04-18
category: データ構造
---

## 説明
う

## 計算量
* クエリ $O(\log \|S\|)$

## 実装例
exist は子供以下に追加された文字列の個数, accept はそのノードにマッチする全ての追加された文字列の番号が格納される。

coutn_less($x)$ は $x$ 未満の値の個数, get_kth($k$) は $k$ 番目(1-indexed)に小さい値を返す。mex_query() は追加される値が相異なる必要がある(重複があってもマージを真面目にやればできるはずだけど実装してない)

{% include read.html  code="structure/binary-trie.cpp" %}

## 応用1: 永続Trie
かきなおす

Trie は木なので比較的容易に永続できる。以下では、2進Trieをポインタベースで実装し、永続している。
{% include read.html  code="structure/persistent-binary-trie.cpp" %}
