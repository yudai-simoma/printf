/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:38:59 by shimomayuda       #+#    #+#             */
/*   Updated: 2023/02/27 10:31:35 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 文字を出力する
*/
void	ft_putchar_fd(char c, int fd)
{
	int	x;

	if (fd < 0)
		return ;
	x = write(fd, &c, 1);
	if (x == -1)
		g_error_flg = -1;
}
