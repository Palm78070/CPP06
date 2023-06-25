/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 01:41:16 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/26 01:48:39 by rthammat         ###   ########.fr       */
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
	return (0);
}
