#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
URL="https://github.com/gerbenvoshol/Statistics-Tool-Box/raw/refs/heads/master/stb_stats.h"
mkdir -p stb_stats

# Download the release
if [ ! -f "stb_stats/stb_stats.h" ]; then
  echo "Downloading stb_stats.h from $URL ..."
  curl -L "$URL" -o "stb_stats/stb_stats.h"
  echo ""
fi
}


# Test the project
test() {
echo "Running 01-mean_variance.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 01.exe examples/01-mean_variance.c      && ./01 && echo -e "\n"
echo "Running 02-ttest.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 02.exe examples/02-ttest.c              && ./02 && echo -e "\n"
echo "Running 03-linear_regression.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 03.exe examples/03-linear_regression.c  && ./03 && echo -e "\n"
echo "Running 04-polynomial_fit.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 04.exe examples/04-polynomial_fit.c     && ./04 && echo -e "\n"
echo "Running 05-histogram.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 05.exe examples/05-histogram.c          && ./05 && echo -e "\n"
echo "Running 06-random_numbers.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 06.exe examples/06-random_numbers.c     && ./06 && echo -e "\n"
echo "Running 07-hash_table.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 07.exe examples/07-hash_table.c        && ./07 && echo -e "\n"
echo "Running 08-sorting.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 08.exe examples/08-sorting.c           && ./08 && echo -e "\n"
echo "Running 09-chisquare.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 09.exe examples/09-chisquare.c         && ./09 && echo -e "\n"
echo "Running 10-correlation.c ..."
clang -I. -D_CRT_SECURE_NO_WARNINGS -o 10.exe examples/10-correlation.c       && ./10 && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
