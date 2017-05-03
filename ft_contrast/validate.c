#include "contrast.h"

int			validate(char *str)
{
	char	*cstr;
	int		ws_count;
	int		cur_count;
	int		sign;
	int		total_count;

	total_count = 0;
	cstr = str;
	sign = 0;
	cur_count = 0;
	ws_count = 0;
	while (*cstr)
	{
		if (!ft_isdigit(*cstr) && *cstr != '-' && *cstr != ' ')
			return (0);
		// Skip all ws before the number
		while (*cstr == ' ')
			cstr++;
		// Skip over the -
		if (*cstr == '-')
			cstr++;
		// Check to see if char after - is a number
		if (!ft_isdigit(*cstr))
			return (0);
		// If it is, skip over the numbers
		while (ft_isdigit(*cstr))
			cstr++;
		// Add one to current nbr count and total count
		cur_count++;
		total_count++;
		// Skip any ws after the number before a \n
		while (*cstr == ' ')
			cstr++;
		// If newline, do testing
		if (*cstr == '\n')
		{
			if (sign == 0)
			{
				ws_count = cur_count;
				cur_count = 0;
				sign = 1;
			}
			else
			{
			//	if (ws_count != cur_count)
			//	{
			//		return (0);
			//	}
			cur_count = 0;
			}
			cstr++;
		}
	}
	cstr = str;
	return (total_count);
}
