int main() {
  int N, M;
  cin >> N >> M;
  Matrix< int > g(N, vector< int >(N));
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x][y] = 1;
    g[y][x] = 1;
  }
  cout << max(1, maximum_clique(g)) << endl;
}
