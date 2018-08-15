/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 11:29:44 by tkobb             #+#    #+#             */
/*   Updated: 2018/08/15 11:29:46 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H
# include "map.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

t_map	*read_map(int filedes);
char	transform(char c, t_map *map);

#endif
