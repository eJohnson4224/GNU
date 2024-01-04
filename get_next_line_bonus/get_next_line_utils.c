/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejohnson <ejohnson@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:21:44 by ejohnson          #+#    #+#             */
/*   Updated: 2023/11/18 23:25:53 by ejohnson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_utils.h"

void	*malloc_and_init(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr != NULL)
	{
		memzero((char *)ptr, size);
	}
	return (ptr);
}

void	memzero(char *buff, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		buff[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	if (!(*s))
		return (NULL);
	while (*s != (const char)c)
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
	void	*set;

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
	// Adding the initialiser to this line fixed the issue you were having
	// The same function has been used now everywhere you were using malloc,
	// which I think is correct.
	address = malloc_and_init(sizeof(char) * (s_len + 1));
	if (!address)
		// May need to return NULL instead
		return (0);
	ft_memcpy(address, (const void *) s, s_len);
	if (!address)
	{
		// This may not be necessary
		free(address);
		address = NULL;
		// May need to return NULL instead
		return (0);
	}
	return ((char *)address);
}
