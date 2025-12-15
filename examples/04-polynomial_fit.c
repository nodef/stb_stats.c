#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
  double x[] = {1, 2, 3, 4, 5};
  double y[] = {1.2, 3.8, 9.1, 15.8, 26.0}; // Approximately y = x^2
  int N = sizeof(x) / sizeof(x[0]);
  int degree = 2; // Quadratic fit

  printf("Polynomial Fit (Degree %d)\n", degree);
  printf("Points:\n");
  for (int i = 0; i < N; ++i) {
    printf("(%.1f, %.1f) ", x[i], y[i]);
  }
  printf("\n");

  // Returns array of coefficients: c[0] + c[1]*x + c[2]*x^2 + ...
  double *coeffs = stb_polyfit(x, y, N, degree);

  if (coeffs) {
    printf("Fitted Polynomial: y = %.4f + %.4f*x + %.4f*x^2\n", coeffs[0],
           coeffs[1], coeffs[2]);
    free(coeffs);
  } else {
    printf("Fitting failed.\n");
  }

  return 0;
}
