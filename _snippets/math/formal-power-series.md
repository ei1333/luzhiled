---
layout: post
title: 形式的冪級数(Formal-Power-Series)
date: 2019-10-03
category: 数学
---

## 説明
えーこれはなんでしょうかねー

形式的べき級数(Formal power series)を扱う。

$P(x) = \sum_{i=0}^{\infty} c_{i} x^{i}$

実用的には多項式 $P(x), Q(x)$ の最初のいくつかの項を与えたときに以下の演算を行う。基本的には演算を畳み込みに落とし込んで FFT を用いて高速化できる。

* $O(n)$ : $P(x)+Q(x), P(x)-Q(x), -P(x), P'(x), \int P(x) dx, kP(x)$
* $O(n \log n)$ : $P(x)Q(x)$
* $O(n \log n)$ : $\frac {1} {P(x)}$ 
* $O(n \log n)$ : $\sqrt {P(x)}$
* $O(n \log n)$ : $\exp(P(x))$
* $O(n \log n)$ : $log(P(x)) = \int \frac {P'(x)} {P(x)}$
* $O(n \log n)$ : $P(x)^{k} = \exp(k \log P(x))$

## 計算量
上に示した

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html)

テンプレート引数としてMod-Intが渡されることを想定している。

TODO 使い方

{% include read.html code="math/formal-power-series.cpp" %}

## 検証

[yukicoder No.3046 yukicoderの過去問](https://yukicoder.me/problems/no/3046) inverse()
{% include read.html code="math/verify/yukicoder-3046.cpp" %}

[Codeforces Round #250 (Div. 1) E - The Child and Binary Tree](https://codeforces.com/contest/438/problem/E) inverse(), sqrt()
{% include read.html code="math/verify/codeforces-250-e.cpp" %}


## 参考
[Operations on Formal Power Series](https://codeforces.com/blog/entry/56422)

