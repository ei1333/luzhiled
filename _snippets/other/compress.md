---
layout: post
title: 座標圧縮(Compress)
date: 2019-08-02
category: その他
---

## 説明
座標の大小関係を維持しつつ、値の範囲を座標の種類数に狭める。

## 計算量
* build: $O(N \log N)$
* get: $O(\log N)$


## 実装例
* add(vs): vs内にある座標をすべて追加する
* add(x): 座標 x を追加する
* build(): 構築する
* get(vs): vs内にある座標をそれぞれ座標圧縮したものを返す
* get(x): 座標 x を座標圧縮したものを返す
* \[k\]:= 座標圧縮後の k が示す実際の座標を返す

{% include read.html  code="other/compress.cpp" %}

## 検証

[AtCoder Beginner Contest 036 C - 座圧](https://atcoder.jp/contests/abc036/tasks/abc036_c)
{% include read.html code="other/verify/atcoder-abc-036-c.cpp" %}

