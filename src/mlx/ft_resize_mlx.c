/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:28:22 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:51 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	ft_check_resized(int base)
{
	if (base <= 1)
		return (1);
	else
		return (base);
}

/*
    *   ft_destroy_img détruit l'image
*/

void	ft_destroy_img(void *mlx, char *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

/*
    *   ft_coords = renvoie une structure avec la 
	*	hauteur/largeur puis les coordonnes x et y
    *   d'un element
*/

t_coords	ft_coords(int h, int w, int x, int y)
{
	t_coords	coords;

	coords.h = h;
	coords.w = w;
	coords.x = x;
	coords.y = y;
	return (coords);
}

/*
    *   ft_rplace = redimensionne une image avec l'aide de ft_coords
    *   puis la place sur une image dest
    *   puis detruit l'image en tempon
*/

void	ft_rplace(t_master *s_m, t_imgs src, t_imgs dest, t_coords coords)
{
	t_imgs	temp;

	temp = ft_img_resize(s_m, src, coords.h, coords.w);
	ft_put_destroy(temp, dest, coords.x, coords.y);
}

/*
	* ft_put_destroy = place une image (src) sur une image (dest) 
	* au coords x et y
	* puis detruit la memoire de l'image source
*/

void	ft_put_destroy(t_imgs src, t_imgs dest, int x, int y)
{
	put_img_to_img(dest, src, x, y);
	ft_destroy_img(src.mlx, src.m_img);
}

/*
    *   ft_img_resize
    *   redimensionne une image avec une hauteur et une largeur defini
*/

t_imgs	ft_img_resize(t_master *s_m, t_imgs img, int h, int w)
{
	t_imgs	img_resized;
	int		x;
	int		y;
	int		color;

	h = ft_check_resized(h);
	w = ft_check_resized(w);
	img_resized = new_img(w, h, s_m);
	y = -1;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
		{
			color = get_pixel_img(img, (x * img.w) / w, (y * img.h) / h);
			put_pixel_img(img_resized, x, y, color);
		}
	}
	return (img_resized);
}
