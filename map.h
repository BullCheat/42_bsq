/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 14:56:03 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 15:00:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
typedef struct	map
{
	char		empty;
	char		obstacle;
	char		full;
	int			width;
	int			height;
	char		*tab;
}				map;

typedef struct	solution
{
	int			x;
	int			y;
	int			len;
}				solution;
#endif