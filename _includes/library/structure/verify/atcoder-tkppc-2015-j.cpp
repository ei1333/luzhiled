template< typename T >
struct Farthest {
  T key;
  multiset< T > md;

  T p_max, c_max, length;

  Farthest() : p_max(-infll), c_max(-infll), length(0) {}

  void set(const T &k) {
    key = p_max = c_max = length = k;
  }

  void merge(const Farthest &parent, const Farthest &child) {
    p_max = max(parent.p_max, parent.length + key + max(md.size() ? *md.rbegin() : 0, child.p_max));
    c_max = max(child.c_max, child.length + key + max(md.size() ? *md.rbegin() : 0, parent.c_max));
    length = parent.length + key + child.length;
  }

  void reverse() {
    swap(p_max, c_max);
  }

  void insert_light(const Farthest &child) {
    md.emplace(child.p_max);
  }

  void erase_light(const Farthest &child) {
    md.erase(md.find(child.p_max));
  }
};

int main() {
  int Q;
  cin >> Q;

  using LCT = LinkCutTreeSubtree< Farthest< int64 >, int64 >;
  vector< LCT > ev(500001), ee(500001);
  ev[0].init(0);

  int num = 1;
  for(int i = 0; i < Q; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1) {
      ev[num].init(0);
      ee[num].init(b);
      ee[num].link(&ev[a]);
      ev[num].link(&ee[num]);
      ++num;
    } else if(t == 2) {
      ee[a].expose();
      ee[a].c.set(b);
      ee[a].update();
    } else {
      ev[a].evert();
      cout << ev[a].c.p_max << endl;
    }
  }
}
