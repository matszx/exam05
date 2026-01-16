#include "bsq.h"

char*	ft_substr(char* str, int start, int len)
{
	char*	res = (char*)malloc(len + 1);

	for (int i = 0; i < len; i++)
		res[i] = str[start + i];
	res[len] = 0;
	return res;
}

int		get_elems(FILE* stream, t_elems* elems)
{
	int ret = fscanf(stream, "%d %c %c %c\n", &(elems->lines), &(elems->empty), &(elems->obst), &(elems->full));

	if (ret != 4)
		return 1;
	if (elems->lines <= 0)
		return 1;
	if (elems->empty < 32 || elems->empty > 126)
		return 1;
	if (elems->obst < 32 || elems->obst > 126)
		return 1;
	if (elems->full < 32 || elems->full > 126)
		return 1;
	if (elems->empty == elems->obst || elems->empty == elems->full || elems->obst == elems->full)
		return 1;
	return 0;
}

int		check_elems(t_map* map, t_elems* elems)
{
	for (int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
		{
			if (map->grid[i][j] != elems->empty && map->grid[i][j] != elems->obst)
				return 1;
		}
	}
	return 0;
}

int		load_map(FILE* stream, t_map* map, t_elems* elems)
{
	map->h = elems->lines;
	map->grid = (char **)malloc(sizeof(char *) * (map->h + 1));
	map->grid[map->h] = NULL;

	char*	buf = NULL;
	size_t	bufsize;

	for (int i = 0; i < map->h; i++)
	{
		int bytes_read = getline(&buf, &bufsize, stream);
		if (bytes_read == -1)
			return 1;
		map->grid[i] = ft_substr(buf, 0, bytes_read);
		map->w = bytes_read - 1;
	}
	return 0;
}

int		find_min(int a, int b, int c)
{
	int	min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

void	find_bsq(t_map* map, t_elems* elems, t_bsq* bsq)
{
	int	matrix[map->h][map->w];

	// init matrix
	for (int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
			matrix[i][j] = 0;
	}

	// algorithm
	bsq->size = 0;
	for (int i = 0; i < map->h; i++)
	{
		for (int j = 0; j < map->w; j++)
		{
			if (map->grid[i][j] == elems->obst)
				matrix[i][j] = 0;
			else if (i == 0 || j == 0)
				matrix[i][j] = 1;
			else
			{
				int min = find_min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]);
				matrix[i][j] = min + 1;
			}
			if (matrix[i][j] > bsq->size)
			{
				bsq->size = matrix[i][j];
				bsq->x = j - matrix[i][j] + 1;
				bsq->y = i - matrix[i][j] + 1;
			}
		}
	}
}

void	print_bsq(t_map* map, t_elems* elems, t_bsq* bsq)
{
	for (int i = bsq->y; i < bsq->y + bsq->size; i++)
	{
		for (int j = bsq->x; j < bsq->x + bsq->size; j++)
			map->grid[i][j] = elems->full;
	}
	for (int i = 0; i < map->h; i++)
		fputs(map->grid[i], stdout);
}

int	main(int argc, char **argv)
{
	FILE*		stream = fopen(argv[1], "r");
	t_map		map;
	t_elems		elems;
	t_bsq		bsq;

	if (!stream)
		return 1;
	if (get_elems(stream, &elems))
		return 1;
	if (load_map(stream, &map, &elems))
		return 1;
	fclose(stream);
	for (int i = 0; i < map.h; i++)
		fputs(map.grid[i], stdout);
	find_bsq(&map, &elems, &bsq);
	print_bsq(&map, &elems, &bsq);
	return 0;
}
