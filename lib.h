/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:02:28 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/13 11:55:02 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "map.h"
# include "transform.h"

unsigned long	stol(char *s, int num);

void			set(t_coord *c, const t_map *map);

#endif
