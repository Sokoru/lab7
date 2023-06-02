#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculate_odd_sum(int a[], int s)
{
    int sum = 0;
    for (int i = 1; i < s; i += 2)
    {
        sum += a[i];
    }
    return sum;
}

int calculate_product_between_negatives(int a[], int s)
{
    int product = 1;
    int first_negative_index = -1;
    int last_negative_index = -1;
    for (int i = 0; i < s; i++)
    {
        if (a[i] < 0)
        {
            if (first_negative_index == -1)
            {
                first_negative_index = i;
            }
            last_negative_index = i;
        }
    }
    if (first_negative_index != -1 && last_negative_index != -1 && first_negative_index < last_negative_index)
    {
        for (int i = first_negative_index + 1; i < last_negative_index; i++)
        {
            product *= a[i];
        }
    }
    else
    {
        product = 0;
    }
    return product;
}

int check_negatives(int a[], int s)
{
    if (a[0] >= 0 || a[s - 1] >= 0)
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами не може бути вичислений.\n");
        return 0;
    }
    return 1;
}

void initialize_array(int a[], int s)
{
    srand(time(0));
    for (int i = 0; i < s; i++)
    {
        a[i] = rand() % 201 - 100;
    }
}

void print_array(int a[], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    const int s = 10;
    int array[s];
    initialize_array(array, s);
    printf("Масив: ");
    print_array(array, s);
    int odd_sum = calculate_odd_sum(array, s);
    printf("Сума елементів з непарними номерами: %d\n", odd_sum);
    if (!check_negatives(array, s))
    {
        return 0;
    }
    int product = calculate_product_between_negatives(array, s);
    if (product == 0)
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами не може бути вичислений.\n");
    }
    else
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами: %d\n", product);
    }

    return 0;
}
