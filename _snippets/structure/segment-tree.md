---
layout: post
title: セグメント木(Segment-Tree)
date: 2018-03-18
author: ei1333
category: データ構造
---

## 説明
完全二分木である。モノイドに対する区間への様々な演算が $O(\log N)$ で実現できる。

モノイドは次の条件を満たす代数的構造である。

* 結合率を満たす。つまり $S$ の各元 $a, b, c$ に対して, $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ が満たされる。
* 単位元をもつ。つまり $S$ の任意の元 $a$ をとってきたときに $a \cdot e = e \cdot a = a$ なる $e$ が存在する。

## 計算量
* 構築 $O(N)$
* クエリ $O(\log N)$

## 実装例
実装では木を 1-indexed の配列で表現している。ノード $k$ について, 親ノードは $\frac k 2$, 子ノードは $2k$, $2k+1$ である。

* SegmentTree($n$, $f$, $M1$):= サイズ $n$ の初期化。ここで $f$ は2つの区間の要素をマージする二項演算, $M1$ はモノイドの単位元である。
* set($k$, $x$):= $k$ 番目の要素に $x$ を代入する。
* build():= セグメント木を構築する。
* query($a$, $b$):= 区間 $[a, b)$ に対して二項演算した結果を返す。
* update($k$, $x$):= $k$ 番目の要素を $x$ に変更する。
* operator[$k$] := $k$ 番目の要素を返す。

```cpp
template< typename Monoid >
struct SegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
  }
 
  void build()
  {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x)
  {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b)
  {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const
  {
    return seg[k + sz];
  }
};
```

## 検証
[AOJ DSL_2_A Range Minimum Query (RMQ)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp)
```cpp
int main()
{
  int N, Q;
  scanf("%d %d", &N, &Q);
  SegmentTree< int > seg(N, [](int a, int b) { return min(a, b); }, INT_MAX);
  while(Q--) {
    int T, X, Y;
    scanf("%d %d %d", &T, &X, &Y);
    if(T == 0) seg.update(X, Y);
    else printf("%d\n", seg.query(X, Y + 1));
  }
}
```

## 応用 1: 遅延評価

遅延評価を用いることで特に区間に対する更新が可能になる。この場合はコンストラクタに対し追加で作用素モノイドの情報も与える。

* SegmentTree($n$, $f$, $g$, $h$, $p$, $M1$, $OM0$):= サイズ $n$ の初期化。ここで $f$ は2つの区間の要素をマージする二項演算, $g$ は要素と作用素をマージする二項演算, $h$ は作用素同士をマージする二項演算, $p$ は作用素を降ろすときに行う演算(第一引数は作用素のもとの値, 第二引数は降ろしたあとの区間の長さが与えられる), $M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
* update($a$, $b$, $x$) := 区間 $[a, b)$ に作用素 $x$ を適用する。

## 応用 2: 2Dセグメント木
セグメント木のノードに平衡二分探索木を載せることで, 二次元平面における点の追加削除と, 矩形内の点の個数を求めるクエリに答えられる2Dセグメント木が可能である。

計算量はクエリあたり $O(\log^2 N)$ だが, オフラインの場合であれば応用3のフラクショナルカスケーディングを用いることで $O(\log N)$ に落とすこともできる。

```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct SegmentTree
{
  int sz;
  vector< tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.resize(2 * sz - 1);
  }

  int query(int a, int b, int lower, int upper, int k, int l, int r)
  {
    if(a >= r || b <= l) {
      return (0);
    } else if(a <= l && r <= b) {
      return (seg[k].order_of_key(upper) - seg[k].order_of_key(lower));
    } else {
      return (query(a, b, lower, upper, 2 * k + 1, l, (l + r) >> 1) + query(a, b, lower, upper, 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r)
  {
    return (query(a, b, l, r, 0, 0, sz));
  }

  void update(int k, int x, bool type)
  {
    k += sz - 1;
    if(type) seg[k].insert(x);
    else seg[k].erase(x);
    while(k > 0) {
      k = (k - 1) >> 1;
      if(type) seg[k].insert(x);
      else seg[k].erase(x);
    }
  }
};
```

## 応用3: フラクショナルカスケーディング
オフラインの場合に, 二分探索を効率化するための補助的な配列を前計算することで二次元矩形クエリを $O(\log N)$ で答えることができる。

```cpp
struct SegmentTreeFractionalCascading
{
  vector< vector< int > > seg;
  vector< vector< int > > LL, RR;
  int sz;

  SegmentTreeFractionalCascading(vector< int > &array)
  {
    sz = 1;
    while(sz < array.size()) sz <<= 1;
    seg.resize(2 * sz - 1);
    LL.resize(2 * sz - 1);
    RR.resize(2 * sz - 1);
    for(int k = 0; k < array.size(); k++) {
      seg[k + sz - 1].emplace_back(array[k]);
    }
    for(int k = sz - 2; k >= 0; k--) {
      seg[k].resize(seg[2 * k + 1].size() + seg[2 * k + 2].size());
      LL[k].resize(seg[k].size() + 1);
      RR[k].resize(seg[k].size() + 1);
      merge(begin(seg[2 * k + 1]), end(seg[2 * k + 1]), begin(seg[2 * k + 2]), end(seg[2 * k + 2]), begin(seg[k]));
      int tail1 = 0, tail2 = 0;
      for(int i = 0; i < seg[k].size(); i++) {
        while(tail1 < seg[2 * k + 1].size() && seg[2 * k + 1][tail1] < seg[k][i]) ++tail1;
        while(tail2 < seg[2 * k + 2].size() && seg[2 * k + 2][tail2] < seg[k][i]) ++tail2;
        LL[k][i] = tail1, RR[k][i] = tail2;
      }
      LL[k][seg[k].size()] = (int) seg[2 * k + 1].size();
      RR[k][seg[k].size()] = (int) seg[2 * k + 2].size();
    }
  }

  int query(int a, int b, int lower, int upper, int k, int l, int r)
  {
    if(a >= r || b <= l) {
      return (0);
    } else if(a <= l && r <= b) {
      return (upper - lower);
    } else {
      return (query(a, b, LL[k][lower], LL[k][upper], 2 * k + 1, l, (l + r) >> 1) + query(a, b, RR[k][lower], RR[k][upper], 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r)
  {
    l = lower_bound(begin(seg[0]), end(seg[0]), l) - begin(seg[0]);
    r = lower_bound(begin(seg[0]), end(seg[0]), r) - begin(seg[0]);
    return (query(a, b, l, r, 0, 0, sz));
  }
};
```

## 応用 4: 二分探索
セグメント木 + 二分探索は愚直に実装すると $O(\log^2 N)$ かかるが, ほとんどの場合はセグメント木上を二分探索することで $O(\log N)$ に落とすことができる。

## 応用 5: 永続セグメント木
みんな大好き永続セグメント木。永続セグメント木は怖そうなイメージだが, 怖いのはメモリ計算量や定数倍くらい。セグメント木のある要素に対して何らかの更新を行うとする。ここで更新後のセグメント木をすべてコピーして残しておくことが永続であるが, これを単純に実装すると, $1$ 回のコピーに $O(N)$ かかってこわれてしまう。しかしよく考えなくても, $1$ 回の更新によって $O(\log N)$ 個のノードの情報しか変化しないので, 変化したノードの情報だけ新しくノードを生成してその部分のみ張り替えるする操作を行えば $O(\log N)$ でのコピーが可能になり, これは一般のセグメント木の計算量と変わらない。

* PersistentSegmentTree($f$, $M1$):= コンストラクタ。$f$ は2つの区間の要素をマージする二項演算, $M1$ はモノイドの単位元である。
* build($v$) := 配列 $v$ を各要素としたセグメント木を構築し, その根を返す。
* update($t$, $k$, $x$) := $t$ を根とするセグメント木に対し $k$ 番目の要素を $x$ に更新し, 更新後の根を返す。
* query($t$, $a$, $b$) := $t$ を根とするセグメント木に対し, 区間 $[a, b)$ の要素を二項演算した結果を返す。

```cpp
template< typename Monoid >
struct PersistentSegmentTree
{
  using F = function< Monoid(Monoid, Monoid) >;
 
  struct Node
  {
    Monoid data;
    Node *l, *r;
 
    Node(const Monoid &data) : data(data) {}
  };
 
 
  int sz;
  const F f;
  const Monoid M1;
 
  PersistentSegmentTree(const F f, const Monoid &M1) : f(f), M1(M1) {}
 
  Node *build(vector< Monoid > &v)
  {
    sz = (int) v.size();
    return build(0, (int) v.size(), v);
  }
 
  Node *merge(Node *l, Node *r)
  {
    auto t = new Node(f(l->data, r->data));
    t->l = l;
    t->r = r;
    return t;
  }
 
  Node *build(int l, int r, vector< Monoid > &v)
  {
    if(l + 1 >= r) return new Node(v[l]);
    return merge(build(l, (l + r) >> 1, v), build((l + r) >> 1, r, v));
  }
 
  Node *update(int a, const Monoid &x, Node *k, int l, int r)
  {
    if(r <= a || a + 1 <= l) {
      return k;
    } else if(a <= l && r <= a + 1) {
      return new Node(x);
    } else {
      return merge(update(a, x, k->l, l, (l + r) >> 1), update(a, x, k->r, (l + r) >> 1, r));
    }
  }
 
  Node *update(Node *t, int k, const Monoid &x)
  {
    return update(k, x, t, 0, sz);
  }
 
  Monoid query(int a, int b, Node *k, int l, int r)
  {
    if(r <= a || b <= l || !k) {
      return M1;
    } else if(a <= l && r <= b) {
      return k->data;
    } else {
      return f(query(a, b, k->l, l, (l + r) >> 1),
               query(a, b, k->r, (l + r) >> 1, r));
    }
  }
 
  Monoid query(Node *t, int a, int b)
  {
    return query(a, b, t, 0, sz);
  }
};
```
