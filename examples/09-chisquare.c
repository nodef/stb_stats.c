#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  // Observed counts (e.g., dice rolls)
  double observed[] = {15.0, 18.0, 22.0, 14.0, 16.0, 15.0};
  int n = sizeof(observed) / sizeof(observed[0]);

  // Expected counts (fair die: 100 rolls / 6 sides = 16.66...)
  double expected[] = {16.67, 16.67, 16.67, 16.67, 16.67, 16.67};

  double chi_sq, p;

  // Using 1 row and n columns for a simple goodness of fit
  stb_chisqr(observed, expected, 1, n, &chi_sq, &p);

  printf("Chi-Square Goodness of Fit:\n");
  printf("Observed: ");
  for (int i = 0; i < n; ++i)
    printf("%.0f ", observed[i]);
  printf("\n");

  printf("Chi-Square Stat: %.4f\n", chi_sq);
  printf("p-value: %.4f\n", p);

  if (p < 0.05) {
    printf("Result: The die is biased (p < 0.05)\n");
  } else {
    printf("Result: The die is fair (p >= 0.05)\n");
  }

  return 0;
}
