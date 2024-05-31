#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    double a;

    double b;

} line;

typedef struct point
{

    double x;

    double y;

} point;

line create_line();
point create_point();
void init_line(line* _line);
void init_point(point* _point);
void get_info_line(line _line);
void get_info_point(point _point);