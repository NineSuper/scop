/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:14:12 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/08 17:27:02 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

/*      Libft       */
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
/*		String		*/
# define TITLE "SCOP"
/*      Error       */
# define E_ALLOC    "Error: Memory allocation failed."
# define E_MLX      "Error: Mlx initialization failed."
# define E_WIN      "Error: Window initialization failed."
/*		Texture		*/

/*		Color		*/
# define C_GREEN "\033[1;32m"
# define C_RED "\033[1;41m"
# define C_NONE "\033[0m"
/*		Screen Size	 */
# ifndef WIDTH
#  define WIDTH 960
# endif

# ifndef HEIGHT
#  define HEIGHT 540
# endif

typedef struct s_coods
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_coords;

typedef struct s_imgs
{
	void	*win;
	void	*mlx;
	void	*m_img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		l_len;
	int		end;
}	t_imgs;


typedef	struct s_win
{
    char	*title;
    void	*mlx;
    void	*win;
    int		height;
    int		width;
}   t_win;

typedef	struct s_master
{
    t_win	win;   
}	t_master;

//			FUNCTION		//

/*		INIT	*/
void			ft_init_mlx(t_master *s_m, t_win *win);
/*		FREE	*/
void			ft_free_all(t_master *s_m);
void			ft_free_mlx(t_win *win);
/*		DLC	MLX	*/
t_imgs			ft_img_resize(t_master *s_m, t_imgs img, int h, int w);
t_imgs			new_file_img(char *path, t_master *s_m);
t_imgs			new_img(int w, int h, t_master *s_m);
t_coords		ft_coords(int h, int w, int x, int y);
void			ft_put_destroy(t_imgs src, t_imgs dest, int x, int y);
void			ft_rplace(t_master *s_m, t_imgs src, t_imgs dest, t_coords coords);
void			ft_destroy_img(void *mlx, char *img);
void			ft_new_img(t_imgs *img, t_master *s_m, int width, int height);
void			img_pix_put(t_imgs *img, int x, int y, int color);
void			put_pixel_img(t_imgs img, int x, int y, int color);
void			put_img_to_img(t_imgs dst, t_imgs srcs, int x, int y);
unsigned int	get_pixel_img(t_imgs img, int x, int y);
int				ft_check_resized(int base);

//			FUNCTION		//
#endif