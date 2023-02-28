/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:27:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/28 19:16:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * %d, %i の場合に呼ばれる
 * intを文字列にした値の出力と、出力した文字列の長さを格納する
 */
void	put_nbr(int a_nbr, size_t *a_return_num)
{
	char	*str;

	ft_putnbr_fd(a_nbr, 1);
	str = ft_itoa(a_nbr);
	if (str == NULL)
		str = "";
	(*a_return_num) += ft_strlen(str);
	free(str);
	str = NULL;
}

/*
 * %u の場合に呼ばれる
 * unsigned intを文字列にした値の出力と、出力した文字列の長さを格納する
 */
void	put_u_nbr(unsigned int a_nbr, size_t *a_return_num)
{
	char	*str;

	ft_u_putnbr_fd(a_nbr, 1);
	str = ft_u_itoa(a_nbr);
	if (str == NULL)
		str = "";
	(*a_return_num) += ft_strlen(str);
	free(str);
	str = NULL;
}

/*
 * %X の場合に呼ばれる
 * 大文字の16進数にした値の出力と、出力した文字列の長さを格納する
 */
void	put_16_upper(unsigned int a_nbr, size_t *a_return_num)
{
	char	*str;

	ft_16_upper_fd(a_nbr, 1);
	str = ft_16_itoa(a_nbr);
	if (str == NULL)
		str = "";
	(*a_return_num) += ft_strlen(str);
	free(str);
	str = NULL;
}

/*
 * %x の場合に呼ばれる
 * 小文字の16進数にした値の出力と、出力した文字列の長さを格納する
 */
void	put_16_lower(unsigned int a_nbr, size_t *a_return_num)
{
	char	*str;

	ft_16_lower_fd(a_nbr, 1);
	str = ft_16_itoa(a_nbr);
	if (str == NULL)
		str = "";
	(*a_return_num) += ft_strlen(str);
	free(str);
	str = NULL;
}

/*
 * %p の場合に呼ばれる
 * アドレス値を16進数にした値の出力と、出力した文字列の長さを格納する
 */
void	put_16_address(void *a_address, size_t *a_return_num)
{
	char	*str;

	ft_16_address_fd((uintptr_t)a_address, 1);
	str = ft_16_address_itoa((uintptr_t)a_address);
	if (str == NULL)
		str = "";
	(*a_return_num) += ft_strlen(str) + 2;
	free(str);
	str = NULL;
}
