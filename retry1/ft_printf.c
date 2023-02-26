/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:47:10 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/25 19:55:59 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//文字列をput_strに格納する関数
void	str_add_str(char **put_str, char *add_str)
{
	while (*add_str != '\0')
	{
		**put_str = *add_str;
		put_str++;
		add_str++;
	}
}

//文字をput_strに格納する変数
void	char_add_str(char **put_str, char c)
{
	**put_str = c;
	put_str++;
}

void	ap_add_str(char **put_str, const char *format, va_list *ap)
{
	if (*format == 'c')
		char_add_str(put_str, (char)va_arg(*ap, int));
	else if (*format == 's')
		str_add_str(put_str, (char *)va_arg(*ap, char *));
	// else if (*format == 'P')

	// else if (*format == 'd')

	// else if (*format == 'i')

	// else if (*format == 'u')

	// else if (*format == 'x')

	// else if (*format == 'X')

	else if (*format == '%')
		char_add_str(put_str, '%');
	else
		char_add_str(put_str, (char)va_arg(*ap, int));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*put_str;
	char	*head;
	size_t	return_num;
	size_t	i;

	put_str = (char *)calloc(((size_t)INT_MAX + 1), sizeof(char));
	if (put_str == NULL)
		return (0);
	head = put_str;
	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			//csdixXpの対応をする
			ap_add_str(&put_str, &format[++i], &ap);
		else
			//文字をput_strに格納する
			char_add_str(&put_str, format[i]);
		i++;
	}
	va_end(ap);
	return_num = ft_strlen(head);
	if (write(1, head, return_num) == -1)
		return (0);
	// free(put_str);
	head = NULL;
	if (return_num > INT_MAX)
		return (0);
	else
		return ((int)return_num);
}

#include <stdio.h>
int	main(void)
{
	int a,b;

	a = printf("   printf: %c, %s, abc\n", 'b', "12345678");
	b = ft_printf("ft_printf: %c, %s, abc\n", 'b', "12345678");
	// a = printf("   printf: %c%c%%%c\n", 'b', '1', 'p');
	// b = ft_printf("ft_printf: %c%c%%%c\n", 'b', '1', 'p');
	printf ("\nprintf:%d, ft_printf:%d", a, b);
	return (0);
}
