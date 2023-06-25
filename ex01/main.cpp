/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:48:44 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/25 22:20:15 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdio.h>

int main(void)
{
	Data *data = (Data *)malloc(sizeof(Data));
	Data *data2 = NULL;
	uintptr_t n;

	data->name = "Palm";
	std::cout << "data name is " << data->name << std::endl;
	n = Serializer::serialize(data);
	std::cout << "Serializer n is " << n << std::endl;
	data2 = Serializer::deserialize(n);
	std::cout << "data2 name is " << data2->name << std::endl;
	if (data == data2)
		std::cout << "data is the same address as data2" << std::endl;
	printf("address of data is %p\n", data);
	printf("address of data2 is %p\n", data2);
	if (data)
	{
		std::cout << "free data" << std::endl;
		free(data);
	}
	return (0);
}
