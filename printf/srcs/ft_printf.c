/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <efleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:09:51 by efleta            #+#    #+#             */
/*   Updated: 2020/03/02 15:15:58 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_length(long long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*itoa(long long int n)
{
	char			*a;
	int				len;
	long long int	tmp;
	
//    if (n == -9223372036854775808)
//        return (ft_strdup("-9223372036854775808"));
	len = ft_length(n);
	tmp = n;
	if (!(a = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = n * (-1);
	}
	a[len] = '\0';
	while (n > 0)
	{
		len--;
		a[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (a);
}

void	ft_printf_sec(char *format, t_struct *st, va_list ap)
{
	//printf("st->i = %d\n", st->i);
	if (format[st->i] == 'd' || format[st->i] == 'i')
	{
		st->a = va_arg(ap, int);
		specif_di(st, st->a, format);
	}
	else if (format[st->i] == 'o' || format[st->i] == 'u' || format[st->i] == 'x' || format[st->i] == 'X')
	{
		unsigned int d;
		d = va_arg(ap, unsigned int);
		specif_uoxX(st, format, d);
	}
	else if (format[st->i] == 'f')
    {
	    double f;
	    f = va_arg(ap, double);

    }
	if (format[st->i] == 'p')
	{
		st->d = va_arg(ap, long long int);
		hexadecimal(st->d, 0, st);
		st->schet = st->schet + re_putstr("0x");
		st->schet = st->schet + re_putstr(st->tmp);
		st->i++;
	}
	ft_print(format, st);
}

int		ft_print_cs(int trig, t_struct *st, va_list ap)
{
	if (trig == 1)
	{
		st->s = va_arg(ap, char *);
		st->schet = st->schet + re_putstr(st->s);
		st->i++;
	}
	else if (trig == 2)
	{
		st->c = va_arg(ap, int);
		st->schet = st->schet + re_putchar(st->c);
		st->i++;
	}
	return 0;
}

void	init(t_struct *st)
{
	st->tmp = ft_memalloc(20);
	st->a = 0;
}

void	specifier(char *format, t_struct *st, va_list ap)
{
	//printf("st->i = %d\n", st->i);
	if (format[st->i] != 's' && format[st->i] != 'c' && format[st->i] != 'p' &&
		format[st->i] != 'd' && format[st->i] != 'i' &&
		format[st->i] != 'o' && format[st->i] != 'u' &&
		format[st->i] != 'x' && format[st->i] != 'X' && format[st->i] !=
		'f')
	{
		st->tmp[0] = format[st->i];
		ft_print(format, st);
//		st->schet = st->schet + re_putchar(format[st->i]);
		st->i++;
		return ;
	}
	if (format[st->i] == 's')
		ft_print_cs(1, st, ap);
	else if (format[st->i] == 'c')
		ft_print_cs(2, st, ap);
	else
		ft_printf_sec(format, st, ap);

}

int		ft_printf(char *format, ...) //сюда нужно вставить остальные флаги и ширину
{
	va_list		ap;
	t_struct	*st;
	int i;
	int j;

	st = (t_struct *)malloc(sizeof(t_struct));
	va_start(ap, format);
	st->i = 0;
	while (format[st->i] != '\0')
		st->i++;
	j = st->i;
	st->i = 0;
	while (st->i < j)
	{
		init(st);
		if (format[st->i] == '%')
		{
			st->i++;

			if (format[st->i] == '%')
			{
				st->schet += re_putchar('%');
				st->i++;
				continue ;
			}
			flags(format, st, ap);
			width(format, st);
			//printf("st->i = %d\n", st->i);
			i = length(format, st, ap);
			if (i == 0)
				specifier(format, st, ap);
			else
				ft_print(format, st);
//			if (format[st->i] == 's')
//				ft_print_cs(1, st, ap);
//			if (format[st->i] == 'c')
//				ft_print_cs(2, st, ap);
//			else
//				ft_printf_sec(format, st, ap);
		}
		else
		{
			st->schet = st->schet + re_putchar(format[st->i]);
			st->i++;
		}	
	}
	va_end(ap);
	return (st->schet);
}



typedef struct				s_str
{
    unsigned int            mant : 23;
    unsigned int            exp : 8;
    unsigned int            sign : 1;


}							t_str;

typedef union				u_sun{
    float                   f;
    struct s_str            v;
}							t_sun;

int main() {
    // int *b;
    // int a = 0x10d;
    // b = &a;
//    int a = printf("%.12f", 5427.54445);
//	printf("\na = %d\n", a);
//	int i = ft_printf("%-#x", 5427);
//	printf("\ni = %d\n", i);

                // 0b00000001100000000000000000000000
                // 0b00111111101001000000000000000000
    signed int n = 0b00111101110011001100110011001101;
    float *f = (float *)&n;
//    float f = 12.25;

    t_sun p;

    p.f = *f;

    printf("%d_ %d_ %d  %.10f\n", p.v.sign, p.v.exp, p.v.mant, p.f);

    p.v.exp = 127;

    printf("%d_ %d_ %d  %f\n", p.v.sign, p.v.exp - 127, p.v.mant, p.f);

//
//    long double a = 9.78e-4000L;
//
//    long double b = a;
//	int num = (int)b;
//	int i = 0;
//	ft_putstr("0.");
//	while (i < 4100)
//    {
//	    i++;
//        b = (b - (long double)num) * 10.0;
//	    num = (int)b;
//	    ft_putnbr(num);
//	    ft_putchar('\n');
}