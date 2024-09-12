/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tron <cle-tron@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:50:32 by cle-tron          #+#    #+#             */
/*   Updated: 2024/09/12 16:21:45 by cle-tron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_data(t_data *data)
{
	free(data->amb->id);
	free(data->amb);


}

int main(int argc, char **argv)
{
	t_data	data;
//	data = malloc(sizeof(t_data));
	(void)argc;
	//check_errors function if(error) return 0;
	init(argv[1], &data);
	print_data(&data);
	free_data(&data);
	return (0);
}
