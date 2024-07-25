// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>

int d[20];

// Problem B: 2 x N Tiling
// Find the number of all possible cases to fill up 2 x N rectangular floor using 1x2, 2x1 and 2x2 tiles.
long long int dp(int n)
{
  // Base cases
  if (n == 0) return 1; // One way to fill a 2x0 floor (do nothing)
  if (n == 1) return 1; // Only 1x2 and 2x1 can be used, so 1 way
  if (n == 2) return 5; // The five ways are: two 1x2 tiles, two 2x1 tiles, one 2x2 tile, or a mix

  // Check if already computed
  if(d[n] != 0) return d[n];

  // Recursive relation including the 2x2 tile
  d[n] = dp(n - 1) + dp(n - 2) + dp(n - 2);

  return d[n];
}

int main(void)
{
  int n;
  printf("Enter the value of N (must be between 0 and 20): ");
  scanf("%d", &n);
  printf("Number of ways to tile a {2 x %d} floor using {1 x 2}, {2 x 1} and {2 x 2} tiles: %lld\n", n, dp(n));
}
