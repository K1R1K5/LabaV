#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int min(int a, int b)
{
    if(a > b)
        return b;
    else
        return a;
}

int min_rec(int* arr, int size)
{
    if(size == 0)
        return arr[size];
    return min(arr[size], min_rec(arr, size-1));
}


int main()
{
    srand(time(0));
    printf("Enter size of array: ");
    int size;
    scanf("%d", &size);

    int* array = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++)
        array[i] = rand() % 100;
        
    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
        
    printf("\n%d\n", min_rec(array, size-1));

    free(array);

    return 0;
}