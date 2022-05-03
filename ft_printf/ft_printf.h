/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hogkim <hogkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 03:51:19 by hogkim            #+#    #+#             */
/*   Updated: 2022/04/07 13:51:18 by hogkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_format_tag
{
	char	*flags;
	int		width;
	int		precision;
	int		if_precision;
	char	type;
	int		ret;
}	t_form_tag;

size_t		ft_is_flag(char c);
size_t		ft_is_type(char c);
size_t		ft_precision(const char *str, size_t i, t_form_tag *ft);
size_t		ft_width(const char *str, size_t i, t_form_tag *ft);
size_t		ft_flag(const char *str, size_t i, t_form_tag *ft);

t_form_tag	*ft_malloc_ft(void);
int			ft_putstr(char *s, int fd);
char		*ft_strncpy(char *dst, char *src, size_t n);
char		*ft_strndup(char *s, size_t n);
int			ft_malatoi(const char *str, size_t count);
char		*ft_bzero_ascii(void *s, size_t n);
char		*ft_bspace(void *s, size_t n);
char		*ft_itoa_base(unsigned long long nb, char *base);
char		*ft_flag_minus(char *s, t_form_tag *ft, char *temp);
char		*ft_fill_zero_space(char *s, t_form_tag *ft, size_t len);
char		*ft_cmp_width_calloc(t_form_tag *ft, int len);
void		ft_free(void *s);

void		ft_di_sign_minus(char *s, char *temp, size_t len, t_form_tag *ft);
char		*ft_di_sign(char *s, char *temp, t_form_tag *ft, int sign);
char		*ft_di_width(char *temp, t_form_tag *ft);
char		*ft_di_precision(char *temp, t_form_tag *ft, int sign);

int			ft_c_print(t_form_tag *ft, va_list ap);
int			ft_di_print(t_form_tag *ft, va_list ap);
int			ft_p_print(t_form_tag *ft, va_list ap);
int			ft_per_print(t_form_tag *ft);
int			ft_s_print(t_form_tag *ft, va_list ap);
int			ft_u_print(t_form_tag *ft, va_list ap);
int			ft_x_print(t_form_tag *ft, va_list ap);

int			ft_printf(const char *str, ...);

#endif
