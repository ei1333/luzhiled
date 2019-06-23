---
layout: post
title: 階乗(Factorial)
date: 2019-06-18
category: 数学
---

## 説明
階乗 mod 素数 を効率的に求める。

## 計算量
* $O(\sqrt {p} \log p)$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html) [Combination](../math/combination.html) [Fast-Fourier-Transform](../math/fast-fourier-transform.html) [Arbitrary-Mod-Convolution](../math/arbitrary-mod-convolution.html)

テンプレート引数としてMod-Intが渡されることを想定している。

* factorial($n$):= $n! \pmod p$ を返す。

{% include read.html code="math/factorial.cpp" %}

## 検証
[yukicoder No.502 階乗を計算するだけ](https://yukicoder.me/problems/no/502)
{% include read.html code="math/verify/yukicoder-502.cpp" %}

[SPOJ FACTMODP - Factorial Modulo Prime](https://www.spoj.com/problems/FACTMODP/)  
modintを可変modとlong longに対応して、任意modFFTの精度をlong doubleにしてうくをすることで mod が $10^{11}$ 以下の制約に対応している。
{% include read.html code="math/verify/spoj-factmodp.cpp" %}

## 参考
[階乗 mod 素数 - memo](https://min-25.hatenablog.com/entry/2017/04/10/215046)
