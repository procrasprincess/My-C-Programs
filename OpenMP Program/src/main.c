#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

int findBiggest(int x[], int from, int to)
{
  int big = 0, i;
  for(i = from; i < to; i++)
    if(big < x[i])
      big = x[i];
  return big;
}

int main()
{
  int i, a[800], b[8], big, lenght = 800;

  srand((int)time(NULL));

  for(i = 0; i < 800; i++)
    a[i] = rand()%50001;

    #pragma omp parallel num_threads(4)
    {
        int ID = omp_get_thread_num();

        printf("Thread %d - Finding from %d to %d",ID,ID * 100, ID * 100 + 100);
        b[ID]=findBiggest(a, ID * 100, ID * 100 + 100);
        printf("Thread %d - Done finding.",ID);
    }

  for(i = 0; i < 8; i++)
    big = findBiggest(b, 0, 8);

  printf("The biggest from the entire array is: %d\n", findBiggest(a, 0, lenght));
  printf("The biggest from the nested loop is: %d\n", big);
  return 0;
}

