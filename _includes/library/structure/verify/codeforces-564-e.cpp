template< typename T >
struct tap {
  T key;

  T sz, szsum, cashsz, cashszsum;

  tap() : key(0), sz(0), szsum(0), cashsz(0), cashszsum(0) {}

  void set(const T &k) {
    sz = key = k;
  }

  void merge(const tap &parent, const tap &child) {
    szsum = cashszsum;
    szsum += parent.sz * parent.sz;
    szsum += child.sz * child.sz;

    sz = key;
    sz += parent.sz;
    sz += child.sz;
    sz += cashsz;
  }

  void reverse() {
  }

  void insert_light(const tap &child) {
    cashszsum += child.sz * child.sz;
    cashsz += child.sz;
  }

  void erase_light(const tap &child) {
    cashszsum -= child.sz * child.sz;
    cashsz -= child.sz;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  vector< int > C(N);
  cin >> C;

  using pi = pair< int64, int >;

  using LCT = LinkCutTreeSubtree< tap< int64 >, int64 >;
  vector< LCT > sub(N);
  vector< map< int, vector< pair< int, int > > > > belong(N + 1);
  for(int i = 0; i < N; i++) {
    --C[i];
    sub[i].init(1);
    belong[C[i]][-1].emplace_back(i, 0);
  }

  vector< int > parent(N + 1, -1);
  vector< int > g[400001];

  g[N].emplace_back(0);
  sub.emplace_back(LCT(1));

  function< void(int, int) > dfs = [&](int idx, int par) {
    parent[idx] = par;
    for(auto &to : g[idx]) {
      if(to == par) continue;
      dfs(to, idx);
    }
  };
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    sub[y].evert();
    sub[y].link(&sub[x]);
  }
  sub[0].evert();
  sub[0].link(&sub[N]);
  dfs(N, -1);

  for(int i = 0; i < M; i++) {
    int u, x;
    cin >> u >> x;
    --u, --x;
    if(C[u] != x) {
      belong[C[u]][i].emplace_back(u, 1); // set black
      C[u] = x;
      belong[x][i].emplace_back(u, 0); // set white
    }
  }


  vector< int64 > ans(M + 1);


  for(int i = 0; i < N; i++) {

    int last = -1;
    int64 path = 1LL * N * N;

    set< int > st;

    for(auto &vs : belong[i]) {
      ans[last + 1] += path;
      ans[vs.first + 1] -= path;

      for(auto &p : vs.second) {
        if(!p.second) {
          st.emplace(p.first);
          path -= sub[p.first].get_root()->query().szsum;
          sub[p.first].cut();
          path += sub[parent[p.first]].get_root()->query().szsum;
          path += sub[p.first].get_root()->query().szsum;

        } else {
          st.erase(p.first);
          path -= sub[p.first].get_root()->query().szsum;
          path -= sub[parent[p.first]].get_root()->query().szsum;
          sub[p.first].link(&sub[parent[p.first]]);
          path += sub[p.first].get_root()->query().szsum;
        }
      }
      last = vs.first;
    }
    ans[last + 1] += path;
    for(auto &p : st) sub[p].link(&sub[parent[p]]);

  }

  int64 ret = 0;
  for(int j = 0; j <= M; j++) {
    ret += ans[j];
    cout << 1LL * N * N * N - ret << endl;
  }
  cout << endl;

}

