/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 05:14:26 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/12 21:10:54 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	df;
	int	*src;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	df = max - min;
	src = (int *)malloc(sizeof(int) * df + 1);
	if (!src)
		return (-1);
	i = 0;
	while (i < df)
	{
		src[i] = min + i;
		i++;
	}
	*range = src;
	return (i);
}
