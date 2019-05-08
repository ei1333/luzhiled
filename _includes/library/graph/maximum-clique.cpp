template< typename T >
T maximum_clique(Matrix< T > g) {
  T INF = numeric_limits< T >::max();

  int N = (int) g.size(), M = 0;
  vector< int > deg(N), v(N);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      assert(g[i][j] == g[j][i]);
      if(g[i][j] > 0) {
        ++deg[i];
        ++M;
      }
    }
  }
  int lim = (int) sqrt(M);
  T ret = 0;
  for(int i = 0; i < N; i++) {
    int root = -1;
    for(int j = 0; j < N; j++) {
      if(v[j]) continue;
      if(root == -1 || deg[j] < deg[root]) root = j;
    }
    vector< int > rots;
    for(int j = 0; j < N; j++) {
      if(j != root && g[root][j] > 0) rots.emplace_back(j);
    }
    if(rots.size() >= lim) {
      vector< int > rest;
      for(int j = 0; j < N; j++) {
        if(!v[j]) rest.emplace_back(j);
      }
      vector< vector< T > > dp(1 << rest.size(), vector< T >(rest.size(), INF));
      for(int j = 1; j < (1 << rest.size()); j++) {
        int add = __builtin_ctz(j);
        int base = j - (1 << add);
        if(base == 0) continue;
        T sum = 0;
        for(int k = add + 1; k < rest.size(); k++) {
          if((j >> k) & 1) {
            dp[j][add] = min(dp[j][add], g[rest[k]][rest[add]]);
            dp[j][k] = min(dp[base][k], g[rest[k]][rest[add]]);
            sum += dp[j][k];
          }
        }
        ret = max(ret, sum + dp[j][add]);
      }
      break;
    }
    vector< vector< T > > dp(1 << rots.size(), vector< T >(rots.size() + 1, INF));
    for(int j = 1; j < (1 << rots.size()); j++) {
      int add = __builtin_ctz(j);
      int base = j - (1 << add);
      T sum = 0;

      dp[j][add] = g[rots[add]][root];
      dp[j][rots.size()] = min(dp[base][rots.size()], dp[j][add]);

      for(int k = add + 1; k < rots.size(); k++) {
        if((j >> k) & 1) {
          dp[j][add] = min(dp[j][add], g[rots[k]][rots[add]]);
          dp[j][k] = min(dp[base][k], g[rots[k]][rots[add]]);
          sum += dp[j][k];
        }
      }
      ret = max(ret, sum + dp[j][add] + dp[j][rots.size()]);
    }

    v[root] = true;
    for(int j = 0; j < N; j++) {
      if(g[j][root] > 0) {
        --deg[j];
        g[root][j] = g[j][root] = 0;
      }
    }
  }
  return ret;
}

