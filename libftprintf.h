#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_fspec
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	char		specifier;
}				t_fspec;

int				ft_printf(const char *format, ...);
t_fspec			ft_initfspec(void);
int				ft_isconvertchar(char c);
int				ft_getwidth(const char **format, va_list ap);
int				ft_getprecision(const char **format, va_list ap);
int				ft_printchar(char c, t_fspec spec);
int				ft_printstr(char *s, t_fspec spec);
int				ft_printnbr(int n, t_fspec spec);
int				ft_printunbr(unsigned int n, t_fspec spec);
int				ft_printhex(unsigned int n, t_fspec spec);
int				ft_printptr(void *p, t_fspec spec);

#endif
