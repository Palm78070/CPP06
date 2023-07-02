/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 00:49:08 by rthammat          #+#    #+#             */
/*   Updated: 2023/07/02 18:47:29 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base *generate(void)
{
	int n = rand();

	if (n % 2 == 0)
	{
		std::cout << "generate class A" << std::endl;
		return (new A());
	}
	else if ((n % 2 != 0) && (n % 10 < 5))
	{
		std::cout << "generate class B" << std::endl;
		return (new B());
	}
	std::cout << "generate class C" << std::endl;
	return (new C());
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return;
	}
	catch (...){}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return;
	}
	catch (...){}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(...){}
}
