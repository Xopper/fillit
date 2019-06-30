/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 22:17:10 by ahaloua           #+#    #+#             */
/*   Updated: 2019/05/21 22:19:19 by ahaloua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int nb)
{
	return (nb >= 0 ? nb : -nb);
}
