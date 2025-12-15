#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  double group1[] = {25.2, 23.4, 21.0, 22.5, 24.1};
  double group2[] = {18.0, 19.5, 20.1, 19.2, 18.9};
  int n1 = sizeof(group1) / sizeof(group1[0]);
  int n2 = sizeof(group2) / sizeof(group2[0]);

  double t, p;

  // t-test assuming equal variance
  stb_ttest(group1, n1, group2, n2, &t, &p);

  printf("Group 1: ");
  for (int i = 0; i < n1; ++i)
    printf("%.1f ", group1[i]);
  printf("\n");

  printf("Group 2: ");
  for (int i = 0; i < n2; ++i)
    printf("%.1f ", group2[i]);
  printf("\n");

  printf("T-Test (Equal Variance):\n");
  printf("t-statistic: %.4f\n", t);
  printf("p-value: %.4f\n", p);

  if (p < 0.05) {
    printf("Result: Significant difference between groups (p < 0.05)\n");
  } else {
    printf("Result: No significant difference (p >= 0.05)\n");
  }

  return 0;
}
