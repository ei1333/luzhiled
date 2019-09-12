---
layout: post
title: 最小流量制限付き最大流
date: 2019-04-06
category: グラフ
tags: 最大流
---

## 説明
流量の下限と上限が決まっているときの最大流。

## 計算量
* うく


## 実装例

* MaxFlowLowerBound($V$):= 頂点数 $V$ で初期化する。
* add_edge($from$, $to$, $low$, $high$):= 頂点 $from$ から $to$ に容量 $[low, high]$ の辺を張る。
* max_flow($s$, $t$):= 頂点 $s$ から $t$ に最大流を流し、その流量を返す。流せなかったとき $-1$。
* can_flow($s$, $t$):= 頂点 $s$ から $t$ に制約を満たせるように流せるか判定する。
* can_flow():= グラフに制約を満たす循環フロー(すべての点での流出量が流入量と等しい流れ)を流せるか判定する。
* min_flow($s$, $t$):= 頂点 $s$ から $t$ に最小流(制約を満たすもののうち最小の流量）を流し、その流量を返す。流せなかったとき $-1$。
* output($m$):= 流したフローを出力する。

{% include read.html  code="graph/maxflow-lower-bound.cpp" %}

## 検証

[AOJ1615 プレゼント交換会](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1615&lang=jp)
{% include read.html code="graph/verify/aoj1615.cpp" %}

## 参考
[最小流量制限付き最大流 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/10/043918)

