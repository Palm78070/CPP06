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
			std::cout << "Non displayable" << std::endl;
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

void printInt(const std::string &s)
{
	int n = 0;

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
		n = std::stoi(s, 0, 10);
		std::cout << n << std::endl;
	}
}

template <typename T>
bool findDecimalPoint(T n)
{
	std::ostringstream oss;
	oss << n;
	std::string s = oss.str();
	return (s.find('.') != std::string::npos);
}

void printFloat(const std::string &s)
{
	float f = 0;

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
		f = std::stof(s, 0);
		std::cout << f;
	}
	if (!findDecimalPoint(f))
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
		d = std::stod(s, 0);
		std::cout << d;
	}
	if (!findDecimalPoint(d))
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
	catch (ScalarConverter::Impossible::exception &e)
	{
		std::cout << "Impossible" << std::endl;
	}
	std::cout << "int: ";
	try
	{
		printInt(s);
	}
	catch (ScalarConverter::Impossible::exception &e)
	{
		std::cout << "Impossible" << std::endl;
	}
	std::cout << "float: ";
	try
	{
		printFloat(s);
	}
	catch (ScalarConverter::Impossible::exception &e)
	{
		std::cout << "Impossible" << std::endl;
	}
	std::cout << "double: ";
	try
	{
		printDouble(s);
	}
	catch (ScalarConverter::Impossible::exception &e)
	{
		std::cout << "Impossible" << std::endl;
	}
}
