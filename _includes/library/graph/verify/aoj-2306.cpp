int main() {
  int N, M;
  cin >> N >> M;
  Matrix< int > g(N, vector< int >(N));
  for(int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    g[x][y] = z;
    g[y][x] = z;
  }
  cout << maximum_clique(g) << endl;
}
