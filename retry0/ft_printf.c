/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/12 17:58:01 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * 変換指定子を処理する
 */
void	ft_ap_puts(const char *format, va_list *ap)
{
	if (*format == 'c')
		ft_putchar_fd((char)va_arg(*ap, int), 1);
	// if (format[i] == 's')

	// if (format[i] == 'P')

	// if (format[i] == 'd')

	// if (format[i] == 'i')

	// if (format[i] == 'u')

	// if (format[i] == 'x')

	// if (format[i] == 'X')

	else if (*format == '%')
		ft_putchar_fd(*format, 1);
	else
		ft_putchar_fd(*format, 1);
}

//
//1, エラーチェック（引数カウント）
//2, %が来るまで出力
//3, %の次の文字で処理を分ける
//
//
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		return_num;
	size_t	i;

	return_num = 0;
	// if (ft_err_check(format, ap))
	// 	return (0);
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_ap_puts(&format[++i], &ap);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (return_num);
}

#include <stdio.h>
int	main(void)
{
	printf("%c\n", 'b');
	ft_printf("%c", 'a');
	return (0);
}
