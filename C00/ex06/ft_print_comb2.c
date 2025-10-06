/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: rzaatreh <marvin@42.fr>		    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2025/02/05 14:42:32 by rzaatreh	       #+#    #+#	      */
/*   Updated: 2025/02/05 15:00:46 by rzaatreh         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_putchar(i / 10 + '0');
			ft_putchar(i % 10 + '0');
			ft_putchar(' ');
			ft_putchar(j / 10 + '0');
			ft_putchar(j % 10 + '0');
			if (!(i == 98 && j == 99))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
