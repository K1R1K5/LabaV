#include "header.h"

line create_line()
{
    line _line;
    return _line;
}

point create_point()
{
    point _point;
    return _point;
}


void init_line(line* _line)
{
    printf("Enter a for line: ");

    double a;

    scanf("%lf", &a);

    printf("Enter b for line: ");

    double b;

    scanf("%lf", &b);


    _line->a = a;
    _line->b = b;
}

void init_point(point* _point)
{
    printf("Enter x for point: ");

    double x;

    scanf("%lf", &x);

    printf("Enter y for point: ");

    double y;

    scanf("%lf", &y);


    _point->x = x;
    _point->y = y;
}

void get_info_line(line _line)
{
    printf("a = %lf\nb = %lf", _line.a, _line.b);
}

void get_info_point(point _point)
{
    printf("a = %lf\nb = %lf", _point.x, _point.y);
}