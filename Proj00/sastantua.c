/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalonji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:16:00 by ikalonji          #+#    #+#             */
/*   Updated: 2020/06/23 12:34:40 by ikalonji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int width_per_level(int i)
{
	if(i == 0)	
		return(7);
	return(width_per_level(i - 1) + 2 * (1 +(3 + i) +(i % 2)+(i / 2)));
}
void level(int height, int width, int gap_diff)
{
	int i;
	int j;
	
	i = 0;
	while (i<height)
	{
		j = -gap_diff;
		while(j < height -1 - i)
		{
			write(1, " ", 1);
			j++;
		}
		j += height + 1 -i;
		write(1, "/", 1);
		while(j< width)
		{
			write(1, "*", 1);
			j++;
		}
		write(1, "\\", 1);
		write(1, "\n", 1);
		i++;
	}

}
void sastantua(int size)
{
	int i;
	int height;
	int width;
	int gap_diff;

	i = 0;


	while(i<size)
	{
		gap_diff =(width_per_level(size - 1)- width_per_level(i)) / 2;
		height = 3 + i; 
		width = width_per_level(i);
		level(height, width, gap_diff);
		write(1, "\n", 1);
		i++;
	}
}

int main(/*int argc, char **argv*/)
{
	sastantua(3);
	return 0;
}
