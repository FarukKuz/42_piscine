/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakuz <fakuz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:56:42 by fakuz             #+#    #+#             */
/*   Updated: 2025/03/02 09:35:09 by fakuz            ###   ########.fr       */
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
				ft_putchar('\\');
			else if ((w == 1 && h == 1) || (w == x && h == y))
				ft_putchar('/');
			else if (w != 1 && w != x && h != 1 && h != y)
				ft_putchar(' ');
			else
				ft_putchar('*');
			w ++;
		}
		h++;
		ft_putchar('\n');
	}
}
