/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:58:55 by yshimoma          #+#    #+#             */
/*   Updated: 2023/02/26 20:26:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
void	ft_u_putnbr_fd(unsigned int n, int fd);
void	ft_16_upper_fd(unsigned int n, int fd);
void	ft_16_lower_fd(unsigned int n, int fd);
void	ft_16_address_fd(uintptr_t n, int fd);
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

#endif