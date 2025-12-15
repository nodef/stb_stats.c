#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


int main() {
  // Generate some data normally distributed around 10
  double data[100];
  for (int i = 0; i < 100; ++i) {
    // Simple mock data for demo purposes,
    // in real usage use actual data or RNG
    data[i] = 10.0 + (i % 20 - 10) * 0.5;
    if (i % 5 == 0)
      data[i] += 5.0; // Add some outliers
  }

  // Create a histogram with automatic binning
  struct stb_hist *hist =
      stb_histogram(data, 100, -2, 0, 0); // -2 for Rice rule

  if (hist) {
    printf("Histogram (Bins: %d, Width: %.2f)\n", hist->number_of_bins,
           hist->bin_width);

    stb_print_histogram(hist);

    stb_free_histogram(hist);
  } else {
    printf("Failed to create histogram.\n");
  }

  return 0;
}
