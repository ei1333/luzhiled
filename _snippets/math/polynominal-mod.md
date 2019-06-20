---
layout: post
title: 多項式mod(Polynominal-Mod)
date: 2019-06-18
category: 数学
---

## 説明
えーこれはなんでしょうかねー

形式的べき級数(Formal power series)を扱う。

$P(x) = \sum_{i=0}^{\infty} c_{i} x^{i}$

実用的には多項式 $P(x), Q(x)$ の最初のいくつかの項を与えたときに以下の演算を行う。基本的には演算を畳み込みに落とし込んで FFT を用いて高速化できる。

* $O(n)$ : $P(x)+Q(x), P(x)-Q(x), -P(x)$
* $O(n \log n)$ : $P(x)Q(x)$
* $O(n \log n)$ : $\frac {1} {P(x)}$ 
* $O(n \log n)$ : $\sqrt {P(x)}$

## 計算量
上に示した

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html) [Fast-Fourier-Transform](../math/fast-fourier-transform.html) [Arbitrary-Mod-Convolution](../math/arbitrary-mod-convolution.html)

テンプレート引数としてMod-Intが渡されることを想定している。

TODO 使い方

{% include read.html code="math/polynominal-mod.cpp" %}

## 検証

[yukicoder No.3046 yukicoderの過去問](https://yukicoder.me/problems/no/3046) inverse()
{% include read.html code="math/verify/yukicoder-3046.cpp" %}

[Codeforces Round #250 (Div. 1) E - The Child and Binary Tree](https://codeforces.com/contest/438/problem/E) inverse(), sqrt()
{% include read.html code="math/verify/codeforces-250-e.cpp" %}


## 参考
[Operations on Formal Power Series](https://codeforces.com/blog/entry/56422)

