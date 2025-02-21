/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:23:34 by aahlyel           #+#    #+#             */
/*   Updated: 2023/12/16 16:06:14 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parcer.h"
#include "tools.h"
#include "libft.h"
#include "library.h"
#include <stdbool.h>
#include <limits.h>

bool	camera_parcer(char *line, t_data *data)
{
	static bool	visited;
	int			i;

	if (!line && !data)
		return (visited);
	if (visited)
		return (ft_putendl_fd(ERR_C_DUP, 2), false);
	visited = true;
	line += 2;
	if (!cordinate_parcer(&line, &data->camera.cord, INT_MAX, INT_MIN))
		return (ft_putendl_fd(ERR_C_CORD, 2), false);
	if (!cordinate_parcer(&line, &data->camera.normalized, 1, -1))
		return (ft_putendl_fd(ERR_C_N, 2), false);
	line += skip_spaces(line);
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[skip_spaces(line + i) + i])
		return (ft_putendl_fd(ERR_C_VF, 2), false);
	data->camera.v_field = (unsigned char)ft_atoi(line);
	return (true);
}
