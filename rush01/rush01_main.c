/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:07:41 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/15 18:07:45 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int grid[4][4]);
int		input(char *str, int content[16]);
int		is_valid(int grid[4][4], int row, int col, int num);
int		solve(int grid[4][4], int row, int col);

int	main(int argc, char **argv)
{
	int	content[16];
	int	grid[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	if (argc != 2 || !input(argv[1], content))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve(grid, 0, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
}
