---
layout: post
title: 離散対数問題(Mod-Log)
date: 2019-10-25
category: 数学
---

## 説明
与えられた $a, b, p$ に対し $a^x \equiv b \pmod p$ を満たす非負整数 $x$ の最小値を求める。

## 計算量
* $O(\sqrt p)$

## 実装例

* mod_log($a$, $b$, $p$): $a^x \equiv b \pmod p$ を満たす非負整数 $x$ の最小値を返す。存在しない場合は $-1$。

{% include read.html  code="math/mod-log.cpp" %}

## 検証

[AtCoder Regular Contest 042 D あまり](https://atcoder.jp/contests/arc042/tasks/arc042_d)
{% include read.html code="math/verify/atcoder-arc-042-d.cpp" %}
