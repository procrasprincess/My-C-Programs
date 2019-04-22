#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ASCIIs		127		//ASCII characters from 0 to 127
#define atmost		1000


char letters[atmost + 1];	//Extra location for the string terminator '\0'
int count[ASCIIs];

void *calculate_Message(void *message){
  int i,index;
  for(i = 0; i < strlen(letters); i++){
    index = (int)letters[i];
    if(index==(int) message)
    (count[index])++;
  }
}

int main(){
  pthread_t threads[ASCIIs];
  int threads_args[ASCIIs];
  int i, index;

  for(i = 0; i < ASCIIs; i++)
    count[i] = 0;

  printf("Enter a line not larger than 100 characters.\n");
  fgets(letters, atmost+1, stdin);//Read a line into array letters. This function adds '\0' to the end of the string

for(i=33 ; i<ASCIIs;i++){
  threads_args[i] = pthread_create( &threads[i], NULL, calculate_Message, (void*) i);
}
for(i=33 ; i<ASCIIs;i++){
  pthread_join( threads[i], NULL);

}
  // for(i = 0; i < strlen(letters); i++){
  //   index = (int)letters[i];
  //   (count[index])++;
  // }

  for(i = 33; i <  ASCIIs; i++)
    if(count[i] != 0)
      printf("Number of %c is: %d\n", i, count[i]); 
  return 0;
}