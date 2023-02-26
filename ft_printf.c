/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/26 11:11:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 
 */
void	put_char(const char a_c, int *a_return_num)
{
	ft_putchar_fd(a_c, 1);
	a_return_num++;
}

/*
 * 変換指定子を処理する
 */
void	ap_puts(const char *a_format, va_list *a_ap, int *a_return_num)
{
	if (*a_format == 'c')
		put_char((char)va_arg(*a_ap, int), a_return_num);
	// if (a_format[i] == 's')

	// if (a_format[i] == 'P')

	// if (a_format[i] == 'd')

	// if (a_format[i] == 'i')

	// if (a_format[i] == 'u')

	// if (a_format[i] == 'x')

	// if (a_format[i] == 'X')

	else if (*a_format == '%')
		put_char(*a_format, a_return_num);
	else
		put_char(*a_format, a_return_num);
}

//
//1, エラーチェック（引数カウント）
//2, %が来るまで出力
//3, %の次の文字で処理を分ける
//
//
int	ft_printf(const char *a_format, ...)
{
	va_list	r_ap;
	int		r_return_num;
	size_t	i;

	r_return_num = 0;
	va_start(r_ap, a_format);
	i = 0;
	while (a_format[i] != '\0')
	{
		if (a_format[i] == '%')
			ap_puts(&a_format[++i], &r_ap, &r_return_num);
		else
			put_char(a_format[i], &r_return_num);
		i++;
	}
	va_end(r_ap);
	return (r_return_num);
}

#include <stdio.h>
int	main(void)
{
	int x;
	int y;

	x = printf("   printf : %c, %%, %c, %c\n", 'b', '1', 'X');
	y = ft_printf("ft_printf : %c, %%, %c, %c\n", 'b', '1', 'X');
	printf("\nprintf= %d, ft_printf= %d\n", x, y);
	return (0);
}
