#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <mpi.h>
long long int total_number_of_tosses;
long long int number_in_circle;


int main(){
 int comm_sz, toss, rank;
 double x, y, distance_squared, pi_estimate;
 long long int total_sum;

 MPI_Init(NULL, NULL);
 MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 if (rank == 0){
   printf("Enter total number of tosses: ");
   scanf("%lld", &total_number_of_tosses);
 };

 MPI_Bcast(&total_number_of_tosses, 1, MPI_LONG_LONG_INT, 0, MPI_COMM_WORLD);
     for (toss = 0; toss<total_number_of_tosses; toss++){
       x = 2 * (rand() / (double)RAND_MAX) - 1;
       y = 2 * (rand() / (double)RAND_MAX) - 1;
       distance_squared = x*x + y*y;
       if (distance_squared <= 1){
         number_in_circle++;
       };
     };

 MPI_Reduce(&number_in_circle, &total_sum, 1, MPI_LONG_LONG_INT, MPI_SUM, 0, MPI_COMM_WORLD);
 if(rank == 0){
   printf("MPI_SUM of number_in_circle is: %lld\n",total_sum);
   pi_estimate = 4 * number_in_circle / ((double)total_number_of_tosses);
   printf("pi estimate = %f\n", pi_estimate);
  }


 MPI_Finalize();
 return 0;
}
