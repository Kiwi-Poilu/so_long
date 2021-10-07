#include "../include/so_long.h"

int	check_walls(char *line, int mode)
{
    int i;

    i = 0;
    while(line[i])
    {
	if (line[i] != '1')
	    return(1);
	i++;
    }
    return (0);
}

int	parsing(char **map)
{
    int i;
    int j;
    int width;
    int ret;

    i = 0;
    width = ft_strlen(map[i]);
    ret += check_walls(map[i++], 0);
    while (map[i + 1])
    {
	if (ft_strlen(map[i]) != width)
	    return (1);
	while (map[i][j]
    }
}

int	main(int ac, char **av)
{
    int ret_gnl;
    int fd;
    char **map;
    char *line;
    char *tmp;
    
    ret_gnl = 1;
    fd = 0;
    fd = open(av[1], O_RDONLY);
    printf("fd = %d\n", fd);
    if (ac != 2)
    {
	ft_putstr("Wrong number of arguments\n");
	return (0);
    }
    while (ret_gnl)
    {
	ret_gnl = get_next_line(fd, &line);
	tmp = ft_strjoin(tmp, line);
	tmp = ft_strjoin(tmp, " ");
	free(line);
    }
    map = ft_split(tmp, ' ');
    //int i = 0;
    //while (map[i])
    //	printf("%s\n", map[i++]);
    parsing(map);
}
