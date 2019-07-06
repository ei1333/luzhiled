template< typename C, typename D >
struct LinkCutTreeSubtree {
  using LCT = LinkCutTreeSubtree;

  LCT *l, *r, *p;
  C c;
  bool rev;
  int sz;

  bool is_root() {
    return !p || (p->l != this && p->r != this);
  }

  LinkCutTreeSubtree() = default;

  LinkCutTreeSubtree(const D &v) { init(v); }

  void init(const D &v) {
    sz = 1;
    l = r = p = nullptr;
    rev = false;
    c.set(v);
  }

  void toggle() {
    swap(l, r);
    c.reverse();
    rev ^= true;
  }

  void push() {
    if(rev) {
      if(l) l->toggle();
      if(r) r->toggle();
      rev = false;
    }
  }

  void update() {
    sz = 1;
    if(l) sz += l->sz;
    if(r) sz += r->sz;
    c.merge(l ? l->c : C(), r ? r->c : C());
  }


  void rotr() {
    auto *x = p, *y = x->p;
    if((x->l = r)) r->p = x;
    r = x, x->p = this;
    x->update(), update();
    if((p = y)) {
      if(y->l == x) y->l = this;
      if(y->r == x) y->r = this;
      y->update();
    }
  }

  void rotl() {
    auto *x = p, *y = x->p;
    if((x->r = l)) l->p = x;
    l = x, x->p = this;
    x->update(), update();
    if((p = y)) {
      if(y->l == x) y->l = this;
      if(y->r == x) y->r = this;
      y->update();
    }
  }

  void splay() {
    push();
    while(!is_root()) {
      auto *q = p;
      if(q->is_root()) {
        q->push(), push();
        if(q->l == this) rotr();
        else rotl();
      } else {
        auto *r = q->p;
        r->push(), q->push(), push();
        if(r->l == q) {
          if(q->l == this) q->rotr(), rotr();
          else rotl(), rotr();
        } else {
          if(q->r == this) q->rotl(), rotl();
          else rotr(), rotl();
        }
      }
    }
  }

  LCT *expose() {
    LCT *rp = nullptr;
    for(auto *cur = this; cur; cur = cur->p) {
      cur->splay();
      if(cur->r) cur->c.insert_light(cur->r->c);
      cur->r = rp;
      if(cur->r) cur->c.erase_light(cur->r->c);
      cur->update();
      rp = cur;
    }
    splay();
    return rp;
  }

  void link(LCT *parent) {
    expose();
    parent->expose();
    p = parent;
    parent->r = this;
    parent->update();
  }

  void cut() {
    expose();
    auto *parent = l;
    l = nullptr;
    parent->p = nullptr;
    update();
  }

  void evert() {
    expose();
    toggle();
    push();
  }

  LCT *lca(LCT *v) {
    expose();
    return v->expose();
  }

  LCT *get_kth(int k) {
    expose();
    LCT x = this;
    while(x) {
      x.push();
      if(x->r && x->r->sz > k) {
        x = x->r;
      } else {
        if(x->r) k -= x->r->sz;
        if(k == 0) return x;
        k -= 1;
        x = x->l;
      }
    }
    return nullptr;
  }

  LCT *get_root() {
    expose();
    LCT *x = this;
    while(x->l) {
      x->push();
      x = x->l;
    }
    x->splay();
    return x;
  }

  C query() {
    expose();
    return c;
  }
};

