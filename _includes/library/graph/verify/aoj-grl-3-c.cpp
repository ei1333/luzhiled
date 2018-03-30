int main() {
  int V, E, Q;
  scanf("%d %d", &V, &E);
  UnWeightedGraph g(V), buff;
  for(int i = 0; i < E; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
  }
  StronglyConnectedComponents< UnWeightedGraph > scc(g);
  scc.build(buff);
  scanf("%d", &Q);
  while(Q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    puts(scc[a] == scc[b] ? "1" : "0");
  }
}
