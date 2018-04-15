template< typename G >
struct TwoEdgeConnectedComponents : LowLink< G > {
  using LL = LowLink< G >;
  vector< int > comp;

  TwoEdgeConnectedComponents(const G &g) : LL(g), comp(g.size(), -1) {}

  int operator[](const int &k) {
    return comp[k];
  }

  void build(UnWeightedGraph &t) {
    LL::build();
    int k = 0;
    function< void(int, int) > dfs = [&](int idx, int par) {
      if(~par && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
      else comp[idx] = k++;
      for(auto &to : this->g[idx]) {
        if(comp[to] == -1) dfs(to, idx);
      }
    };
    dfs(0, -1);
    t.resize(k);
    for(auto &e : this->bridge) {
      int x = comp[e.first], y = comp[e.second];
      t[x].push_back(y);
      t[y].push_back(x);
    }
  }
};
