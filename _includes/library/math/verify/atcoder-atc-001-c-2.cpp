int main() {
  int N;
  scanf("%d", &N);
  vector< int > A(N + 1), B(N + 1);
  for(int i = 0; i < N; i++) scanf("%d %d", &A[i + 1], &B[i + 1]);
  FastFourierTransform fft;
  auto C = fft.Multiply(A, B);
  for(int i = 1; i <= 2 * N; i++) printf("%lld\n", C[i]);
}

