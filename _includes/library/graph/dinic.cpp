template< typename cost_t >
struct Dinic {
  const cost_t INF;

  struct edge {
    int to;
    cost_t cap;
    int rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< cost_t > min_cost;
  vector< int > iter;

  Dinic(int V) : INF(numeric_limits< cost_t >::max()), graph(V) {}

  void add_edge(int from, int to, cost_t cap) {
    graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (int) graph[from].size() - 1, true});
  }

  bool bfs(int s, int t) {
    min_cost.assign(graph.size(), -1);
    queue< int > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  cost_t dfs(int idx, const int t, cost_t flow) {
    if(idx == t) return (flow);
    for(int &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
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
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      cost_t f = 0;
      while((f = dfs(s, t, INF)) > 0) {
        flow += f;
      }
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
