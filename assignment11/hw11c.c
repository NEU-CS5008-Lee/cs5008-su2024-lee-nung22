// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>

int d[20];

// Problem C: 3 x N Tiling
// Find the number of all possible cases to fill up 3 x N rectangular floor using 1x2 and 2x1 tiles.
long long int dp(int n)
{
  // Base cases
  if (n == 0) return 1; // 1 way to fill a 3x0 grid (doing nothing)
  if (n == 1) return 0; // Impossible to fill a 3x1 grid with 1x2 and 2x1 tiles
  if (n == 2) return 3; // Three ways: two vertical 1x2 tiles in each row, or two horizontal 2x1 tiles per column

  // Check if the result is already computed
  if (d[n] != 0) return d[n];

  // Recursive relation
  d[n] = 3 * dp(n - 2) + 2 * dp(n - 1);

  for (int i = 3; i <= n; i++) {
    d[n] += 2 * dp(n - i);
  }

  return d[n];
}

int main(void)
{
  int n;
  printf("Enter the value of N (must be between 0 and 20): ");
  scanf("%d", &n);
  printf("Number of ways to tile a {3 x %d} floor using {1 x 2} and {2 x 1} tiles: %lld\n", n, dp(n));
}
