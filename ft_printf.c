#include "libftprintf.h"

static t_fspec	ft_getspec(const char **format, va_list ap)
{
	t_fspec	spec;

	spec = ft_initfspec();
	(*format)++;
	while (!ft_isconvertchar(**format) && **format != '\0')
	{
		if (**format == '-')
			spec.minus = 1;
		else if (**format == '0')
			spec.zero = 1;
		else if (**format == '*' || ft_isdigit(**format))
			spec.width = ft_getwidth(&(*format), ap);
		else if (**format == '.')
		{
			spec.dot = 1;
			spec.precision = ft_getprecision(&(*format), ap);
		}
		else
			break ;
		(*format)++;
	}
	spec.specifier = **format;
	return (spec);
}

static int		ft_convert(va_list ap, t_fspec spec)
{
	if (spec.specifier == 'c')
		return (ft_printchar(va_arg(ap, int), spec));
	else if (spec.specifier == 's')
		return (ft_printstr(va_arg(ap, char *), spec));
	else if (spec.specifier == 'p')
		return (ft_printptr(va_arg(ap, void *), spec));
	else if (spec.specifier == 'd' || spec.specifier == 'i')
		return (ft_printnbr(va_arg(ap, int), spec));
	else if (spec.specifier == 'u')
		return (ft_printunbr(va_arg(ap, unsigned int), spec));
	else if (spec.specifier == 'x' || spec.specifier == 'X')
		return (ft_printhex(va_arg(ap, unsigned int), spec));
	else if (spec.specifier == '%')
		return (ft_printchar('%', spec));
	else
		return (ft_printchar(spec.specifier, spec));
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			rtval;
	int			tmpval;

	if (format == NULL)
		return (-1);
	rtval = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		tmpval = rtval;
		if (*format == '%')
			rtval += ft_convert(ap, ft_getspec(&format, ap));
		else
			rtval += ft_printchar(*format, ft_initfspec());
		if (rtval < tmpval)
			rtval = -1;
		if (rtval < 0 || *format == '\0')
			break ;
		format++;
	}
	va_end(ap);
	return (rtval);
}
