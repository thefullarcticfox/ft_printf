#include "libftprintf.h"

t_fspec		ft_initfspec(void)
{
	t_fspec	spec;

	spec.zero = 0;
	spec.minus = 0;
	spec.width = 0;
	spec.dot = 0;
	spec.precision = 0;
	spec.specifier = 0;
	return (spec);
}

int			ft_isconvertchar(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int			ft_getwidth(const char **format, va_list ap)
{
	int		width;

	width = 0;
	if (**format == '*')
		width = va_arg(ap, int);
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		(*format)--;
	}
	return (width);
}

int			ft_getprecision(const char **format, va_list ap)
{
	int		precision;

	precision = 0;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		precision = va_arg(ap, int);
	}
	if (ft_isdigit(*(*format + 1)))
	{
		(*format)++;
		precision = ft_atoi(*format);
		while (ft_isdigit(*(*format + 1)))
			(*format)++;
	}
	return (precision);
}
