---
layout: post
title: トライ木(Trie)
date: 2018-08-19
category: データ構造
---

## 説明
プレフィックス木とも呼ばれる。あるノードの配下の全てのノードには自身に対応する文字列に共通するプレフィックスがあり, ルートには空の文字列が対応している。

## 計算量
* 追加 $O(\|S\|)$
* クエリ $O(\|S\|)$

## 実装例

exist は子供以下に追加された文字列の個数, accept はそのノードにマッチする全ての追加された文字列の番号が格納される。

* Trie< char_size, margin >(): 文字列の種類数 char_size, 開始文字が margin のトライ木を作成する。
* add($S$): 文字列 $S$ をトライ木に追加する
* query($S$, $F$): 文字列 $S$ のプレフィックスに一致する文字列を検索する。一致した文字列ごとに関数 $F$ が呼び出される。
* size(): 追加された文字列の数を返す
* nodesize(): ノード数を返す

{% include read.html  code="structure/trie.cpp" %}

## 検証

[AtCoder 天下一プログラマーコンテスト2016本戦 C - たんごたくさん](https://tenka1-2016-final-open.contest.atcoder.jp/tasks/tenka1_2016_final_c)
{% include read.html code="structure/verify/atcoder-tenka1-2016-final-c.cpp" %}

## 応用1: 2進Trie

Trie は xor と相性が良い。以下では、Trieに格納されている値全体に対する xor と, max, min, mex クエリを実装している。(全体xorについては遅延評価しなくてもできる 実装の簡略化が目的）

{% include read.html  code="structure/binary-trie.cpp" %}

## 応用2: 永続Trie

Trie は木なので比較的容易に永続できる。以下では、2進Trieをポインタベースで実装し、永続している。
{% include read.html  code="structure/persistent-binary-trie.cpp" %}
