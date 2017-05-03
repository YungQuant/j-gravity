#include "contrast.h"

char		*read_pgm(FILE *fp)
{
	char	*buff;
	long	len;

	buff = 0;
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buff = (char*)malloc(len);
	if (buff)
	{
		fread(buff, 1, len, fp);
	}
	return (buff);
}

a_prop		*read_argv(char **argv, g_prop *g)
{
	char		**carg;
	int			i;
	a_prop		*a;
	char		*line;
	int			fd;
	FILE		*fp;
	size_t		linecap;
	ssize_t		linelen;
	int			count;

	count = 0;
	linecap = 0;
	line = NULL;
	carg = argv;
	fd = 0;
	i = 1;
	if (!(a = (a_prop*)malloc(sizeof(a_prop))))
		return (NULL);
//	if (!(line = ft_strnew(1)))
//		return (NULL);
	while (i < 7)
	{
		if (!ft_strcmp(carg[i], "-f"))
		{
			fd = open(carg[i + 1], O_RDONLY);
			fp = fdopen(fd, "r");
			linelen = getline(&line, &linecap, fp);
			(*g).file_type = line;
		//	ft_strdel(&line);
			getline(&line, &linecap, fp);
			while (*line == '#')
				getline(&line, &linecap, fp);
			(*g).width = ft_atoi(line);
			line = line + 2;
			(*g).height = ft_atoi(line);
		//	ft_strdel(&line);
			getline(&line, &linecap, fp);
			while (*line == '#')
				getline(&line, &linecap, fp);
		//	ft_strdel(&line);
			(*g).max_grey = ft_atoi(line);
		//	getline(&line, &linecap, fp);
		//	ft_strdel(&line);
			line = read_pgm(fp);
			while (count < 4 && *line != '\0')
			{
				if (*line == '\n')
					count++;
				line++;
			}
			(*a).pgm = line;
			(*g).nbr_count = validate(line);
			(*g).calc_w = find_width(line);
			(*g).calc_h = (*g).nbr_count / (*g).width;
			i = i + 2;
		}
		if (!ft_strcmp(carg[i], "-c"))
		{
			(*a).con_lvl = ft_atoi(carg[i + 1]);
			i = i + 2;
		}
		if (!ft_strcmp(carg[i], "-o"))
		{
			(*a).file_name = carg[i + 1];
			i = i + 2;
		}
	}
	
	return (a);
}
