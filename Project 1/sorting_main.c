#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long *Load_File(char *Filename, int *Size);
int Save_File(char *Filename, long *Array, int Size);
void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_move);
void Shell_Selection_Sort(long *Array, int Size, double *N_Comp, double *N_move);

int main(int argc, char* argv[]) 
{
  if(argc != 6) 
  {
    printf("\nWrong Command! You have to use this exactly:\n");
    printf("\ngcc -Werror -Wall -Wshadow -O3 sorting.c sorting_main.c -o proj1\n\n");
    exit (1);
  }

  int size;
  double numberOfComparisons = 0;
  double numberOfMoves = 0;
  
  clock_t inputOutputStart;
  clock_t inputOutputEnd;
  clock_t inputOutputTime;
  clock_t sortingTimeStart;
  clock_t sortingTimeEnd;
  clock_t sortingTime;

  // Loading Input Output Timer
  inputOutputStart = clock();
  long *Array = Load_File(argv[3], &size);
  inputOutputEnd = clock();
  inputOutputTime = inputOutputEnd - inputOutputStart;
  // End of Loading Input Output Timer

  // Saving Input Output Timer
  inputOutputStart = clock();

  if(Save_File(argv[5], Array, size) != 0) 
  { 
    exit(1);
  }

  inputOutputEnd = clock();
  inputOutputTime += (inputOutputEnd - inputOutputStart);
  // End of Saving Input Output Timer

  double inputOutputTime = inputOutputTime / CLOCKS_PER_SEC;
  double sortingTime = sortingTime / CLOCKS_PER_SEC;

  // All the information the evil Professor Koh and his TA henchmen need:
  printf("Number of comparisons: %le\n", numberOfComparisons);
  printf("Number of moves: %le\n", numberOfMoves);
  printf("I/O time: %le\n", inputOutputTime);
  printf("Sorting time: %le\n", sortingTime);

  return 0;
}

