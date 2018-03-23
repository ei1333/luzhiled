template< typename cost_t >
struct FordFulkerson {
  struct edge {
    int to;
    cost_t cap;
    int rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< int > used;
  const cost_t INF;
  int timestamp;

  FordFulkerson(int n) : INF(numeric_limits< cost_t >::max()), timestamp(0) {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(int from, int to, cost_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
  }

  cost_t dfs(int idx, const int t, cost_t flow) {
    if(idx == t) return flow;
    used[idx] = timestamp;
    for(auto &e : graph[idx]) {
      if(e.cap > 0 && used[e.to] != timestamp) {
        cost_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  cost_t max_flow(int s, int t) {
    cost_t flow = 0;
    for(cost_t f; (f = dfs(s, t, INF)) > 0; timestamp++) {
      flow += f;
    }
    return flow;
  }

  void output() {
    for(int i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

