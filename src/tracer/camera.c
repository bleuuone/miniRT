/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 06:33:28 by aelbrahm          #+#    #+#             */
/*   Updated: 2023/12/24 16:51:21 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdlib.h>
#include "vector.h"
#include "library.h"

t_vec	cam_to_world(double matrix[4][4], t_vec *dir)
{
	t_vec	v;

	v.v_x = dir->v_x * matrix[0][0] + dir->v_y * \
	matrix[1][0] + dir->v_z * matrix[2][0];
	v.v_y = dir->v_x * matrix[0][1] + dir->v_y * \
	matrix[1][1] + dir->v_z * matrix[2][1];
	v.v_z = dir->v_x * matrix[0][2] + dir->v_y * \
	matrix[1][2] + dir->v_z * matrix[2][2];
	return (v);
}

void	camera_transform_matrix(t_camera *c)
{
	t_vec	forword;

	forword = c->normalized;
	c->tr_matrix[0][0] = c->right.v_x;
	c->tr_matrix[0][1] = c->right.v_y;
	c->tr_matrix[0][2] = c->right.v_z;
	c->tr_matrix[1][0] = c->up.v_x;
	c->tr_matrix[1][1] = c->up.v_y;
	c->tr_matrix[1][2] = c->up.v_z;
	c->tr_matrix[2][0] = forword.v_x;
	c->tr_matrix[2][1] = forword.v_y;
	c->tr_matrix[2][2] = forword.v_z;
}

void	camera_attributs(t_camera *c)
{
	c->aspect_ratio = (WIDTH > HEIGHT) * ((double)WIDTH / \
	(double)HEIGHT) + (WIDTH <= HEIGHT) * ((double)HEIGHT / (double)WIDTH);
	c->scale = tan(((double)c->v_field * 0.5) * M_PI / 180);
	camera_transform_matrix(c);
}

void	lookat(t_camera *cam)
{
	t_vec	tmp;
	t_vec	forword;

	tmp = (t_vec){0, 1, 0};
	forword = cam->normalized;
	cam->right = cross_product(tmp, forword);
	cam->up = cross_product(forword, cam->right);
	camera_attributs(cam);
}
