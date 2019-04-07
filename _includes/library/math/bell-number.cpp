template< typename T >
T bell_number(int n, int k) {
  T ret = 0;
  for(int j = 1; j <= k; j++) ret += stirling_number_second< T >(n, j);
  return ret;
}

