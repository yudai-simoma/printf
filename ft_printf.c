/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/27 12:17:20 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	g_error_flg = 0;

/*
 * 受け取った文字をft_putchar_fdに渡し、1文字出力
 * 1文字出力した分return_numを1つ足す
 */
void	put_char(char a_c, size_t *a_return_num)
{
	ft_putchar_fd(a_c, 1);
	(*a_return_num)++;
}

/*
 * 
 */
void	put_str(char *a_str, size_t *a_return_num)
{
	if (a_str == NULL)
		a_str = "(null)";
	ft_putstr_fd(a_str, 1);
	(*a_return_num) += ft_strlen(a_str);
}

/*
 * 変換指定子を処理する
 */
void	ap_puts(const char *a_format, va_list *a_ap, size_t *a_return_num)
{
	if (*a_format == 'c')
		put_char((char)va_arg(*a_ap, int), a_return_num);
	else if (*a_format == 's')
		put_str((char *)va_arg(*a_ap, char *), a_return_num);
	else if (*a_format == 'p')
		put_16_address((void *)va_arg(*a_ap, void *), a_return_num);
	else if (*a_format == 'd' || *a_format == 'i')
		put_nbr((int)va_arg(*a_ap, int), a_return_num);
	else if (*a_format == 'u')
		put_u_nbr((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
	else if (*a_format == 'x')
		put_16_lower((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
	else if (*a_format == 'X')
		put_16_upper((unsigned int)va_arg(*a_ap, unsigned int), a_return_num);
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
	size_t	r_return_num;
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
	if (r_return_num > INT_MAX || g_error_flg != 0)
		return (-1);
	else
		return (r_return_num);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int x;
// 	int y;

// 	x = printf("   printf : %c, %%, %s, %i, %d, %u, %X, %x, %p\n", 'b', 
		//"abcdefg", 12345, 987654, 2147483648, 123456789, 987654321, 60);
// 	y = ft_printf("ft_printf : %c, %%, %s, %i, %d, %u, %X, %x, %p\n", 'b', 
		//"abcdefg", 12345, 987654, 2147483648, 123456789, 987654321, 60);
// 	printf("\nprintf= %d, ft_printf= %d\n", x, y);
// 	return (0);
// }
