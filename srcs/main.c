#include "../include/so_long.h"

int	check_walls(char *line, int mode)
{
	int i;

	i = 0;
	if (mode == 0)
	{
		while (line[i])
		{
			if (line[i++] != '1')
			{
				printf("cw1");
				return (1);
			}
		}
	}
	else
	{
		if (line[i++] != '1')
		{
			printf("cw2");
			return (1);
		}
		while (line[i + 1])
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
					&& line[i] != 'P' && line[i] != 'E' && line[i] != '\n')
			{
				printf("cw3\nbad char = %c\n", line[i]);
				return (1);
			}
			i++;
		}
		if (line[i] != '1')
		{
			printf("cw4\n");
			return (1);
		}
	}
	return (0);
}

int	parsing(char **map)
{
	int i;
	int j;
	int width;
	int ret;
	int p;
	int c;
	int e;

	ret = 0;
	i = 0;
	p = 0;
	c = 0;
	e = 0;
	width = ft_strlen(map[i]);
	ret += check_walls(map[i++], 0);
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != width)
		{	
			printf("prs1\n");
			return (1);
		}
		ret += check_walls(map[i], 1);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			if	(map[i][j] == 'C')
				c++;
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || c < 1 || e < 1)
	{
		printf("p = %d\nc = %d\ne = %d\n", p, c, e);
		printf("prs2\n");
		return (1);
	}
	if (ft_strlen(map[i]) != width)
	{
		printf("prs3\n");
		return (1);
	}
	ret += check_walls(map[i], 0);
	return (ret);
}
/*
int	main(int ac, char **av)
{
	int ret_gnl;
	int fd;
	char **map;
	char *line;
	char *tmp;

	ret_gnl = 1;
	
	fd = 0;
	printf("caca");
	fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
	printf("Caca");
	if (ac != 2)
	{
		ft_putstr("Wrong number of arguments\n");
		return (0);
	}
	printf("Yo");
	while (ret_gnl)
	{
		printf("Salut");
		ret_gnl = get_next_line(fd, &line);
		tmp = ft_strjoin(tmp, line);
		printf("salut");
		tmp = ft_strjoin(tmp, " ");
		printf("Yo");
		free(line);
	}
	map = ft_split(tmp, ' ');
	int i = 0;
	while (map[i])
	printf("%s\n", map[i++]);
	printf("parsing = %d\n", parsing(map));
}
int		main(void)
{
	void	*mlx;
	mlx  = mlx_init();
}
*/

int	main(int ac, char **av)
{	
	ac++;
	int fd = open(av[1], O_RDONLY);
	printf("fd = %d\n", fd);
}

