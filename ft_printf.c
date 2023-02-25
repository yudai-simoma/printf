/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/25 12:48:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//
//1, エラーチェック（引数カウント）
//2, %が来るまで出力
//3, %の次の文字で処理を分ける
//
//
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		i++;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%c\n", 'b');
	ft_printf("%c", 'a');
	return (0);
}
