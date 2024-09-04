/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/04 15:57:00 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char **argv)
{
	(void)argc;
	if (ft_isspace(' '))
		printf("libftok\n");
	init(argv[1]);
	return (0);
}
