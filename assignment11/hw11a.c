// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>

int d[20];

// Problem A: 2 x N Tiling
// Find the number of all possible cases to fill up 2 x N rectangular floor using 1x2 and 2x1 tiles.
long long int dp(int n)
{
  // Initialize base cases
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;
  if(d[n] != 0)
    return d[n];
    
  return d[n] = dp(n - 1) + dp(n - 2);
}

int main(void)
{
  int n;
  printf("Enter the value of N (must be between 0 and 20): ");
  scanf("%d", &n);
  printf("Number of ways to tile a {2 x %d} floor using {1 x 2} and {2 x 1} tiles: %lld\n", n, dp(n));
}
