#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_elems
{
	int		lines;
	char	empty;
	char	obst;
	char	full;
}	t_elems;

typedef struct s_map
{
	char**	grid;
	int		w;
	int		h;
}	t_map;

typedef struct s_bsq
{
	int	size;
	int	x;
	int	y;
}	t_bsq;
