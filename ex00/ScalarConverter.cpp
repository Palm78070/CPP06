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
	return (s == "-inff" || s == "+inff" || s == "nanf" || s == "-inf" || s == "+inf" || s == "nan" || s == "inf" || s == "inff");
}

bool isNum(const std::string &s)
{
	int i = 0;
	while (s[i] == '+' || s[i] == '-')
		++i;
	if (!std::isdigit(s[i]) && s[i] != '.')
		return (false);
	while (s[i])
	{
		if ((!std::isdigit(s[i]) && s[i] != '.' && s[i] != 'f'))
			return (false);
		if (s[i] == '.')
		{
			if (i >= (int)(s.size()) - 1)
				return (false);
			if (!std::isdigit(s[i + 1]) && s[i + 1] != 'f')
				return (false);
		}
		if (s[i] == 'f' && i < (int)(s.size()) - 1)
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
	double input = atof(s.c_str());

	if (isKeyword(s))
		throw ScalarConverter::Impossible();
	if (isChar(s))
	{
		if (!std::isprint(s[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << s[0] << std::endl;
	}
	else
	{
		if (!isNum(s))
			throw ScalarConverter::Impossible();
		try
		{
			if (!isascii(static_cast<int>(input)))
				throw ScalarConverter::Impossible();
			c = static_cast<int>(input);
		}
		catch (std::exception &)
		{
			throw ScalarConverter::Impossible();
		}
		if (!std::isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << static_cast<char>(c) << std::endl;
	}
}

void printInt(const std::string &s)
{
	int n = 0;
	double input = atof(s.c_str());

	if (s.size() == 1)
	{
		if (std::isdigit(s[0]))
			n = s[0] - '0';
		else
			n = static_cast<int>(s[0]);
		std::cout << n << std::endl;
	}
	else
	{
		if (!isNum(s))
			throw ScalarConverter::Impossible();
		try
		{
			if (input > INT_MAX|| input < INT_MIN)
				throw ScalarConverter::Impossible();
			n = static_cast<int>(input);
		}
		catch (std::exception &)
		{
			throw ScalarConverter::Impossible();
		}
		std::cout << n << std::endl;
	}
}

void printFloat(const std::string &s)
{
	float f = 0;
	double input = atof(s.c_str());

	if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff")
		std::cout << "+inff" << std::endl;
	else if (s == "-inf" || s == "-inff")
		std::cout << "-inff" << std::endl;
	else if (s == "nan" || s == "nanf")
		std::cout << "nanf" << std::endl;
	if (isKeyword(s))
		return;
	else if (s.size() == 1)
	{
		if (std::isdigit(s[0]))
			f = s[0] - '0';
		else
			f = static_cast<float>(s[0]);
		std::cout << f;
	}
	else
	{
		if (!isNum(s))
			throw ScalarConverter::Impossible();
		try
		{
			f = static_cast<float>(input);
		}
		catch (std::exception &)
		{
			throw ScalarConverter::Impossible();
		}
		std::cout << f;
	}
	if (!findDecimalPoint(f) && (f - static_cast<int>(f) == 0))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void printDouble(const std::string &s)
{
	double d = 0;

	if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff")
		std::cout << "+inf" << std::endl;
	else if (s == "-inf" || s == "-inff")
		std::cout << "-inf" << std::endl;
	else if (s == "nan" || s == "nanf")
		std::cout << "nan" << std::endl;
	if (isKeyword(s))
		return;
	else if (s.size() == 1)
	{
		if (std::isdigit(s[0]))
			d = s[0] - '0';
		else
			d = static_cast<double>(s[0]);
		std::cout << d;
	}
	else
	{
		if (!isNum(s))
			throw ScalarConverter::Impossible();
		try
		{
			d = atof(s.c_str());
		}
		catch (std::exception &)
		{
			throw ScalarConverter::Impossible();
		}
		std::cout << d;
	}
	if (!findDecimalPoint(d) && (d - static_cast<int>(d) == 0))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &s)
{
	std::cout << "char: ";
	try
	{
		printChar(s);
	}
	catch (ScalarConverter::Impossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "int: ";
	try
	{
		printInt(s);
	}
	catch (ScalarConverter::Impossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "float: ";
	try
	{
		printFloat(s);
	}
	catch (ScalarConverter::Impossible &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "double: ";
	try
	{
		printDouble(s);
	}
	catch (ScalarConverter::Impossible &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char *ScalarConverter::Impossible::what() const throw()
{
	return ("Impossible");
}
