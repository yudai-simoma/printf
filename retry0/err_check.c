/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:20:24 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/12 14:36:08 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * formatの中から%の個数を取得
 */
static size_t	ft_format_percent_count(const char *format)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%')
			count++;
		i++;
	}
	return count;
}

/*
 * apの引数がいくつあるか取得	未実装
 */
// static size_t	ft_ap_count(va_list ap)
// {
// 	size_t	count;

// 	count = 0;
// 	va_start(ap);
// 	while (ap != NULL)
// 	{
// 		va_arg()
// 	}
	
// }

/*
 * エラーチェック
 */
int	ft_err_check(const char *format, va_list ap)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (format == NULL || ap == NULL)
		return (1);
	x = ft_format_percent_count(format);
	// y = ft_ap_count(ap);
	if (x > y)
		return (1);
	return (0);
}
