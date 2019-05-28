---
layout: post
title: Monotone-Minima
date: 2019-05-29
category: 動的計画法
---

## 説明
$2$ 変数関数 $f(i, j) (0 \leq i \lt H, 0 \leq j \lt W)$ が Monotone であるとは、すべての $k$ に対して $\mathrm{argmin} f(k, *) \leq \mathrm{argmin} f(k + 1, *)$ を満たすことをいう。つまり各行の最小値をとる位置が右下に単調に下がっていることを意味する。

Monge $\Rightarrow$ Totally Monotone(TM) $\Rightarrow$ Monotone なので、Monotone は弱い条件である。

## 計算量
* $O((H + W) \log H)$

## 実装例
* monotone_minima($H$, $W$, $f$, $comp$): 各行について、最小値をとる位置と最小値をペアで返す。$f$ は $2$ 変数関数。

{% include read.html  code="dp/monotone-minima.cpp" %}

## 検証
[AtCoder COLOCON -Colopl programming contest 2018- Final C - スペースエクスプローラー高橋君](https://atcoder.jp/contests/colopl2018-final/tasks/colopl2018_final_c)
{% include read.html code="dp/verify/atcoder-colopl2018-final-c.cpp" %}

## 応用: オンライン・オフライン変換
[動的計画法高速化テクニック（オフライン・オンライン変換）- Qiita](https://qiita.com/tmaehara/items/0687af2cfb807cde7860)

$dp[j] = \min \\{ dp[i] + f(i,j) : i \in [0,j) \\}$ (例: $f(i,j)$ を区間 $[i,j)$ のコストとすると、区間[0, j) を任意個に分割するときの最小コスト) を考える。

愚直にDPをすると $O(N^2)$ かかるが、最小値をとる位置 $i$ が、 $j$ の増加にしたがって単調増加する場合 $O(N \log^2 N)$ で解くことができる。

区間 $[l, r)$ の dp 配列を埋めたい。$m = \frac {l + r} 2$ とする。
遷移するときに $m$ をまたがないものは分割して再帰的に解くことにすると、$m$ をまたぐものだけを考えれば良い。$[l, m)$ の dp 配列の値はわかり、それ以前の dp の計算結果に依存しない形となる。つまり $2$ 変数関数 $g(j, i) = dp[i] + f(i, j) (l \le i \lt m, m \leq j \lt r)$ を定義できて、Monotone-Minima を用いて効率的に解くことができる。(日本語むずかしい　こまった）(分割統治FFTも同じ考え方なので下のコードのinduceの部分をFFTにするとできると思う)

* online_offline_dp($N$, $f$, $comp$): 長さ $N + 1$ の dp 配列($dp[j]:=$ 区間 $[0, j)$ を任意個に分割するときのコスト) を返す。$f(i, j)$ は区間 $[i, j)$ のコストを与える $2$ 変数関数($0 \leq i \lt j \leq N$ を満たす範囲で定義されていればよい)。
{% include read.html  code="dp/online-offline-dp.cpp" %}

[yukicoder No.705 ゴミ拾い Hard](https://yukicoder.me/problems/no/705)
{% include read.html code="dp/verify/yukicoder-715.cpp" %}

