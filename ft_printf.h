/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:28:48 by bordenoy          #+#    #+#             */
/*   Updated: 2019/02/13 20:58:32 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 50
# define SIZE_OPT 12

# define ABS(Value)	( (Value) < (0) ? (~(Value)+1) : (Value))

typedef struct			s_opt
{
	unsigned int		opt : 5;
	unsigned int		largeur;
	int					precision;
	unsigned int		prec;
	unsigned int		taille;
	char				conversion;
}						t_opt;

typedef struct			s_gob
{
	t_opt				opt;
	char				*b;
}						t_gob;

typedef struct			s_ch
{
	unsigned int		opt : 5;
}						t_ch;

typedef union			u_datas
{
	void				*f;
	int					d;
	unsigned int		us;
	unsigned char		uc;
	unsigned long		ul;
	unsigned long long	ull;
	unsigned short		ush;
	long long			ll;
	long				l;
	float				flo;
	double				dbl;
	long double			ldbl;
	short				h;
	char				*s;
	char				c;
}						t_datas;

typedef	struct			s_printf
{
	t_opt				opt;
	void				(*ptf)(t_datas, t_gob);
}						t_printf;

int						ft_printf(const char *format, ...);
size_t					ft_strlen_at(const char *str, size_t a);
char					*ft_itoa(int b);
void					ft_bzero(void *v, size_t n);
void					ft_setbuffer(char *c);
void					ft_add(char *b, char t);
int						ft_putstrlensize(char *c, int y);
int						ft_getsize(char *b, int c);
size_t					ft_strlen(char *c);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
int						end(char *b);
int						ft_atoi(const char *str);
int						par(const char *format, t_opt *opt, va_list ap);
void					ft_putnbr(t_datas nbr, t_gob opt);
void					ft_putnbr_unsigned(t_datas nbr, t_gob opt);
void					ft_putstr(t_datas nbr, t_gob opt);
void					ft_putchar(t_datas nbr, t_gob opt);
void					ft_pourcentage(t_datas nbr, t_gob opt);
int						ft_putnbr_base(long long n, char *t, int a, t_gob opt);
int						ft_u_b(unsigned long long n, char *b, int a, t_gob o);
int 					ft_ret(long long h, char *c, int a, t_gob opt);
int 					ft_retu(unsigned long long h, char *c, int a, t_gob opt);
void					ft_putnbr_address(t_datas nbr, t_gob opt);
char					opts(t_gob opt, int nb);
unsigned int			hexa(t_gob opt, char c, int g);
void					affre(t_gob opt, unsigned int a, int b);
void					offre(t_gob opt, unsigned int a, t_datas nbr);
void					ft_floater(long double nbr, t_gob opt);
void					ffre(t_opt opt, int a, int b);
unsigned int			or(int a, int b);
void					ft_arrange(t_gob opt, char format, va_list ap);
t_opt					getopts(const char *str);
int						taille(const char *format, t_opt *opt);
int						ft_size(unsigned int a);
void					ft_fl_base(long long a, char *b, t_gob opt);
int						float_count(long long a);
char					ft_floatzero(t_gob opt);
void					float_optafter(long long a, t_gob opt);
void					ft_getf(va_list ap, t_gob opt);
void					float_opt(long long a, t_gob opt);
void					aff_float(long long a, long long b, t_gob opt);
void					ft_floater(long double hallo, t_gob opt);
void					ft_pour(t_gob opt);
#endif
