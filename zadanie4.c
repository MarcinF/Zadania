#include <stdio.h>
#include <stdlib.h>
//liczby od najwiekszej do najmniejszej
int main()
{
  int i, j, a, n, number[4096];
  printf("podaj ilosc liczb \n");
  scanf("%d", &n);

  printf("podaj liczby \n");
  for (i = 0; i < n; ++i)
  scanf("%d", &number[i]);

  for (i = 0; i < n; ++i)
  {

    for (j = i + 1; j < n; ++j)
    {

      if (number[i] < number[j])
        {
          a = number[i];
          number[i] = number[j];
          number[j] = a;
        }
    }
  }

  printf("liczby od najwiekszej do najmniejszej \n");
  for (i = 0; i < n; ++i)
    printf("%d\n", number[i]);
}
