/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:44:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/08 19:11:39 by ahaloua          ###   ########.fr       */
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
int ft_istertris(const char *str);
int check_conn(const char *str);
int ft_check_inlines(const char *str, int r);

#endif
