/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_mtl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:42:30 by tde-los-          #+#    #+#             */
/*   Updated: 2024/07/11 15:15:16 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void    ft_read_mtl(t_mtl *mtl, int fd)
{
    char    *temp;
    char    buff[4096];
    int     size;
    char    *old_temp;

    temp = ft_calloc(1, 1);
	while ((size = read(fd, buff, sizeof(buff))) > 0)
	{
		old_temp = temp;
		buff[size] = '\0';
		temp = ft_strjoin(temp, buff);
		free(old_temp);
	}
	if (fd > 0)
		close(fd);
	if (temp)
	{
		mtl->file = ft_split(temp, '\n');
		free(temp);
	}
}

void    ft_print_mtl(t_mtl *mtl)
{
    printf("%s[\n", C_BLUE);
    printf("\tNs : %f\n", mtl->Ns);
    printf("\tKa : %f %f %f\n", mtl->Ka[0], mtl->Ka[1], mtl->Ka[2]);
    printf("\tKd : %f %f %f\n", mtl->Kd[0], mtl->Kd[1], mtl->Kd[2]);
    printf("\tKs : %f %f %f\n", mtl->Ks[0], mtl->Ks[1], mtl->Ks[2]);
    printf("\tNi : %f\n", mtl->Ni);
    printf("\td : %f\n", mtl->d);
    printf("\tillum : %d\n", mtl->illum);
    printf("]%s\n", C_NONE);
}

void    ft_read_file_mtl(t_mtl *mtl)
{
    int i;

    i = -1;
    while (mtl->file[++i])
    {
        if (!ft_strncmp(mtl->file[i], "Ns ", 3))
            sscanf(mtl->file[i], "Ns %f", &mtl->Ns);
        else if (!ft_strncmp(mtl->file[i], "Ka ", 3))
            sscanf(mtl->file[i], "Ka %f %f %f", &mtl->Ka[0], &mtl->Ka[1], &mtl->Ka[2]);
        else if (!ft_strncmp(mtl->file[i], "Kd ", 3))
            sscanf(mtl->file[i], "Kd %f %f %f", &mtl->Kd[0], &mtl->Kd[1], &mtl->Kd[2]);
        else if (!ft_strncmp(mtl->file[i], "Ks ", 3))
            sscanf(mtl->file[i], "Ks %f %f %f", &mtl->Ks[0], &mtl->Ks[1], &mtl->Ks[2]);
        else if (!ft_strncmp(mtl->file[i], "Ni ", 3))
            sscanf(mtl->file[i], "Ni %f", &mtl->Ni);
        else if (!ft_strncmp(mtl->file[i], "d ", 2))
            sscanf(mtl->file[i], "d %f", &mtl->d);
        else if (!ft_strncmp(mtl->file[i], "illum ", 6))
            sscanf(mtl->file[i], "illum %d", &mtl->illum);
    }
    ft_print_mtl(mtl);
}

void	ft_init_mtl(t_mtl *mtl, char *dir)
{
	int	fd;

	mtl->dir = ft_strjoin("ressources/", dir);
	fd = open(mtl->dir, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf("%sFile [%s] not found%s\n", C_RED, mtl->dir, C_NONE);
		free(mtl->dir);
		mtl->dir = NULL;
		return ;
	}
	ft_printf("%s[%s]%s\n", C_GREEN, mtl->dir, C_NONE);
    ft_read_mtl(mtl, fd);
    ft_read_file_mtl(mtl);
}