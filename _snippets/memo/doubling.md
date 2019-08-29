---
layout: post
title: ダブリング
date: 2018-12-28
category: メモ
---

## 概要
全要素について, 次の要素が容易に計算できるとき $x_i$ 個先の要素を求めるクエリに対して, 前計算 $(N \log N)$, クエリ $(\log N)$ で求めることができる。

前計算では $\mathrm{table}[k][i]$ に対して $i$ 番目の要素の $2^k$ 個次の要素を格納する(存在しないとき $-1$)。

位置 $p_i$ から $x_i$ 個先の要素を求めるクエリに答える際には, $x_i$ を二進展開して考える。上位 bit から見ていって, $k$ 桁目の bit  が $1$ のとき $2^k$ 次の要素に進むことを繰り返す。この $1$ 回ぶんの操作は$p_i = \mathrm{table}[k][p_i]$ をすることで行える。

{% highlight cpp %}
struct Doubling
{
  const int LOG;
  vector< vector< int > > table;
  
  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
  {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int k, int64_t t)
  {
    for(int i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
    }
    return k;
  }
};
{% endhighlight %}


単純に $x_i$ 個先の要素を求めるだけではなくて, 現在位置から $x_i$ 個先までの要素の総和や, $x_i$ 個先までの要素のうちの min などを求めたいときがある。ここでは総和を求める例を考える。この場合は前計算によって $\mathrm{table}[k][i]$ を埋めた後に, $\mathrm{sum}[k][i] := $ $[i, i + 2^k)$ の総和を埋める計算を行う。$\mathrm{sum}[0][i]$ に $i$ 番目の要素の値を格納してあるとすると, $\mathrm{sum}[k+1][i]$ は $\mathrm{sum}[k][i]$ (つまり $[i, i+2^k)$) に $\mathrm{sum}[k][\mathrm{table}[k][i]]$ (つまり $[i+2^k, i+2^k+2^k=i+2^{k+1})$) を加えたものなので, これをいい感じの順序で計算すればよい。クエリに答える時は, $p_i = table[k][p_i]$ をするとき合計に $\mathrm{sum}[k][p_i]$ を加えることで求められる。

またダブリング配列を使った二分探索も同じ計算量で行える。位置 $p_i$ からで合計が $s_i$ 以下であるような最大の $x_i$ を求めたいとする。上位 bit から見ていって, $\mathrm{sum}[k][p_i]$ が $s_i$ 未満であるとき $s_i$ から $\mathrm{sum}[k][p_i]$ をひいて $p_i = \mathrm{table}[k][p_i]$ として次に移動することを繰り返せばよい。次に移動したときの bit を保存していくと最終的なそれが最大の $x_i$ である。

ダブリングを用いたLCAも同じような二分探索をしている。まず頂点 $u, v$ のLCAを求める。ここで $d_i$ を頂点 $i$ の深さとし, $d_u \le d_v$ を仮定する($d_u \gt d_v$ のときは swap すればよい)。まず $d_v$ を $d_v - d_u$ 個だけ親に遡らせて深さを合わせる。ここで $d_v$ が $d_u$ と一致したらそれが LCA。それ以外のときは, 上位bit から $u, v$ 双方の $2^k$ 先の親が異なれば共に遡ることを繰り返して, 双方の親ではない直前の頂点を求める。するとその親がLCAとなる。

{% include read.html code="tree/doubling-lowest-common-ancestor.cpp" %}

