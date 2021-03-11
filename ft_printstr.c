#include "libftprintf.h"

static int		ft_printspaces(t_fspec spec, int len)
{
	int		rtval;

	rtval = 0;
	if (spec.width < 0)
		spec.width = -spec.width;
	while (spec.width-- > len)
	{
		if (spec.zero == 1 && spec.minus == 0)
			rtval += write(1, "0", 1);
		else
			rtval += write(1, " ", 1);
	}
	return (rtval);
}

static t_fspec	ft_definewidth(t_fspec spec, int *len)
{
	if (spec.precision < 0)
		spec.dot = 0;
	if (spec.width < 0)
		spec.minus = 1;
	if (spec.dot && *len > spec.precision && spec.specifier == 's')
		*len = spec.precision;
	return (spec);
}

int				ft_printchar(char c, t_fspec spec)
{
	int		rtval;

	rtval = 0;
	if (spec.minus == 1 || spec.width < -1)
	{
		rtval += write(1, &c, 1);
		rtval += ft_printspaces(spec, 1);
	}
	else
	{
		rtval += ft_printspaces(spec, 1);
		rtval += write(1, &c, 1);
	}
	return (rtval);
}

int				ft_printstr(char *s, t_fspec spec)
{
	int		rtval;
	int		len;

	rtval = 0;
	if (s == NULL)
		return (ft_printstr("(null)", spec));
	len = ft_strlen(s);
	spec = ft_definewidth(spec, &len);
	if (spec.minus == 1)
	{
		rtval += write(1, s, len);
		rtval += ft_printspaces(spec, len);
	}
	if (spec.minus == 0)
	{
		rtval += ft_printspaces(spec, len);
		rtval += write(1, s, len);
	}
	return (rtval);
}
