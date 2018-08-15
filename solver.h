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

# include "map.h"
# include <stdlib.h>

void		initialize(int width);
void		parse(char c, int x, int y);
t_solution	*get_solution();

#endif
