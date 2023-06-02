#include <stdio.h>
#include <math.h>

double calcD(double x1, double y1, double x2, double y2)
{
    double d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return d;
}

const char* determine_triangle_type(double s1, double s2, double s3)
{
    if (s1 <= 0 || s2 <= 0 || s3 <= 0 || s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
    {
        return "Трикутник не існує";
    }
    else if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
    {
        return "Гострокутний трикутник";
    }
    else if (s1 + s2 == s3 || s1 + s3 == s2 || s2 + s3 == s1)
    {
        return "Прямокутний трикутник";
    }
    else
    {
        return "Тупокутний трикутник";
    }
}

int main()
{
    double x1, y1, x2, y2, x3, y3;

    printf("Введіть координати вершин трикутника:\n");
    printf("Вершина A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Вершина B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Вершина C (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    double s1 = calcD(x1, y1, x2, y2);
    double s2 = calcD(x1, y1, x3, y3);
    double s3 = calcD(x2, y2, x3, y3);

    const char *triangle_type = determine_triangle_type(s1, s2, s3);
    printf("%s\n", triangle_type);

    return 0;
}
