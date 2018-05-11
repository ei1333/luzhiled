struct FastFourierTransform {
  using C = complex< double >;

  const double PI = acos(-1);
  vector< vector< C > > rts, rrts;

  void ensure_base(int N) {
    if(rts.size() >= N) return;
    rts.resize(N), rrts.resize(N);
    for(int i = 1; i < N; i <<= 1) {
      if(rts[i].size()) continue;
      rts[i].resize(i), rrts[i].resize(i);
      for(int k = 0; k < i; k++) {
        rts[i][k] = polar(1.0, PI / i * k);
        rrts[i][k] = polar(1.0, -PI / i * k);
      }
    }
  }

  void DiscreteFourierTransform(vector< C > &F, bool rev) {
    const int N = (int) F.size();
    auto &r = rev ? rrts : rts;

    for(int i = 0, j = 1; j + 1 < N; j++) {
      for(int k = N >> 1; k > (i ^= k); k >>= 1);
      if(i > j) swap(F[i], F[j]);
    }
    ensure_base(N);
    C s, t;
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          s = F[j + k];
          t = C(F[j + k + i].real() * r[i][k].real() - F[j + k + i].imag() * r[i][k].imag(),
                F[j + k + i].real() * r[i][k].imag() + F[j + k + i].imag() * r[i][k].real());
          F[j + k] = s + t, F[j + k + i] = s - t;
        }
      }
    }
    if(rev) for(int i = 0; i < N; i++) F[i] /= N;
  }

  vector< long long > Multiply(const vector< int > &A, const vector< int > &B) {
    int sz = 1;
    while(sz < A.size() + B.size() - 1) sz <<= 1;
    vector< C > F(sz), G(sz);
    for(int i = 0; i < A.size(); i++) F[i] = A[i];
    for(int i = 0; i < B.size(); i++) G[i] = B[i];
    DiscreteFourierTransform(F, false);
    DiscreteFourierTransform(G, false);
    for(int i = 0; i < sz; i++) F[i] *= G[i];
    DiscreteFourierTransform(F, true);
    vector< long long > X(A.size() + B.size() - 1);
    for(int i = 0; i < A.size() + B.size() - 1; i++) X[i] = F[i].real() + 0.5;
    return (X);
  }
};

