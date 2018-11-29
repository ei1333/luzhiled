---
layout: post
title: 燃やす埋める問題
date: 2018-11-29
category: メモ
---

## 概要

以下の制約問題は最小カットで解くことが出来る。

* すべての頂点に $\\{0, 1\\}$ を割り当てる
* 頂点 $x_i$ が $0$ で頂点 $y_i$ が $1$ に割り当てられたとき $z_i$ 失う
* 失う重みの和の最小値を求めよ

この問題の解法は以下の通りである。

* 必ず $0$ が割り当てられる頂点 $S$, $1$ が割り当てられる頂点 $T$ を用意する
* 制約 $(x_i, y_i, z_i)$ がある → 頂点 $x_i$ から頂点 $y_i$ に容量 $z_i$ の辺を張る
* 頂点 $S$ から頂点 $T$ への最小カットを求める

また色々な制約を $(x, y, z)$ の形に変形することができる($w$ は新しい頂点を別に用意することを表す)。

| 変形前の制約 |  変形後の制約 |
| ------------ |  -----------  |
| $x$ が $0$ のとき $z$ 失う          | $(x, T, z)$ |
| $x$ が $0$ のとき $z$ 得る          | 無条件で $z$ 得る <br> $(S, x, z)$ |
| $x$ が $1$ のとき $z$ 失う          | $(S, x, z)$ |
| $x$ が $1$ のとき $z$ 得る          | 無条件で $z$ 得る <br> $(x, T, z)$ |
| $x, y$ がともに $0$ のとき $z$ 得る | 無条件で $z$ 得る <br> $(S, w, z)$ <br> $(w, x, \infty)$ <br> $(w, y, \infty)$ |
| $x, y$ がともに $1$ のとき $z$ 得る | 無条件で $z$ 得る <br> $(w, T, z)$ <br> $(x, w, \infty)$ <br> $(y, w, \infty)$ |

一方で以下の制約があるときは、解くことが基本的には難しい。グラフが $2$ 部グラフになっている場合は、一方の頂点の真理値を全て反転させることで、「$x$ が $0$ で $y$ が $1$ のときに $z$ 失う」場合に帰着できる場合がある。

| 変形前の制約 |  変形後の制約 |
| ------------ |  -----------  |
| $x, y$ がともに $0$ のとき $z$ 失う | - |
| $x, y$ がともに $1$ のとき $z$ 失う | - |


## 問題例
[Educational Codeforces Round 55 G. Petya and Graph](https://codeforces.com/contest/1082/problem/G)

> $N$ 頂点 $M$ 辺の単純グラフが与えられる。それぞれの頂点と辺には重み $a_i, w_i$ が割り当てられている。部分グラフの重みを(辺の重みの和)-(頂点の重みの和) と定義する。部分グラフの最大重みを求めよ。

それぞれの頂点に対して $1$ が割り当てられた時に部分グラフに使用すると定義する。

* 頂点 $i$ が $1$ のとき $a_i$ 失う
* 頂点 $v_i, u_i$ がともに $1$ のとき $w_i$ 得る

にしたがってグラフを構成すると、答えを求めることができる。

{% highlight cpp %}
#include<bits/stdc++.h>
using int64 = long long;
int main() {
  int N, M, A[1000];
  cin >> N >> M;
  Dinic< int64 > flow(N + M + 2);
  int S = N + M, T = N + M + 1;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    flow.add_edge(S, i, a);
  }
  for(int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    ret += c;
    flow.add_edge(i + N, T, c);
    flow.add_edge(a, i + N, flow.INF);
    flow.add_edge(b, i + N, flow.INF);
  }
  cout << ret - flow.max_flow(S,T) << endl;
}
{% endhighlight %}

## 参考
* [最小カットを使って「燃やす埋める問題」を解く - SlideShare](https://www.slideshare.net/shindannin/project-selection-problem)
* [最小カットについて - よすぽの日記](http://yosupo.hatenablog.com/entry/2015/03/31/134336)
* [燃やす埋める問題 - いかたこのたこつぼ](https://ikatakos.com/pot/programming_algorithm/graph_theory/maximum_flow/burn_bury_problem)
