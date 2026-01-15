#include "life.h"

char**	create_board(int w, int h)
{
	char**	board = (char**)malloc(sizeof(char*) * (h + 1));

	for (int i = 0; i < h; i++)
	{
		board[i] = (char*)malloc(sizeof(char) * w + 1);
		for (int j = 0; j < w; j++)
			board[i][j] = ' ';
		board[i][w] = 0;
	}
	board[h] = 0;

	return board;
}

void	draw_moves(char** board, int w, int h)
{
	char	input;
	int		x = 0;
	int		y = 0;
	int		drawing = 0;

	read(STDIN_FILENO, &input, 1);
	while (input)
	{
		if (input == 'x')
			drawing = !drawing;
		else if (input == 'w')
		{
			if (y > 0)
				y -= 1;
		}
		else if (input == 'a')
		{
			if (x > 0)
				x -= 1;
		}
		else if (input == 's')
		{
			if (y < h - 1)
				y += 1;
		}
		else if (input == 'd')
		{
			if (x < w - 1)
				x += 1;
		}
		if (drawing)
			board[y][x] = '0';
		read(STDIN_FILENO, &input, 1);
	}
}

void	print_board(char** board)
{
	int	y = 0;
	while (board[y])
	{
		int	x = 0;
		while (board[y][x])
			putchar(board[y][x++]);
		putchar('\n');
		y++;
	}
}

void	free_board(char** board, int w, int h)
{
	for (int i = 0; i < h; i++)
		free(board[i]);
	free(board);
}

void	iterate(char** board, int w, int h)
{
	//char**	new_board = create_board(w, h);
}

int	main(int argc, char** argv)
{
	if (argc != 4)
		return 1;
	int w = atoi(argv[1]);
	int	h = atoi(argv[2]);
	int	it = atoi(argv[3]);

	char**	board = create_board(w, h);
	draw_moves(board, w, h);
	while (it-- > 0)
		iterate(board, w, h);
	print_board(board);
	free_board(board, w, h);
	return 0;
}
