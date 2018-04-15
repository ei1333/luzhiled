int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  UnWeightedGraph g(N);
  for(int i = 0; i < M; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  TwoEdgeConnectedComponents< UnWeightedGraph > bcc(g);
  UnWeightedGraph t;
  bcc.build(t);
  DoublingLowestCommonAncestor< UnWeightedGraph > lca(t);
  lca.build();
  int Q;
  scanf("%d", &Q);
  auto getdist = [&](int x, int y) {
    return lca.dep[x] + lca.dep[y] - 2 * lca.dep[lca.query(x, y)];
  };
  while(Q--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a = bcc[--a], b = bcc[--b], c = bcc[--c];
    if(getdist(a, c) == getdist(a, b) + getdist(b, c)) puts("OK");
    else puts("NG");
  }
}
