/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:47:20 by ejohnson          #+#    #+#             */
/*   Updated: 2023/11/18 22:54:48 by ejohnson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!(*s))
		return (NULL);
	while (*s != (const char) c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (*c)
	{
		c++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dest_size)
	{
		i = 0;
		while (src[i] != '\0' && i < (dest_size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < dest_size)
	{
		++i;
		*dest++ = *src++;
	}
	if (i < dest_size)
		*dest = '\0';
	while (*src++)
		++i;
	return (i);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t leng)
{
	void	*set;

	if (!dest && !src)
		return (0);
	set = dest;
	while (leng--)
		*(char *)dest++ = *(char *)src++;
	return (set);
}

char	*ft_strdup(const char *s)
{
	void	*address;
	size_t	s_len;

	s_len = ft_strlen(s);
	address = malloc(sizeof(char) * (s_len + 1));
	if (!address)
		return (0);
	ft_memcpy(address, (const void *) s, s_len);
	if (!address)
	{
		free (address);
		address = NULL;
		return (0);
	}
	return ((char *)address);
}
