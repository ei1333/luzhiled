---
layout: post
title: 列の平方分割(Sqrt-Decomposition)
date: 2019-02-25
category: データ構造
---

## 説明
列の平方分割により、区間クエリを効率的に処理できるようになる場合がある。

ここでは長さ $N$ の要素があって各要素にはその要素の高さと値が設定されているときの問題を扱う(二次元座標のイメージ)。最初の要素の高さは全て $0$ である。このときある区間の高さに対して一様に $1$ 加減算、ある区間のある高さまたはある高さ以上にある要素の和を求めるクエリの処理を平方分割により $O(\sqrt N)$ で解く。

(ある高さにある要素の和だけを求めたい場合には $1$ 加減算に限定しなくても sum を unordered_map などでもつことによりギャグが可能)

空間計算量が破滅しがちなので、必要なところだけ領域を確保するように注意して実装している($O(Q)$ とかだと思う)。

## 計算量
* クエリ $O(\sqrt N)$


## 実装例
* SqrtDecomposition($N$, $L=0$):= テンプレートの $T$ は値の型、$E$ は高さの型。要素数 $N$ の列で初期化する。初期の高さと値は全て $0$ である。$L$ は query_low を投げるときに指定する。
* set($k$, $x$):= 要素 $k$ に $x$ を格納する。
* add($a$, $b$):= 区間 $[a, b)$ に $1$ を加算する。
* sub($a$, $b$):= 区間 $[a, b)$ に $1$ を減算する。
* query($a$, $b$, $x$):= 区間 $[a, b)$ の高さ $x$ にある要素の和を求める。
* query_low($a$, $b$):= 区間 $[a, b)$ の高さ $L$ 以上にある要素の和を求める。
* build($add$, $dat$):= 列の高さが $add$、値が $dat$ で初期化する。$add$ が一様に高いけど変化が少ないみたいなときに使う(空間計算量はそのブロックでの高さの最大値-最小値になる)。

{% include read.html  code="structure/sqrt-decomposition.cpp" %}

## 検証
[AtCoder 早稲田大学プログラミングコンテスト2019 D - Choose Your Characters](https://atcoder.jp/contests/wupc2019/tasks/wupc2019_d)
{% include read.html code="structure/verify/atcoder-wupc-2019-d.cpp" %}

