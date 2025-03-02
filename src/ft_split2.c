/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:32:09 by ihajji            #+#    #+#             */
/*   Updated: 2025/03/02 00:02:50 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
int ft_isqoute(char c)
{
	return (c == '"' || c == '\'');
}

static size_t	count_tokens(const char *s, char *charset)
{
	size_t	count;
	char qoute;

	count = 0;
	while (*s)
	{
		while (*s && ft_strchr(charset, *s) && !ft_isqoute(*s))
			s++;
		if (ft_isqoute(*s))
		{
			qoute = *(s++);
			while (*s && *s != qoute)
				s++;
		}
		if (*s)
		{

			printf("%c	\n", *s);
			count++;
		}
		if (ft_isqoute(*s) && *s == qoute)
			s++;
		while (*s && !ft_strchr(charset, *s))
			s++;
	}
	return (count);
}
int main()
{
	// printf("%lu\n", count_tokens("Hello World", " ")); // 2
	// printf("%lu\n", count_tokens("Hello   World", " ")); // 2
	// printf("%lu\n", count_tokens("  Hello   World  ", " ")); // 2
	// printf("%lu\n", count_tokens("Hello,World", ",")); // 2
	// printf("%lu\n", count_tokens("Hello, World", ", ")); // 2
	// printf("%lu\n", count_tokens("Hello,,World", ",")); // 2
	// printf("%lu\n", count_tokens("\"Hello World\"", " ")); // 1
	// printf("%lu\n", count_tokens("\"Hello, World\"", " ")); // 1
	// printf("%lu\n", count_tokens("\"Hello World\" test", " ")); // 2
	// printf("%lu\n", count_tokens("Hello 'World'", " ")); // 2
	// printf("%lu\n", count_tokens("'Hello' 'World'", " ")); // 2
	// printf("%lu\n", count_tokens("\"Hello\" 'World'", " ")); // 2
	// printf("%lu\n", count_tokens("\"Hello 'World'\"", " ")); // 1
	// printf("%lu\n", count_tokens("Hello' 'World", " ")); // 1
	// printf("%lu\n", count_tokens("\"\"Hello World\"\"", " ")); // 2
	// printf("%lu\n", count_tokens("", " ")); // 0
	// printf("%lu\n", count_tokens("    ", " ")); // 0
	// printf("%lu\n", count_tokens("' '", " ")); // 1
	// printf("%lu\n", count_tokens("\" \"", " ")); // 1
	// printf("%lu\n", count_tokens("'Hello \"World\"'", " ")); // 1
	// printf("%lu\n", count_tokens("\"Hello 'World' again\"", " ")); // 1
	// printf("%lu\n", count_tokens("\"Hello, 'World, again'\"", ",")); // 1
	printf("%lu\n", count_tokens("\"Hello\", 'World, again'", ",")); // 2
	printf("%lu\n", count_tokens("\"Hello\", 'World, again', test", ",")); // 3
	printf("%lu\n", count_tokens("test \"Hello, World\" again", ",")); // 2
	printf("%lu\n", count_tokens("test 'Hello, World' again", ",")); // 2
	printf("%lu\n", count_tokens("\"Hello, World\", test", ",")); // 2
}
// hello"dslakjdsa dsaldsalk dsalkjdewq
// -....,,Hello"World Hola"Hi "How"are you		Hola;

// static size_t	get_word_len(const char *s, char c)
// {
// 	size_t	len;
//
// 	len = 0;
// 	while (*s && *s != c)
// 	{
// 		s++;
// 		len++;
// 	}
// 	return (len);
// }
//
// static char	**free_mem(char **list, size_t i)
// {
// 	while (i-- > 0)
// 		free(list[i]);
// 	free(list);
// 	return (NULL);
// }
//
// char	**ft_split2(char const *s, char *charset)
// {
// 	size_t	token_count;
// 	char	**list;
// 	char	*word;
// 	size_t	i;
//
// 	if (!s || !charset)
// 		return (NULL);
// 	i = 0;
// 	token_count = count_token(s, c);
// 	list = ft_calloc(token_count + 1, sizeof(char *));
// 	if (!list)
// 		return (NULL);
// 	while (i < token_count)
// 	{
// 		while (*s == c)
// 			s++;
// 		word = ft_substr(s, 0, get_word_len(s, c));
// 		if (!word)
// 			return (free_mem(list, i));
// 		list[i++] = word;
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	return (list);
// }
