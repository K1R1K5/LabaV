#include "header.h"

int main()
{
    line _line = create_line();

    init_line(&_line);

    printf("Enter size of array: ");

    int size;

    scanf("%d", &size);

    point arr[size];

    for(int i = 0 ; i < size; i++)
    {
        arr[i] = create_point();
        init_point(&arr[i]);
    }

    int c = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i].y == (_line.a * arr[i].x) + _line.b)
            c++;
    }

    printf("Count of point: %d", c);

    return 0;
}