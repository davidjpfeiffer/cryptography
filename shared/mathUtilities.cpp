#ifndef __MATHUTILITIES
#define __MATHUTILITIES

int mod(int n, int m);

int mod(int n, int m)
{
  while (n < 0)
  {
    n += m;
  }

  return n % m;
}

int pow(int n, int m)
{
  if (m == 0)
  {
    return 1;
  }

  for (int i = 1; i < m; i++)
  {
    n *= n;
  }

  return n;
}

#endif