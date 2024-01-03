/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:43:42 by ejohnson          #+#    #+#             */
/*   Updated: 2023/11/18 23:43:48 by ejohnson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../get_next_line_utils.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	char	*ptr;

	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	s1 = NULL;
	return (ptr);
}

static char	*read_backup(int fd, char *buff, char *backup)
{
	long	bytes;
	int sentry;

	bytes = 1;
	sentry = 1;
	while (bytes != 0 && sentry == 1)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buff[bytes] = '\0';
		backup = ft_strjoin(backup, buff);
		if (!backup)
		{
			free(buff);
			return (NULL);
		}
		if (ft_strchr(buff, '\n'))
			sentry = 0;
	}
	free(buff);
	return (backup);
}

static char	*make_line(char *backup)
{
	int			i;
	static char	*line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	ft_strlcpy(line, backup, i + 2);
	if (line[0] == '\0')
	{
		free (line);
		line = NULL;
		return (NULL);
	}
	return (line);
}

static char	*new_backup(char *backup)
{
	int		i;
	char	*backup_new;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup_new = (char *)malloc(sizeof(char) * ((ft_strlen(backup) - i) + 1));
	if (!backup_new)
	{
		free(backup_new);
		backup_new = NULL;
		return (NULL);
	}
	ft_strlcpy(backup_new, backup + (i + 1), ((ft_strlen(backup) - i) + 1));
	free(backup);
	backup = NULL;
	return (backup_new);
}

char	*get_next_line(int fd)
{
	static char	*backup[FD_MAX];
	char		*buff;
	char		*line;

	buff = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	backup[fd] = read_backup(fd, buff, backup[fd]);
	if (!backup[fd])
	{
		free (backup[fd]);
		free (buff);
		return (NULL);
	}
	line = make_line(backup[fd]);
	backup[fd] = new_backup(backup[fd]);
	return (line);
}
