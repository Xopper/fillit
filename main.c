/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:45:42 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/04 15:26:26 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{

	int fd = open(argv[argc - 1], O_RDONLY);
	if (ft_read_tetris(fd) == 1)
		ft_putendl("it's OK");
	else
		ft_putendl("KOOO");
	return (0);
}
