/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:08:49 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/23 18:30:29 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*arr;

	if (min >= max)
		return (0);
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
int main(void)
{
	int min = 3;
	int max = 7;
    	int *range = ft_range(min, max);

	int i = 0;
    	if (range != NULL)
    	{
        	while (i < max - min)
		{
            		printf("%d ", range[i]);
			i++;
        	}
        	free(range);
    	}
    	else
		printf("Invalid");
}*/
