#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void		ft_putnbr(int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
#endif
