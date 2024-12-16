/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:21:43 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/25 20:59:52 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		before_p(char *str, int *return_len);
int		after_p(char *str, va_list print_list, int *return_len);
int		print_itos(int n, int *return_len);
int		print_xtos(unsigned int num, int *return_len, char flag);
int		write_hex_x(unsigned int num, int *return_len);
int		write_hex_bigx(unsigned int num, int *return_len);
int		print_utos(unsigned int num, int *return_len);
int		print_ptos(unsigned long long pointer, int *return_len);
int		print_c(char c, int *return_len);
int		print_s(void *s, int *return_len);

#endif
