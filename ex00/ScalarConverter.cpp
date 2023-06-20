#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
	}
	return (*this);
}

bool isKeyword(const std::string &s)
{
	return (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan");
}

bool isDecimalPoint(const std::string &s, int i)
{
	if (i == 0 || i == (int)(s.size()) - 1 || !std::isdigit(s[i - 1]) || !std::isdigit(s[i + 1]))
		return (false);
	return (true);
}

bool isFDecimal(const std::string &s, int i)
{
	int isDot = 0;
	for (int index = i; index > 0; --index)
	{
		if (s[index] == '.')
		{
			isDot = 1;
			break;
		}
	}
	if (i == 0 || !std::isdigit(s[i - 1]) || !isDot || i < (int)(s.size()) - 1)
		return (false);
	return (true);
}

bool isNum(const std::string &s)
{
	int i = 0;
	while (s[i] == '+' || s[i] == '-')
		++i;
	while (s[i])
	{
		if ((!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f'))
			return (false);
		if (s[i] == '.' && !isDecimalPoint(s, i))
			return (false);
		if (s[i] == 'f' && !isFDecimal(s, i))
			return (false);
		++i;
	}
	return (true);
}

bool isChar(const std::string &s)
{
	return (s.size() == 1 && !std::isdigit(s[0]));
}

void printChar(const std::string &s)
{
	char c = 0;

	if (isKeyword(s))
		throw ScalarConverter::Impossible();
	if (isChar(s))
	{
		if (!std::isprint(s[0]))
			std::cout << "Non printable" << std::endl;
		else
			std::cout << s[0] << std::endl;
	}
	else
	{
		if (!isNum(s))
			throw ScalarConverter::Impossible();
		c = std::stoi(s, 0, 10);
		if (!std::isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(c) << std::endl;
	}
}

void ScalarConverter::convert(const std::string &s)
{
	std::cout << "char: ";
	try
	{
		printChar(s);
	}
	catch (ScalarConverter::Impossible::exception &e)
	{
		std::cout << "Impossible" << std::endl;
	}
}
