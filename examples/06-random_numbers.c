#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>
#include <time.h>


int main() {
  uint64_t seed = (uint64_t)time(NULL);
  stb_spcg32(seed); // Seed the PRNG

  printf("Random Numbers (PCG32):\n");
  for (int i = 0; i < 5; ++i) {
    printf("%u\n", stb_pcg32(&seed));
  }

  printf("\nGaussian Random Numbers (Mean 0, StdDev 1):\n");
  for (int i = 0; i < 5; ++i) {
    printf("%.4f\n", stb_pcg32_gauss(&seed));
  }

  printf("\nGaussian Random Numbers (Mean 10, StdDev 2):\n");
  for (int i = 0; i < 5; ++i) {
    printf("%.4f\n", stb_pcg32_gauss_msd(&seed, 10.0, 2.0));
  }

  return 0;
}
