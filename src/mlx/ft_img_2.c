/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:34:01 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:59 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	put_img_to_img(t_imgs dst, t_imgs srcs, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < srcs.w)
	{
		j = -1;
		while (++j < srcs.h)
			put_pixel_img(dst, x + i, y + j, get_pixel_img(srcs, i, j));
	}
}

/*	
	*	t_imgs	new_img = crée une image vierge
	*	avec une hauteur prédéfinie
*/

t_imgs	new_img(int w, int h, t_master *s_m)
{
	t_imgs	image;

	image.win = s_m->win.win;
	image.mlx = s_m->win.mlx;
	image.m_img = mlx_new_image(s_m->win.mlx, w, h);
	image.addr = mlx_get_data_addr(image.m_img, &(image.bpp),
			&(image.l_len), &(image.end));
	image.w = w;
	image.h = h;
	return (image);
}
