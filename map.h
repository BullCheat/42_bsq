/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:56:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 11:29:18 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	char		empty;
	char		obstacle;
	char		full;
	int			width;
	int			height;
	char		*tab;
}				t_map;

typedef struct	s_solution
{
	int			x;
	int			y;
	int			len;
}				t_solution;

#endif
