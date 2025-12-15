#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double y[] = {5.0, 4.0, 3.0, 2.0, 1.0}; // Perfect negative correlation
  int n = sizeof(x) / sizeof(x[0]);

  printf("Dataset: \n");
  printf("X: ");
  for (int i = 0; i < n; ++i)
    printf("%.1f ", x[i]);
  printf("\n");
  printf("Y: ");
  for (int i = 0; i < n; ++i)
    printf("%.1f ", y[i]);
  printf("\n");

  // Spearman's Rank Correlation
  double rho = stb_spearman(x, y, n);
  printf("Spearman's Rho: %.4f\n", rho);

  // Kendall's Tau
  double tau, z, prob;
  double k_corr = stb_kendall(x, y, n, &tau, &z, &prob);
  printf("Kendall's Tau: %.4f (Probability: %.4f)\n", tau, prob);

  return 0;
}
