#define STB_STATS_IMPLEMENTATION
#include <stb_stats.h>
#include <stdio.h>


// Define hash table for int key, int value
stb_create_htable(stb_ii_, int, int, it, l == r)


int main() {
  stb_ii_t t = stb_ii_new();

  printf("Hash Table Operations:\n");

  // Put values
  stb_ii_put(t, 1, 100);
  stb_ii_put(t, 2, 200);
  stb_ii_put(t, 3, 300);
  printf("Inserted 1->100, 2->200, 3->300\n");

  // Get values
  int val;
  if (stb_ii_get(t, 1, &val)) {
    printf("Get(1): %d\n", val);
  } else {
    printf("Get(1): Not found\n");
  }

  if (stb_ii_get(t, 4, &val)) {
    printf("Get(4): %d\n", val);
  } else {
    printf("Get(4): Not found\n");
  }

  // Iterate
  printf("Iterating:\n");
  for (size_t i = 0; i < stb_ii_bsize(t); i = stb_ii_nexti(t, i)) {
    printf("Key: %d, Value: %d\n", t->keys[i], t->values[i]);
  }

  stb_ii_free(t);
  return 0;
}
