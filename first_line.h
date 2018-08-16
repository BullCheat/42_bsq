/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:42:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 11:33:24 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LINE_H
# define FIRST_LINE_H
# define CHUNK_SIZE 1024
# include "llist.h"
# include "map.h"
# include "lib.h"
# include "read_map.h"
# include "transform.h"
# include "solver.h"

t_llist		*read_first_line(int filedes, unsigned long *len);
int			copy_first_line(t_llist *list, const t_map *map);

#endif
