---
layout: post
title: 橋/関節点(LowLink)
date: 2018-04-15
category: グラフ
---

## 説明
橋や関節点などを効率的に求める際に有効なアルゴリズム。

グラフをDFSして, ord[$idx$] := DFS で頂点に訪れた順番, low[$idx$] := 頂点 $idx$ からDFS木の葉方向の辺を $0$ 回以上, 後退辺を $1$ 回以下通って到達可能な頂点の $ord$ の最小値 を各頂点について求める。

ある頂点 $u$ が関節点であるとき, DFS木の根については子が $2$ つ以上, それ以外の頂点については 頂点 $u$ のある子 $v$ について ord[$u$] $\le$ low[$v$] を満たす。 

ある辺 $(u, v)$ が橋であるとき, ord[$u$] $\lt$ low[$v$] を満たす。

## 計算量
* $O(V)$

## 実装例

* LowLink($g$):= グラフ $g$ で初期化する。
* build():= グラフ $g$ に対する LowLink を構築する。構築後, articulation には関節点, bridge には橋が追加される。非連結でもOK。

{% include read.html  code="graph/lowlink.cpp" %}

## 検証

[AOJ GRL_3_A 関節点](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A)
{% include read.html code="graph/verify/aoj-grl-3-a.test.cpp" %}

[AOJ GRL_3_B 橋](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B)
{% include read.html code="graph/verify/aoj-grl-3-b.test.cpp" %}
