#include "../includes/ft_printf.h"

void	flags(char *format, t_struct *st, va_list ap)
{
	//printf("st->i = %d\n", st->i);
	while (format[st->i] >= 32 && format[st->i] <= 48 && format[st->i] != 37)
	{
		if (format[st->i] == '+')
			st->f_plus = 1;
		else if (format[st->i] == '-')
			st->f_minus = 1;
		else if (format[st->i] == ' ')
			st->f_space = 1;
		else if (format[st->i] == '#')
			st->f_resh = 1;
		else if (format[st->i] == '0')
		{
			st->f_nul = 1;
			//st->i--;
		}
		st->i++;
		//printf("st->i:%d\n", st->i);
	}
	//printf("st->i:%d\n", st->i);
	//length(format, st, ap);
}

void	print_resh(char *format, t_struct *st)
{
	if (st->f_resh == 1 && st->tmp[0] != '0')
	{
		if (format[st->i] == 'x')
			st->schet = st->schet + re_putstr("0x");
		else if (format[st->i] == 'X')
			st->schet = st->schet + re_putstr("0X");
		else if (format[st->i] == 'o')
			st->schet = st->schet + re_putstr("0");
	}
}

void	ft_print(char *format, t_struct *st)
{
	int i;

	i = 0;
	st->i = st->i - 1;
	if (st->f_minus == 1)
	{
		print_resh(format, st);
		st->schet = st->schet + re_putstr(st->tmp);
		return ;
	}
	 if (st->f_nul > 0 && st->f_minus != 1)
	 	i++;
	 else if (st->f_space == 1 || st->wdht > 0)
	 	space_print(st);
	 print_resh(format, st);
//	if (st->f_resh == 1 && st->tmp[0] != '0')
//	{
//		if (format[st->i] == 'x')
//			st->schet = st->schet + re_putstr("0x");
//		else if (format[st->i] == 'X')
//			st->schet = st->schet + re_putstr("0X");
//		else if (format[st->i] == 'o')
//			st->schet = st->schet + re_putstr("0");
//	}
	if (i > 0)
		null_print(st);
	if (st->f_minus == 0)
		st->schet = st->schet + re_putstr(st->tmp);
	ft_free(st);
	st->i = st->i + 1;
}

void space_print(t_struct *st)
{
	int d;

	//int a = ft_strlen(st->tmp);
	d = st->wdht - ft_strlen(st->tmp);
	if (st->f_resh == 1 && st->specif == 'x')
		d = d - 2;
	else if (st->f_resh == 1 && st->specif == 'o')
		d--;
	while (d-- > 0)
		st->schet = st->schet + re_putchar(' ');
}

void	null_print(t_struct *st)
{
	int d;

	d = st->wdht - ft_strlen(st->tmp);
	if (st->f_resh == 1 && (st->specif == 'x' || st->specif == 'X'))
		d = d - 2;
	else if (st->f_resh == 1 && st->specif == 'o')
		d--;
	while (d-- > 0)
		st->schet = st->schet + re_putchar('0');
}

void		width(char *format, t_struct *st)
{
	int		i;
	int		j;
	char	*wdht;

	i = st->i;
	j = 0;
	st->wdht = 0;
	wdht = ft_memalloc(20);
	while (format[i] != '\0' && format[i] != '%')
	{
		if (format[i] >= 48 && format[i] <= 57)
		{
			wdht[j] = format[i];
			j++;
		}
		i++;
		if (format[i] == '.' || (format[i] > 96 && format[i] < 123)
		|| format[i] == 'X')
			break ;
	}
	st->i = st->i + j;
	st->wdht = ft_atoi(wdht);
//	if (st->f_nul == 1)
//		null_print(st);
//	else
//		space_print(st);
	//printf("st->wdht:%d\n", st->wdht);
	//return (1);
}

void	ft_free(t_struct *st)
{
	// free(st->tmp);
	st->f_plus = 0; // триггер
	st->f_minus = 0;
	st->f_space = 0;
	st->f_resh = 0;
	st->f_nul = 0;
	st->wdht = 0;
	free(st->tmp);
}
