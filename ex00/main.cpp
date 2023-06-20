/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:22:37 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/20 22:13:34 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ft_isNum(std::string const &s)
{
	for (int i = 0; s[i] != '0'; ++i)
	{
		if (!std::isdigit(s[i]) && s[i] != '.')
			return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect format => ./convert (argument)" << std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
