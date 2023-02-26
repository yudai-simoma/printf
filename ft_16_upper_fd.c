/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_upper_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:35:07 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/02/26 16:21:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 与えられた数値を文字列へ格納
*/
static void	ft_putnbr(unsigned int nn, long break_num, int fd)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (nn > 15)
		ft_putchar_fd(str[nn / break_num], fd);
	else
		ft_putchar_fd(str[nn % 16], fd);
}

/*
** 数値を大きい位から一つづつ、出力関数に渡す
** 16の位が0の時のみ例外処理をしている
*/
static void	ft_putnbr_fd_add(long n_len, long nn, long break_num, int fd)
{
	while (n_len)
	{
		if (n_len != 1)
		{
			if (nn > 15)
			{
				ft_putnbr(nn, break_num / 16, fd);
				break_num /= 16;
				nn -= (break_num * (nn / break_num));
			}
			else
			{
				ft_putnbr(0, break_num / 16, fd);
				break_num /= 16;
				nn -= (break_num * (nn / break_num));
			}
		}
		else
		{
			ft_putnbr(nn, break_num / 16, fd);
			break_num = 1;
			nn /= 16;
		}
		n_len--;
	}
}

/*
** 数値を出力する
*/
void	ft_16_upper_fd(unsigned int n, int fd)
{
	long	n_len;
	long	nn;
	long	break_num;

	nn = n;
	n_len = 0;
	if (n < 0)
	{
		nn *= -1;
		ft_putchar_fd('-', fd);
	}
	break_num = 1;
	while (n)
	{
		n /= 16;
		break_num *= 16;
		n_len++;
	}
	if (nn < 16)
	{
		break_num = 16;
		n_len = 1;
	}
	ft_putnbr_fd_add(n_len, nn, break_num, fd);
}
