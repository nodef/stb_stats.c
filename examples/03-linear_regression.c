#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  // y = 2x + 1
  double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double y[] = {3.1, 4.9, 7.2, 8.9, 11.1}; // with some noise
  int n = sizeof(x) / sizeof(x[0]);

  double a, b, r;
  stb_linfit(x, y, n, &a, &b, &r);

  printf("Linear Regression (y = ax + b)\n");
  printf("Points:\n");
  for (int i = 0; i < n; ++i) {
    printf("(%.1f, %.1f) ", x[i], y[i]);
  }
  printf("\n");

  printf("Estimated Slope (a): %.4f\n", a);
  printf("Estimated Intercept (b): %.4f\n", b);
  printf("Correlation Coefficient (r): %.4f\n", r);

  return 0;
}
