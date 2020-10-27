#include <stdio.h>

int * hailstoneSequence(int x)
{
  int res[10];
  int i = 0;
  while (x != 1)
  {
    res[i++] = x;
    if (x % 2 == 0) 
      x = x / 2;
    else
      x = 3 * x + 1;
  }
  res[i] = 1;
  return res;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Error not enough arguments.\n");
    return -1;
  }
  for (int i = 1; i < argc; i++)
  {
    int x;
    sscanf(argv[i], "%d", &x);
    if (x < 1)
    {
      printf("Error invalid negative input.\n");
      continue;
    }
    int[10] res = hailstoneSequence(x);
    printf("Hailstone Sequence: ");
    for (int i = 0; i < 10; i++)
    {
      printf("%d ", res[i]);
      if (res[i] == 1)
        break;
    }
  }
  return 0;
}

