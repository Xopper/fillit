/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:44:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/04 15:26:08 by aazeroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_tetrim
{
	int tab[4][5];
}		t_tetrim;
typedef struct s_tetris
{
	t_tetrim multi_tab[26];
}		t_tetris;

int	ft_read_tetris(int fd);

#endif
