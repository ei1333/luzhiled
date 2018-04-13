template< typename structure_t, typename get_t, typename update_t >
struct SegmentTree2D {
  using merge_f = function< get_t(get_t, get_t) >;
  using range_get_f = function< get_t(structure_t &, int, int) >;
  using update_f = function< get_t(structure_t &, int, update_t) >;

  int sz;
  vector< structure_t > seg;
  const merge_f &f;
  const range_get_f &g;
  const update_f &h;
  const get_t &identity;

  SegmentTree2D(int n, const merge_f &f, const range_get_f &g, const update_f &h, const get_t &identity)
      : f(f), g(g), h(h), identity(identity) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.resize(2 * sz - 1);
  }

  get_t query(int a, int b, int lower, int upper, int k, int l, int r) {
    if(r <= a || b <= l) {
      return identity;
    } else if(a <= l && r <= b) {
      return g(seg[k], lower, upper);
    } else {
      return f(query(a, b, lower, upper, 2 * k + 1, l, (l + r) >> 1),
               query(a, b, lower, upper, 2 * k + 2, (l + r) >> 1, r));
    }
  }

  int query(int a, int b, int l, int r) {
    return (query(a, b, l, r, 0, 0, sz));
  }

  void update(int x, int y, update_t z) {
    x += sz - 1;
    h(seg[x], y, z);
    while(x > 0) {
      x = (x - 1) >> 1;
      h(seg[x], y, z);
    }
  }
};
