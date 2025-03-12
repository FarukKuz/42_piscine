/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 05:13:46 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/12 21:10:51 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	df;
	int	*range;
	int	i;

	if (min >= max)
		return (0);
	df = max - min;
	range = (int *)malloc(sizeof(int) * df);
	if (!range)
		return (0);
	i = 0;
	while (i < df)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
