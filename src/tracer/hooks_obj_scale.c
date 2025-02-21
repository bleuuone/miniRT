/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_obj_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbrahm <aelbrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:13:59 by aelbrahm          #+#    #+#             */
/*   Updated: 2023/12/13 12:22:21 by aelbrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minirt.h"
#include "library.h"

static void	sphere_scale(t_data *data, int key)
{
	t_objects	*obj;

	obj = data->objects;
	while (obj)
	{
		if (obj->type == SPHERE)
		{
			if (key == 27)
				((t_sphere *)obj->object)->diameter -= 0.1;
			else if (key == 24)
				((t_sphere *)obj->object)->diameter += 0.1;
		}
		obj = obj->next;
	}
}

static void	cy_scale(t_data *data, int key)
{
	t_objects	*obj;
	t_cylender	*c;

	obj = data->objects;
	while (obj)
	{
		if (obj->type == CYLENDER)
		{
			c = obj->object;
			if (key == 27)
			{
				((t_cylender *)obj->object)->height -= 0.1;
				calculate_disk_plan(c, c->p_face, true);
				calculate_disk_plan(c, c->p_face->next, false);
			}
			else if (key == 24)
			{
				((t_cylender *)obj->object)->height += 0.1;
				calculate_disk_plan(c, c->p_face, true);
				calculate_disk_plan(c, c->p_face->next, false);
			}
		}
		obj = obj->next;
	}
}

void	scale(int key, t_data *data)
{
	if (data->shape == SPHERE)
		sphere_scale(data, key);
	else if (data->shape == CYLENDER)
		cy_scale(data, key);
	draw(*data, data->m_rt);
}
