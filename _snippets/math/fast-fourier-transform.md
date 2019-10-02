---
layout: post
title: 高速フーリエ変換(Fast-Fourier-Transform)
date: 2019-06-18
category: 数学
---

## 説明
高速フーリエ変換による畳み込みを行う。

## 計算量
* $O((n + m) \log (n + m))$

## 実装例
* multiply($a$, $b$):= 配列 $a$ と配列 $b$ を畳み込みした結果を返す。

{% include read.html code="math/fast-fourier-transform.cpp" %}

## 検証
[AtCoder ATC_001_C 高速フーリエ変換](https://beta.atcoder.jp/contests/atc001/tasks/fft_c)
{% include read.html code="math/verify/atcoder-atc-001-c-2.cpp" %}

## 応用 1: mod 上でのFFT
mod 上でのFFTによる畳込みを行う。長さ $n$ のFFTを行うとき mod の原子 $n$ 乗根が必要になる。よく使いそうな素数と原子根のペアとして 周期 $2^{21}$ の $(1012924417, 5), (924844033, 5)$ などがある。

* multiply($A$, $B$):= 配列 $A$ と配列 $B$ を畳み込みした結果を返す。
{% include read.html code="math/number-theoretic-transform.cpp" %}

[AtCoder ATC_001_C 高速フーリエ変換](https://beta.atcoder.jp/contests/atc001/tasks/fft_c)
{% include read.html code="math/verify/atcoder-atc-001-c.cpp" %}

