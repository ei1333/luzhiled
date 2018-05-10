---
layout: post
title: 高速フーリエ変換(Fast-Fourier-Transform)
date: 2018-05-10
category: 数学
---

## 説明
高速フーリエ変換による畳み込みを行う。

## 計算量
* $O(N \log N)$

## 実装例

## 応用 1: mod 上でのFFT
mod 上でのFFTによる畳込みを行う。長さ $n$ のFFTを行うとき mod の原子 $n$ 乗根が必要になる。よく使いそうな素数と原子根のペアとして 周期 $2^{21}$ の $(1012924417, 5), (924844033, 5)$ などがある。

{% include read.html code="math/number-theoretic-transform.cpp" %}

[AtCoder ATC_001_C 高速フーリエ変換](https://beta.atcoder.jp/contests/atc001/tasks/fft_c)
{% include read.html code="math/verify/atcoder-atc-001-c.cpp" %}

