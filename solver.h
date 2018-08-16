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

# define LAST_ROW_TYPE unsigned int
# include "map.h"
# include "transform.h"
# include <stdlib.h>

char		initialize(size_t width);
void		parse(char c, t_coord *coord);
t_solution	*get_solution();

#endif
