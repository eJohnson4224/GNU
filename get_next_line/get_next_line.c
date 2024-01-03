/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:47:02 by ejohnson          #+#    #+#             */
/*   Updated: 2023/11/14 16:01:58 by ejohnson         ###   ########.fr       */
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
	int	bytes;
	int	sentry;

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
	char		*line;
	// ??? static char	*line;

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
	static char	*backup;
	char		*buff;
	char		*line;

	buff = NULL;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free (buff);
		return (NULL);
	}
	backup = read_backup(fd, buff, backup);
	if (!backup)
	{
		free (backup);
		free (buff);
		return (NULL);
	}
	line = make_line(backup);
	backup = new_backup(backup);
	return (line);
}