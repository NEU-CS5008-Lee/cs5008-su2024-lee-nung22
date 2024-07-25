// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>

int d[20];

// Problem D: 2 x N Tiling
// Find the number of all possible cases to fill up 2 x N rectangular floor using 1x2, 2x1 and 1x1 tiles.
long long int dp(int n)
{
  // Base cases
  if (n == 0)
    return 1; // 1 way to fill a 2x0 floor (do nothing)
  if (n == 1)
    return 2; // 2 ways: two 1x1 tiles or one 1x2 tile

  // Check if already computed
  if (d[n] != 0)
    return d[n];

  // Recursive relation
  d[n] = dp(n - 1) + dp(n - 1) + dp(n - 2);

  return d[n];
}

int main(void)
{
  int n;
  printf("Enter the value of N (must be between 0 and 20): ");
  scanf("%d", &n);
  printf("Number of ways to tile a {2 x %d} floor using {1 x 2}, {2 x 1} and {1 x 1} tiles: %lld\n", n, dp(n));
}
