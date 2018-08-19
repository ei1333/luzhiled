template< typename T >
struct PrioritySumStructure {
  static const bool INCREASE = false;
  static const bool DECREASE = true;

  bool order;
  int k, sz;
  T sum;
  set< pair< T, int > > add, pend;
  map< int, T > adding, pending;

  PrioritySumStructure(int k, bool order = INCREASE) : k(k), sum(0), sz(0), order(order) {}

  void sweep() {
    while(sz < k && !pend.empty()) {
      auto p = order ? --pend.end() : pend.begin();
      sum += p->first;
      ++sz;
      add.emplace(*p);
      adding.emplace(p->second, p->first);
      pending.erase(p->second);
      pend.erase(p);
    }
    while(sz > k) {
      auto p = order ? add.begin() : --add.end();
      sum -= p->first;
      --sz;
      pend.emplace(*p);
      pending.emplace(p->second, p->first);
      adding.erase(p->second);
      add.erase(p);
    }
  }

  T get_sum() {
    if(sz < k) throw ("Get Sum Exception");
    return sum;
  }

  void add_element(int k, T x) {
    if(adding.count(k) || pending.count(k)) {
      throw ("Add Element Exception");
    }
    ++sz;
    add.emplace(x, k);
    adding[k] = x;
    sum += x;
    sweep();
  }

  void delete_element(int k) {
    if(pending.count(k)) {
      pend.erase({pending[k], k});
      pending.erase(k);
    } else if(adding.count(k)) {
      --sz;
      sum -= adding[k];
      add.erase({adding[k], k});
      adding.erase(k);
      sweep();
    } else {
      throw ("Delete Element Exception");
    }
  }

  void increment_size() {
    ++k;
    sweep();
  }

  void decrement_size() {
    if(k == 0) throw ("Decrement Size Exception");
    --k;
    sweep();
  }
};
