/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:00:57 by tde-los-          #+#    #+#             */
/*   Updated: 2024/05/28 13:58:35 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*
	TODO	Créer des objets 3D sur blender
	TODO	Parser les objets
	TODO	Faire une fenêtre avec SDL2
	*	Apprendre à regarder les leaks sans voir les erreurs génerés \
		automatiquement via OpenGL
	*	Faire des évènements sur la fenêtre
	*	Mettre un cube via OpenGL sur la fenêtre SDL2 
	TODO	Afficher un cube fait sur blender
	TODO	Faire un HUD
*/

int	ft_args(int argc, char **argv, t_master *s_m)
{
	if (argc == 2)
	{
		if (argv[1] && argv[1][0] && ft_strlen(argv[1]) > 4)
		{
			if (ft_strnstr(argv[1] + ft_strlen(argv[1] + 4), ".obj", 4))
			{
				s_m->object.dir = ft_strdup(argv[1]);
				ft_printf("%s[%s]%s\n", C_GREEN, s_m->object.dir, C_NONE);
				return (0);
			}
		}
	}
	ft_printf("%s%s%s\n", C_RED, B_ARG, C_NONE);
	return (1);
}

int	main(int argc, char **argv)
{
	t_master	*s_m;

	s_m = ft_calloc(1, sizeof(t_master));
	if (!s_m)
		return (ft_printf("%s%s%s\n", C_RED, E_ALLOC, C_NONE));
	if (ft_args(argc, argv, s_m) || ft_parse_obj(&s_m->object))
		ft_free_all(s_m);
	ft_init_window(s_m);
	ft_sdl_loop(s_m);
	ft_free_all(s_m);
	return (0);
}

// ft_test((t_win){.height = 5});
