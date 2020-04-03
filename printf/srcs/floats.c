#include "../includes/ft_printf.h"
# define SIZE_E 127
# define SIZE_M 23

//void    bit_parcer(long double f)
//{
//    t_sun eeei;
//    //unsigned displayMask = 1 << 22;
//    int c;
//
//    eeei.f = f;
//    printf("\n");
////    printf("%d_ %d_ %d  %f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
//    for (c=0; c<=23; c++)
//    {
//        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
//        //eeei.v.mant <<= 1;
//
////        if (c % 8 == 0)
////            putchar(' ');
//    }
//}

void    *ft_cpy(char *newptr, char *ptr, int size)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(ptr);
    while (i < size)
    {
        newptr[i] = '0';
        i++;
    }
    while (j > 0)
    {
        i--;
        j--;
        newptr[i] = ptr[j];
    }
    return (newptr);
}

void	*ft_realloc(void *ptr, size_t size)
{
    char	*newptr;

    printf("realloc\n");
    if (!size && ptr)
    {
        if (!(newptr = (char *)malloc(1)))
            return (NULL);
        ft_memdel(&ptr);
        return (newptr);
    }
    if (!(newptr = (char *)malloc(size)))
        return (NULL);
    if (ptr)
    {
        ft_cpy(newptr, ptr, size);
        ft_memdel(&ptr);
    }
    return (newptr);
}

int two_degree(int s)
{
    int i;
    unsigned long long a;

    a = 1;
    i = 0;
    while (i < s)
    {
        a *= 2;
        i++;
    }
    return (a);
}

void    *get_char(char *arr)
{
    char *mas;
    int i;
    int j;
    char tmp;

    j = ft_strlen(arr);
    i = 0;
    mas = ft_memalloc(ft_strlen(arr));
    while (arr[i] != '\0')
    {
        mas[i] = arr[j - 1];
        i++;
        j--;
    }
    ft_memdel(&arr);
    return (mas);
}

void    *sum_char(char *fp, char *arr)
{
    int i;
    int j;
    char tmp;

    i = ft_strlen(fp);
    j = ft_strlen(arr);
    printf("i:%d, j:%d\n", i, j);
    if ((i - 1) == j)
    {
        fp = ft_realloc(fp, (i*2));
        i = ft_strlen(fp);
    }
    while (j > 0)
    {
        j--;
        i--;
        tmp = arr[j];
        fp[i] += tmp - '0';
        if (fp[i] > '9')
        {
            fp[i]-= 10;
            fp[i - 1]++;
        }
    }
    printf("fp:%s, arr:%s\n", fp, arr);
    return (fp);
}

void    bit_parcer(long double f)
{
    t_sun eeei;
    int c;
    int shift;
    int b;
    unsigned long long sum;
    char *arr;
    char *fp;
    int size;

    size = 8;
    fp = ft_memalloc(size);
    fp = ft_realloc(fp, size);
    arr = ft_memalloc(1);
    printf("fp:%s\n", fp);
    eeei.f = f;
    sum = 0;
    c = sizeof(f);
    printf("%d_ %d_ %d  %f\n", eeei.v.sign, eeei.v.exp, eeei.v.mant, eeei.f);
    shift = exp_shift(eeei);
    printf("shift:%d\n", shift);
    for (c = (SIZE_M - shift); c < SIZE_M; c++)
        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
    printf("\n");
    for (c = (SIZE_M - shift); c < SIZE_M; c++)
    {
//        ft_putchar(eeei.v.mant & (1 << c) ? '1' : '0');
        eeei.v.mant & (1 << c) ? (b = 1) : (b = 0);
        //ft_putnbr(b);
        if (b == 1)
        {
            sum = two_degree(c - (SIZE_M - shift));
            arr = ft_itoa(sum);
            //arr = get_char(arr);
            fp = sum_char(fp, arr);
            //printf("sum:%s\n", arr);
        }
    }
    sum = two_degree(c - (SIZE_M - shift));
    arr = ft_itoa(sum);
    sum_char(fp, arr);
//    printf("\nsum:%d\n", sum);
    printf("\n");
}

int exp_shift(t_sun eeei)
{
    int a;

    a = eeei.v.exp - SIZE_E;
    return (a);
}

//int two_degree(char *arr, int deg)
//{
//    int i;
//    int len;
//    char *newptr;
//
//    i = 0;
//    if (arr[i] == '\0')
//        arr[i] = '1';
//    i = ft_strlen(arr);
//    len = i;
//    while (deg > 0)
//    {
//        i--;
//        tmp = arr[i];
//        arr[i] += tmp - '0';
//        if (arr[i] > '9' && i == 0)
//        {
//            newptr = ft_strnew(len + 1);
//            fp[i]-= 10;
//            fp[i - 1]++;
//        }
//    }
//}