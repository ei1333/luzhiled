---
layout: post
title: 任意mod畳み込み(Arbitrary-Mod-Convolution)
date: 2019-06-18
category: 数学
---

## 説明
高速フーリエ変換による畳み込みを行う。$2^{30}$ 未満ならどの mod でもOK。それ以上の mod がでるコンテストには参加しない。
## 計算量
* $O((n + m) \log (n + m))$

## 実装例
依存ライブラリ [Mod-Int](../math/mod-int.html) [Fast-Fourier-Transform](../math/fast-fourier-transform.html)

テンプレート引数としてMod-Intが渡されることを想定している。

* multiply($a$, $b$):= 配列 $a$ と配列 $b$ を畳み込みした結果を返す。

{% include read.html code="math/arbitrary-mod-convolution.cpp" %}

## 検証
[AtCoder ATC_001_C 高速フーリエ変換](https://beta.atcoder.jp/contests/atc001/tasks/fft_c)
{% include read.html code="math/verify/atcoder-atc-001-c-3.cpp" %}
