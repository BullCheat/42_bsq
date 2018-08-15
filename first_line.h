/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:42:48 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/14 21:19:06 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LINE_H
# define FIRST_LINE_H
# define CHUNK_SIZE 50
# include "llist.h"
# include "map.h"

t_llist		*read_first_line(int filedes, int *len);
int			copy_first_line(t_llist *list, t_map *map);

#endif
