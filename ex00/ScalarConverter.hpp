/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:24 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/29 15:04:16 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
public:
	static void convert(const std::string &str);

	class Impossible : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
};

template <typename T>
bool findDecimalPoint(T n)
{
	std::ostringstream oss;
	oss << n;
	std::string s = oss.str();
	return (s.find('.') != std::string::npos);
}

#endif
