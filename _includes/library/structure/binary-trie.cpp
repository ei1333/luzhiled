template< typename T >
struct BinaryTrieNode {
  int nxt[2];
  T lazy;
  int exist; // 子ども以下に存在する文字列の数の合計
  vector< int > accept; // その文字列id

  BinaryTrieNode() : exist(0) {
    nxt[0] = nxt[1] = -1;
  }
};

template< typename T, int MAX_LOG >
struct BinaryTrie {

  using Node = BinaryTrieNode< T >;
  vector< Node > nodes;
  int root;

  BinaryTrie() : root(0) {
    nodes.push_back(Node());
  }

  void update_direct(int node, int id) {
    ++nodes[node].exist; //notice!!
    nodes[node].accept.push_back(id);
    direct_action(node, id);
  }

  void update_child(int node, int child, int id) {
    ++nodes[node].exist;
    child_action(node, child, id);
  }

  void add(const T &bit, int bit_index, int node_index, int id) {
    propagate(bit_index, node_index);
    if(bit_index == -1) {
      update_direct(node_index, id);
    } else {
      const int c = (bit >> bit_index) & 1;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(Node());
      }
      add(bit, bit_index - 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const T &bit, int id) {
    add(bit, MAX_LOG, 0, id);
  }

  void add(const T &bit) {
    add(bit, nodes[0].exist);
  }

  T max_query(T bit, int bit_index, int node_index) {
    if(bit_index == -1) return bit;
    propagate(bit_index, node_index);
    if(~nodes[node_index].nxt[1] && nodes[nodes[node_index].nxt[1]].exist) {
      return max_query(bit | (1LL << bit_index), bit_index - 1, nodes[node_index].nxt[1]);
    } else {
      return max_query(bit, bit_index - 1, nodes[node_index].nxt[0]);
    }
  }

  T min_query(T bit, int bit_index, int node_index) {
    if(bit_index == -1) return bit;
    propagate(bit_index, node_index);
    if(~nodes[node_index].nxt[0] && nodes[nodes[node_index].nxt[0]].exist) {
      return min_query(bit, bit_index - 1, nodes[node_index].nxt[0]);
    } else {
      return min_query(bit | (1LL << bit_index), bit_index - 1, nodes[node_index].nxt[1]);
    }
  }

  T mex_query(int bit_index, int node_index) { // distinct-values
    if(bit_index == -1 || node_index == -1) {
      return 0;
    } else {
      propagate(bit_index, node_index);
      if(~nodes[node_index].nxt[0] && nodes[nodes[node_index].nxt[0]].exist == (1LL << bit_index)) {
        return mex_query(bit_index - 1, nodes[node_index].nxt[1]) | (1LL << bit_index);
      } else {
        return mex_query(bit_index - 1, nodes[node_index].nxt[0]);
      }
    }
  }

  pair< T, int > max_query() {
    return max_query(0, MAX_LOG, 0);
  }

  T min_query() {
    return min_query(0, MAX_LOG, 0);
  }

  T mex_query() {
    return mex_query(MAX_LOG, 0);
  }

  int size() const {
    return (nodes[0].exist);
  }

  int nodesize() const {
    return ((int) nodes.size());
  }

  void xorpush(const T &bit) {
    nodes[0].lazy ^= bit;
  }

  void propagate(int bit_index, int node_index) {
    const int c = (nodes[node_index].lazy >> bit_index) & 1;
    if(c) swap(nodes[node_index].nxt[0], nodes[node_index].nxt[1]);
    if(~nodes[node_index].nxt[0]) nodes[nodes[node_index].nxt[0]].lazy ^= nodes[node_index].lazy;
    if(~nodes[node_index].nxt[1]) nodes[nodes[node_index].nxt[1]].lazy ^= nodes[node_index].lazy;
    nodes[node_index].lazy = 0;
  }
};
