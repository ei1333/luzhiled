modint bell_number(int n) {
  Combination< modint > table(n);
  vector< modint > subfactorial(n + 1);
  subfactorial[0] = 1;
  for(int i = 2; i <= n; i++) {
    subfactorial[i] = (subfactorial[i - 1] + subfactorial[i - 2]) * (i - 1);
  }
  modint ret = 0;
  for(int m = 0; m <= n; m++) {
    modint add = (modint(m) ^ n) * subfactorial[n - m];
    add *= table.rfact(m);
    add *= table.rfact(n - m);
    ret += add;
  }
  return ret;
}
