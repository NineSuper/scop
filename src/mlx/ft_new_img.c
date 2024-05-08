/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:34:58 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:49 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	put_pixel_img(t_imgs img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.l_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_imgs img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.l_len) + (x * img.bpp / 8))));
}

/*	
	*	new_file_img = crée une nouvelle image à partir d'un fichier
*/

t_imgs	new_file_img(char *path, t_master *s_m)
{
	t_imgs	image;

	image.win = s_m->win.win;
	image.mlx = s_m->win.mlx;
	image.m_img = mlx_xpm_file_to_image(s_m->win.mlx, path, &image.w, &image.h);
	if (!image.m_img)
	{
		printf("\033[1;41mERROR: %s n'existe pas\033[00m\n", path);
		ft_free_all(s_m);
	}
	image.addr = mlx_get_data_addr(image.m_img, &(image.bpp),
			&(image.l_len), &(image.end));
	return (image);
}


/*
	*	img_pix_put = mets une image sur une image
*/

void	img_pix_put(t_imgs *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->l_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->end != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/*
	*	ft_new_img = crée une nouvelle image
	*	avec une taille prédéfinie
*/

void	ft_new_img(t_imgs *img, t_master *s_m, int width, int height)
{
	if (img->m_img)
		mlx_destroy_image(s_m->win.mlx, img->m_img);
	img->m_img = mlx_new_image(s_m->win.mlx, width, height);
	img->addr = mlx_get_data_addr(img->m_img, &img->bpp, \
		&img->l_len, &img->end);
}
