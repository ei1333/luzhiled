---
layout: post
title: Mo's Algorithm
date: 2019-05-21
category: その他
---

## 説明
[Mo's algorithm - ei1333の日記](https://ei1333.hateblo.jp/entry/2017/09/11/211011)

クエリを先読みできて、区間の伸縮が簡単に計算できるとき Mo's Algorithm が適用できる可能でいがある。

## 計算量
* $O(f(N) Q \log N)$

区間を伸縮するときの計算量を $f(N)$ とする

## 実装例

* Mo($N$, $Q$):= 区間の長さ $N$, $Q$ 個のクエリで初期化する。
* add($l$, $r$):= クエリ $[l, r)$ を追加する。
* run($add$, $del$, $rem$):= 全てのクエリを処理する。ここで, add(idx) は idx 番目の要素を入れる, del(idx) は idx 番目の要素を消す, rem(idx) はクエリ idx を処理する関数。

{% include read.html  code="other/mo.cpp" %}

## 検証

[SPOJ D-Query](https://www.spoj.com/problems/DQUERY/)
{% include read.html code="other/verify/spoj-dquery.cpp" %}

[SPOJ Frequent values](https://www.spoj.com/problems/FREQUENT/)
{% include read.html code="other/verify/spoj-frequent.cpp" %}

## 応用 1: ロールバック平方分割
普通のMoだと要素を削除する操作が要求された。

[Mo's algorithm の上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000) をすると、削除操作は不要で要素の追加と snapshot を撮った位置まで巻き戻す rollback ができればよい。

* MoRollBack($N$, $Q$):= 区間の長さ $N$, $Q$ 個のクエリで初期化する。
* add($l$, $r$):= クエリ $[l, r)$ を追加する。
* run($add$, $rem$, $reset$, $snapshot$, $rollback$):= 全てのクエリを処理する。ここで, add(idx) は idx 番目の要素を入れる, rem(idx) はクエリ idx を処理する、$reset$ はデータ構造の初期化, $snapshot$ は現在の状態を記録, $rollback$ は $snapshot$ まで巻き戻す関数。

{% include read.html  code="other/mo-rollback.cpp" %}

[Codeforces 
2014-2015 ACM-ICPC, NEERC, Southern Subregional Contest A - Nasta Rabbara](https://codeforces.com/gym/100513/problem/A)

区間 $[l_i, r_i]$ の辺のみがあるときに、二部グラフかどうか答えよ
{% include read.html code="other/verify/codeforces-neerc-ssc-2014-a.cpp" %}
