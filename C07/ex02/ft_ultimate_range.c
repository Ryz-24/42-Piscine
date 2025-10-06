/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:46:33 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/26 16:22:09 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
/*
int main()
{
    int *range;
    int min = 3;
    int max = 7;
    int size;
    int	i;

    i = 0;
    size = ft_ultimate_range(&range, min, max);
    if (range != NULL)
    {
        printf("Size: %d\n", size);
        while (i < size)
        {
            printf("%d ", range[i]);
	    i++;
        }
        free(range);
    }
    else
        printf("Invalid");

    return 0;
}*/
