/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <rthammat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:20:24 by rthammat          #+#    #+#             */
/*   Updated: 2023/06/20 22:09:25 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <cstring>
#include <cctype>

class ScalarConverter
{
public:
	static void convert(const std::string &str);
	// static char getChar(void);
	// static int getInt(void);
	// static float getFloat(void);
	// static double getDouble(void);
	// static void convertChar(const std::string &s);

	class Impossible : public std::exception
	{
	public:
		virtual const char *what() const throw() { return "Impossible"; }
	};

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
	// static std::string _input;
	// static char _c;
	// static int _n;
	// static float _f;
	// static double _d;
};

#endif
