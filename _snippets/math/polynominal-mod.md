---
layout: post
title: 多項式mod(Polynominal-Mod)
date: 2019-06-18
category: 数学
---

## 説明
えーこれはなんでしょうかねー

## 計算量
* 加算・減算 $O(N)$
* 乗算・除算(逆元) $O(N \log N)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html) [Fast-Fourier-Transform](../math/fast-fourier-transform.html) [Arbitrary-Mod-Convolution](../math/arbitrary-mod-convolution.html)

テンプレート引数としてMod-Intが渡されることを想定している。

TODO 使い方

{% include read.html code="math/polynominal-mod.cpp" %}

## 検証
乗算・除算のみ
[yukicoder No.3046 yukicoderの過去問](https://yukicoder.me/problems/no/3046)
{% include read.html code="math/verify/yukicoder-3046.cpp" %}

