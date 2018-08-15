/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transofrm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:50:56 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 16:52:37 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H
# include "map.h"
# include <stdlib.h>
# define ERROR 127

char	transform_to(char c, t_map *map);
char	transform_from(long x, long y, t_map *map, t_solution *solution);

#endif
