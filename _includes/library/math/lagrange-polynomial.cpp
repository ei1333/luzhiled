template< typename T >
T lagrange_polynomial(const vector< T > &y, int64_t t) {
  int N = y.size() - 1;
  Combination< T > comb(N);
  if(t <= N) return y[t];
  T num(1), ret(0);
  for(int i = 0; i <= N; i++) {
    T tmp = y[i] / (t - i) * comb.rfact(i) * comb.rfact(N - i);
    if((N - i) & 1) ret -= tmp;
    else ret += tmp;
    num *= t - i;
  }
  return ret * num;
}
