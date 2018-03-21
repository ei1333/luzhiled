---
layout: post
title: テンプレート
date: 2018-03-18
author: ei1333
math: true
category: グラフ
---

## 説明
グラフを扱うときのテンプレートである。


## 実装例

* edge := 重み付き辺
* Edges := 重み付き辺集合
* WeightedGraph := 重み付きグラフ
* UnWeightedGraph := 重みなしグラフ
* Matrix := 距離行列

```cpp
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
```
