/* This program module contains all the functions used for
sorting_main.c*/

#include <stdio.h>
#include <stdlib.h>

long * Load_File(char * Filename, int * Size)
{
    long numberOfIntegersToBeSorted = 0;
    FILE * inputFile = fopen("Filename", "r");

    if (inputFile == NULL) // Checks whether the input file was read correctly.
    {
        printf("\nNo file was read as input!\n");
        exit (1);
    }

    fscanf(inputFile, "%li", &numberOfIntegersToBeSorted); // Reads the first value since it contains the size of the array.

    long * arrayOfIntegers = malloc(sizeof(long) * (*Size)); // Creates the array using malloc.
    int i = 0; // Used for counting.

    for (i = 0; i < numberOfIntegersToBeSorted; i++) // Reads all the data into an array.
    {
        fscanf(inputFile, %li, &arrayOfIntegers[i]);
    }

    Size = numberOfIntegersToBeSorted; // As requested by the project sheet. Doesn't seem too useful...

    fclose(inputFile); // Closes the file.
    return arrayOfIntegers; // Returns the array of unsorted integers.
}

int Save_File(char * Filename, long * Array, int Size)
{
    FILE * outputFile = fopen("Filename", "w");

    if (outputFile == NULL) // Checks whether the output file was opened correctly.
    {
        printf("\nNo file was opened for writing to!\n");
        exit (1);
    }

    fprintf(outputFile, "%d\n", Size); // Prints the size as the first value in the file.
    int i = 0; // Used for counting.

    for (i = 0; i < Size; i++) // Prints all the data in the array.
    {
        fprintf(outputFile, "%li\n", Array[i]);
    }

    fclose(outputFile);
    return 0;
}

void Alex_Insertion_Sort(long * Array, int Size, double * N_Comp, double * N_Move)
{
    int i = 0; // Used for counting.
    int j = 0; // Used for comparisons and swaps.
    long temporaryVariable = 0; // Used to store temporary values. Not sure if I can set a long variable to 0...

    for (i = 0; i < Size; i++) // Insertion sort algorithm.
    {
        j = i;
        while (j > 0)
        {
            if (Array[j] < Array[j - 1])
            {
                temporaryVariable = Array[j];
                Array[j] = Array[j - 1];
                Array[j - 1] = temporaryVariable;
                (*N_Move) = (*N_Move) + 3;
                (*N_Comp)++;
            }
            else
            {
                (*N_Comp)++;
            }
            j--;
        }
    }

    return;
}

void Shell_Insertion_Sort(long * Array, int Size, double * N_Comp, double * N_Move)
{
    int i = 0; // Used for counting.
    int j = 0; // Used for comparisons and swaps.
    int k = 0; // Same deal as above.
    long temporaryVariable = 0; // Used to store temporary values. Not sure if I can set a long variable to 0...

    for(i = Size / 2; i > 0; i = i / 2)
    {
        (*N_Comp)++;
        for(j = i; j < Size; j++)
        {
            (*N_Comp)++;
            for(k = j - i; k >= 0; k = k - i)
            {
                (*N_Comp)++;
                if(Array[k + i] >= Array[k])
                {
                    break;
                }
                else
                {
                    temporaryVariable = Array[k];
                    Array[k] = Array[k + i];
                    Array[k + i] = temporaryVariable;
                    (*N_Move) = (*N_Move) + 3;
                }
            }
            (*N_Comp)++; // Last comparison to break out of loop.
        }
        (*N_Comp)++; // Last comparison to break out of loop.
    }
    (*N_Comp)++; // Last comparison to break out of loop.

    return;
}

void Shell_Selection_Sort(long * Array, int Size, double * N_Comp, double * N_Move)
{
    int i = 0; // Used for counting.
    int j = 0; // Used for comparisons and swaps.
    int smallestIndexValue = 0; // Stores the smallest index value.
    long temporaryVariable = 0; // Used to store temporary values. Not sure if I can set a long variable to 0...

    for (i = 0; i < Size; i++) // Selection sort algorithm.
    {
        j = i + 1;
        while (j < Size)
        {
            if (Array[j] < Array[j - 1])
            {
                smallestIndexValue = j;
                (*N_Comp)++;
                (*N_Move)++;
            }
            else
            {
                (*N_Comp)++;
            }
            j++;
        }
        temporaryVariable = Array[i + 1];
        Array[i + 1] = Array[smallestIndexValue];
        Array[smallestIndexValue] = temporaryVariable;
        (*N_Move) = (*N_Move) + 3;
    }

    return;
}

int Print_Seq(char * Filename, int Size)
{
    
}