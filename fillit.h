/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <ahaloua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:44:40 by ahaloua           #+#    #+#             */
/*   Updated: 2019/07/20 19:27:38 by ahaloua          ###   ########.fr       */
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
	char id;
}		t_tetrim;

typedef struct s_tetris
{
	t_tetrim multi_tab[26];
}		t_tetris;

int		ft_read_tetris(int fd);
int		ft_istertris(const char *str);
int		check_conn(const char *str);
int		ft_check_inlines(const char *str, int r);
void	ft_shift(t_tetrim *one);
void	ft_stock_hashs(char *buff, t_tetrim *one);
void	ft_puttet(t_tetrim one, int ret);
int 	ft_sqrt(int nb);
int 	ft_map_size(int nb);
void	ft_creat_map(char ***map, int size);
void	ft_putmap(char **map);
void	ft_free_map(char **map);
#endif
