/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 01:41:16 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/28 01:51:27 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 5; ++i)
	{
		Base *base = generate();
		identify(base);
		delete base;
	}
	std::cout << "\nTest identity(Base &p)" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Base *base2 = generate();
		identify(*base2);
		delete base2;
	}
	return (0);
}
