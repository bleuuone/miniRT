/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:06:17 by aahlyel           #+#    #+#             */
/*   Updated: 2023/12/25 17:30:37 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

void	color_range_norm(t_vec *color);
t_vec	raytrace(t_data *data, t_rays *rays, t_hit_record *rec, int level);
void	my_mlx_put(t_mrt *rt, int x, int y, int color);
int		rgb_to_int(t_vec color);
void	prime_ray(int x, int y, t_ray *ray, t_camera *cam);
t_vec	c_color(t_vec f_c, t_vec s_c, double p1, double p2);
int		rgb_to_int(t_vec color);
t_vec	merge_light(t_vec color, t_color light_color, double ratio);
bool	shadow_ray(t_rays *rays, t_light *light, \
t_objects *obj, t_hit_record *rec);
t_vec	specular_light(t_rays *rays, t_light *light, \
t_features speclr, t_hit_record *rec);
t_vec	diffuse_effect(t_rays *rays, t_light *light, t_hit_record *rec);
void	nineties(t_vec *color);
void	checkread_borad(t_objects *obj, t_hit_record *rec);
void	textures_binding(t_objects *shapes, t_mrt *img);
t_vec	get_tex_color(t_texture_img *texture, double u, double v, bool sp);
void	check_color(t_objects *object, t_hit_record *rec);

#endif