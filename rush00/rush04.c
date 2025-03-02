/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:19:39 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/02 09:34:51 by fakuz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	w;
	int	h;

	h = 1;
	while (h <= y)
	{
		w = 1;
		while (w <= x)
		{
			if ((y != 1 && w == 1 && h == y) || (x != 1 && w == x && h == 1))
				ft_putchar('C');
			else if ((w == 1 && h == 1) || (w == x && h == y))
				ft_putchar('A');
			else if (w != 1 && w != x && h != 1 && h != y)
				ft_putchar(' ');
			else
				ft_putchar('B');
			w ++;
		}
		h++;
		ft_putchar('\n');
	}
}
