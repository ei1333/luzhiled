template< typename G >
struct CentroidDecomposition {
  const G &g;
  vector< int > sub;
  vector< bool > v;

  CentroidDecomposition(const G &g) : g(g), sub(g.size()), v(g.size()) {}

  inline int build_dfs(int idx, int par) {
    sub[idx] = 1;
    for(auto &to : g[idx]) {
      if(to == par || v[to]) continue;
      sub[idx] += build_dfs(to, idx);
    }
    return (sub[idx]);
  }

  inline int search_centroid(int idx, int par, const int mid) {
    for(auto &to : g[idx]) {
      if(to == par || v[to]) continue;
      if(sub[to] > mid) return search_centroid(to, idx, mid);
    }
    return (idx);
  }

  inline void centroid_decomp(int idx, const function< void(int) > &beet) {
    int centroid = search_centroid(idx, -1, build_dfs(idx, -1) / 2);
    beet(centroid);
    v[centroid] = true;
    for(auto &to : g[centroid]) if(!v[to]) centroid_decomp(to, beet);
  }

  inline bool killed(int idx) {
    return v[idx];
  }
};
