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

#endif