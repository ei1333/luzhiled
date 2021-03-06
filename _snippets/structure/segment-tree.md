---
layout: post
title: セグメント木(Segment-Tree)
date: 2018-08-07
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
* find_first($a$, $check$) := $[a,x)$ が $check$ を満たす最初の要素位置 $x$ を返す。
* find_last($b$, $check$) := $[x,b)$ が $check$ を満たす最後の要素位置 $x$ を返す。

{% include read.html  code="structure/segment-tree.cpp" %}

## 検証
[AOJ DSL_2_A Range Minimum Query (RMQ)](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp)

{% include read.html  code="structure/verify/aoj-dsl-2-a.test.cpp" %}

## 応用 1: 遅延評価

遅延評価を用いることで特に区間に対する更新が可能になる。この場合はコンストラクタに対し追加で作用素モノイドの情報も与える。

* SegmentTree($n$, $f$, $g$, $h$, $M1$, $OM0$):= サイズ $n$ の初期化。ここで $f$ は2つの区間の要素をマージする二項演算, $g$ は要素と作用素をマージする二項演算(第三引数は対応する区間の長さ), $h$ は作用素同士をマージする二項演算, $M1$ はモノイドの単位元, $OM0$ は作用素の単位元である。
* update($a$, $b$, $x$) := 区間 $[a, b)$ に作用素 $x$ を適用する。

{% include read.html  code="structure/lazy-segment-tree.cpp" %}


## 応用 2: 2Dセグメント木
二次元平面上における点集合に対して, 求められる機能が {矩形内の点に対する更新, 一点取得} あるいは {矩形取得, 一点更新} であるとき, セグメント木のノードに区間に対するクエリを扱えるデータ構造を載せることで $1$ クエリあたり $O(\log^2 N)$ の 2Dセグメント木が実現可能である。

{矩形内の点に対する更新, 矩形取得} が必要な場合はセグメント木では不可能なので, 平方分割や平面走査などの別の手法を用いる必要がある。

ここでは{矩形取得, 一点更新} について実装例を示す。

* {矩形取得, 一点更新}
{% include read.html  code="structure/segment-tree-2d.cpp" %}

例えば矩形sum, 一点addの場合の使用例は次のとおりである。矩形sumを求めるときは横方向, 縦方向ともに半開区間で渡すと良い。

{% highlight cpp %}
using BIT = BinaryIndexedTree< int >;
auto f = [](int x, int y) { return x + y; };
auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
auto h = [](BIT &k, int x, int y) { k.add(x, y); };

SegmentTree2DCompressed< BIT, int, int > seg(100002, f, g, h, 0);
{% endhighlight %}


## 応用 4: Segment-Tree-Beats
{% include read.html  code="structure/segment-tree-beats.cpp" %}

## 応用 5: 双対セグメント木
{% include read.html  code="structure/duel-segment-tree.cpp" %}

## 応用 6: 永続セグメント木
みんな大好き永続セグメント木。永続セグメント木は怖そうなイメージだが, 怖いのはメモリ計算量や定数倍くらい。セグメント木のある要素に対して何らかの更新を行うとする。ここで更新後のセグメント木をすべてコピーして残しておくことが永続であるが, これを単純に実装すると, $1$ 回のコピーに $O(N)$ かかってこわれてしまう。しかしよく考えなくても, $1$ 回の更新によって $O(\log N)$ 個のノードの情報しか変化しないので, 変化したノードの情報だけ新しくノードを生成してその部分のみ張り替えるする操作を行えば $O(\log N)$ でのコピーが可能になり, これは一般のセグメント木の計算量と変わらない。

* PersistentSegmentTree($f$, $M1$):= コンストラクタ。$f$ は2つの区間の要素をマージする二項演算, $M1$ はモノイドの単位元である。
* build($v$) := 配列 $v$ を各要素としたセグメント木を構築し, その根を返す。
* update($t$, $k$, $x$) := $t$ を根とするセグメント木に対し $k$ 番目の要素を $x$ に更新し, 更新後の根を返す。
* query($t$, $a$, $b$) := $t$ を根とするセグメント木に対し, 区間 $[a, b)$ の要素を二項演算した結果を返す。

{% include read.html  code="structure/persistent-segment-tree.cpp" %}
