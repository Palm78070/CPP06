/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:24 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/26 01:52:42 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>

// template <typename T>

class ScalarConverter
{
public:
	static void convert(const std::string &str);

	class Impossible : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Impossible"; }
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
};

#endif
