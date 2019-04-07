template< typename T >
T bell_number(int n) {
  Combination< T > table(n);
  vector< T > subfactorial(n + 1);
  subfactorial[0] = 1;
  for(int i = 2; i <= n; i++) {
    subfactorial[i] = (subfactorial[i - 1] + subfactorial[i - 2]) * (i - 1);
  }
  auto ret = 0;
  for(int m = 0; m <= n; m++) {
    auto add = (T(m) ^ n) * subfactorial[n - m];
    add *= table.rfact(m);
    add *= table.rfact(n - m);
    ret += add;
  }
  return ret;
}
