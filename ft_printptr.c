#include "libftprintf.h"

int		ft_printptr(void *p, t_fspec spec)
{
	char	*arr;
	int		rtval;
	int		prec;

	rtval = 0;
	prec = spec.precision;
	if (spec.zero && (spec.dot || spec.width < 0 || spec.minus))
		spec.zero = 0;
	if (spec.zero)
	{
		prec = spec.width - 2;
		spec.width = 0;
	}
	if (spec.dot && prec == 0 && p == NULL)
		arr = ft_strdup("0x");
	else
		arr = ft_ptoa_prec(p, prec);
	if (arr == NULL)
		return (-1);
	rtval += ft_printstr(arr, spec);
	free(arr);
	return (rtval);
}
