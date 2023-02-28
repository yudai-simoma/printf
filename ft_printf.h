/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:58:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/28 19:15:34 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

extern int	g_error_flg;

int		ft_printf(const char *format, ...);
char	*ft_u_itoa(unsigned int n);
char	*ft_16_itoa(unsigned int n);
char	*ft_16_address_itoa(uintptr_t n);
void	put_char(char a_c, size_t *a_return_num);
void	put_str(char *a_str, size_t *a_return_num);
void	put_nbr(int a_nbr, size_t *a_return_num);
void	put_u_nbr(unsigned int a_nbr, size_t *a_return_num);
void	put_16_upper(unsigned int a_nbr, size_t *a_return_num);
void	put_16_lower(unsigned int a_nbr, size_t *a_return_num);
void	put_16_address(void *a_address, size_t *a_return_num);
void	ap_puts(const char *a_format, va_list *a_ap, size_t *a_return_num);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif