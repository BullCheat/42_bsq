/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrean <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:53:28 by adrean            #+#    #+#             */
/*   Updated: 2018/08/15 16:53:29 by adrean           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

# define LAST_ROW_TYPE unsigned short
# include "map.h"
# include <stdlib.h>

void		initialize(size_t width);
void		parse(char c, long x, long y);
t_solution	*get_solution();

#endif
