/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:44:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/16 19:21:14 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft/libft.h"
#include <fcntl.h>

typedef struct s_cord
{
	int cl;
	int ln;
}		t_cord;

typedef struct s_tetrim
{
	t_cord hashtab[4];
	char gp;
	char c;
}		t_tetrim;

typedef struct s_tetris
{
	t_tetrim multi_tab[26];
}		t_tetris;

int		ft_read_tetris(int fd);
int		ft_istertris(const char *str);
int		check_conn(const char *str);
int		ft_check_inlines(const char *str, int r);
void	ft_gethashs(t_tetrim tet, int col, int ln);
void	ft_shift(t_tetrim *one);
void	ft_stock_hash(char *buff, t_tetrim *one);
#endif
