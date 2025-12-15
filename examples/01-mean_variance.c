#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  int n = sizeof(data) / sizeof(data[0]);
  double mean, variance;

  stb_meanvar(data, n, &mean, &variance);

  printf("Data: ");
  for (int i = 0; i < n; ++i)
    printf("%.1f ", data[i]);
  printf("\n");

  printf("Mean: %.4f\n", mean);
  printf("Variance: %.4f\n", variance);

  return 0;
}
