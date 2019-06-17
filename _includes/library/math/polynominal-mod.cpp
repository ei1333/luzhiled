template< typename T >
struct PolynominalMod : vector< T > {
  using vector< T >::vector;
  using P = PolynominalMod;
  static ArbitraryModConvolution< T > fft;

  P operator+(const P &r) const { return P(*this) += r; }

  P operator-(const P &r) const { return P(*this) -= r; }

  P operator*(const P &r) const { return P(*this) *= r; }

  P operator/(const P &r) const { return P(*this) /= r; }

  P &operator+=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  P &operator-=(const P &r) {
    if(r.size() > this->size()) this->resize(r.size());
    for(int i = 0; i < r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }

  P &operator*=(const P &r) {
    if(this->empty() || r.empty()) {
      this->clear();
      return *this;
    }
    auto ret = fft.multiply(*this, r);
    this->resize(ret.size());
    for(int k = 0; k < ret.size(); k++) (*this)[k] = ret[k];
    return *this;
  }

  P operator-() const {
    P ret(this->size());
    for(int i = 0; i < this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  P &operator/=(const P &r) {
    return *this *= r.inverse();
  }

  P inverse() const {
    const int n = (int) this->size();
    assert(n);
    P ret({T(1) / (*this)[0]});
    for(int k = 1; k < this->size(); k <<= 1) {
      P tmp(min(k << 1, n));
      for(int i = 0; i < tmp.size(); i++) tmp[i] = (*this)[i];
      P e = -(tmp * ret);
      e[0] += 2;
      ret *= e;
      ret.resize(tmp.size());
    }
    return ret;
  }
};
