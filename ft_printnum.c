#include "libftprintf.h"

static t_fspec	ft_defineflags(t_fspec spec, int *prec, int negnum)
{
	if (((spec.dot && *prec >= 0) || spec.width < 0 || spec.minus) &&
		spec.zero)
		spec.zero = 0;
	if (spec.zero)
	{
		*prec = spec.width;
		if (negnum)
			(*prec)--;
		spec.width = 0;
	}
	return (spec);
}

int				ft_printnbr(int n, t_fspec spec)
{
	char	*arr;
	int		rtval;
	int		prec;

	prec = spec.precision;
	spec = ft_defineflags(spec, &prec, n < 0);
	if (spec.dot && prec == 0 && n == 0 && spec.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_itoa_prec(n, prec);
	if (arr == NULL)
		return (-1);
	rtval = ft_printstr(arr, spec);
	free(arr);
	return (rtval);
}

int				ft_printunbr(unsigned int n, t_fspec spec)
{
	char	*arr;
	int		rtval;
	int		prec;

	prec = spec.precision;
	spec = ft_defineflags(spec, &prec, 0);
	if (spec.dot && prec == 0 && n == 0 && spec.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_utoa_base_prec(n, 10, prec);
	if (arr == NULL)
		return (-1);
	rtval = ft_printstr(arr, spec);
	free(arr);
	return (rtval);
}

int				ft_printhex(unsigned int n, t_fspec spec)
{
	char	*arr;
	int		rtval;
	int		prec;
	int		i;

	prec = spec.precision;
	spec = ft_defineflags(spec, &prec, 0);
	if (spec.dot && prec == 0 && n == 0 && spec.zero == 0)
		arr = ft_strdup("");
	else
		arr = ft_utoa_base_prec(n, 16, prec);
	if (arr == NULL)
		return (-1);
	i = -1;
	if (spec.specifier == 'X')
		while (arr[++i])
			arr[i] = ft_toupper(arr[i]);
	rtval = ft_printstr(arr, spec);
	free(arr);
	return (rtval);
}
