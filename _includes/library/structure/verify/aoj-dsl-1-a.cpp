int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  UnionFind uf(N);
  while(Q--) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    if(t == 0) uf.unite(x, y);
    else printf("%d\n", uf.find(x) == uf.find(y));
  }
}
