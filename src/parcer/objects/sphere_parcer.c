/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:21:00 by aahlyel           #+#    #+#             */
/*   Updated: 2023/08/02 00:16:33 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "parcer.h"
#include "tools.h"
#include "libft.h"
#include "library.h"
#include <stdbool.h>
#include <limits.h>

bool sphere_parcer(char *line, t_data *data)
{
	t_objects	*obejct;
	t_sphere	*sphere;
	bool		success;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (false);
	success = true;
	line += 3;
	line += skip_spaces(line);
	if (!cordinate_parcer(&line, &sphere->cord, INT_MAX, INT_MIN))
		return (ft_putendl_fd("minirt: invalid cordinate format", 2), false);
	line += skip_spaces(line);
	sphere->diameter = ft_atod(&line, &success, INT_MAX, INT_MIN);
	if (!success)
		return (ft_putendl_fd("minirt: invalid diameter format", 2), false);
	line += skip_spaces(line);
	if (!color_parcer(line, &sphere->clr))
		return (false);
	obejct = newobject(sphere, SPHERE);
	addobject_front(&data->objects, obejct);
	return (true);
}