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
* query($S$, $f$): 文字列 $S$ のプレフィックスに一致する文字列を検索する。一致した文字列ごとに関数 $f$ が呼び出される。
* size(): ノード数を返す
* count(): 存在する文字列の個数を返す

{% include read.html  code="structure/trie.cpp" %}

## 検証

[AtCoder 天下一プログラマーコンテスト2016本戦 C - たんごたくさん](https://tenka1-2016-final-open.contest.atcoder.jp/tasks/tenka1_2016_final_c)
{% include read.html code="structure/verify/atcoder-tenka1-2016-final-c.cpp" %}

