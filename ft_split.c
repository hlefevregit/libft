/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlefevre <hlefevre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:08:21 by hlefevre          #+#    #+#             */
/*   Updated: 2021/10/28 18:31:09 by hlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wrdcnt(const char *s, char c)
{
	int	wrd;
	int	i;

	i = 0;
	wrd = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			wrd++;
		i++;
	}
	if (s[0] != '\0')
		wrd++;
	return (wrd);
}

char	*ft_getwrd(const char *s, char c, int *i)
{
	char	*d;
	int		k;

	k = 0;
	d = (char *)malloc(sizeof(*d) * ft_strlen(s));
	if (!d)
		return (NULL);
	while (s[*i] && s[*i] != c)
	{
		d[k] = s[*i];
		k++;
		*i = *i + 1;
	}
	d[k] = '\0';
	while (s[*i] && s[*i] == c)
		*i = *i + 1;
	return (d);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		wrd_cnt;
	char	**str;

	i = 0;
	j = 0;
	wrd_cnt = ft_wrdcnt(s, c);
	str = (char **)malloc(sizeof(s) * (wrd_cnt + 1));
	if (!str)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (j < wrd_cnt && s[i])
	{
		str[j] = ft_getwrd(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
