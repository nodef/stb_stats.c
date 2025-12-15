#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int compare_doubles(const void *a, const void *b) {
  double arg1 = *(const double *)a;
  double arg2 = *(const double *)b;
  if (arg1 < arg2)
    return -1;
  if (arg1 > arg2)
    return 1;
  return 0;
}


int main() {
  double data[] = {5.5, 2.2, 9.9, 1.1, 4.4};
  size_t n = sizeof(data) / sizeof(data[0]);

  printf("Original: ");
  for (size_t i = 0; i < n; ++i)
    printf("%.1f ", data[i]);
  printf("\n");

  // Corrected usage: stb_qsort is a macro that takes the array, length, element
  // size, and compare function
  stb_qsort(data, n, sizeof(double), compare_doubles);

  printf("Sorted:   ");
  for (size_t i = 0; i < n; ++i)
    printf("%.1f ", data[i]);
  printf("\n");

  return 0;
}
