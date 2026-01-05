#include "bigint.hpp"

bigint::bigint()
{
	digits = "0";
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	digits = ss.str();
}

bigint::bigint(const bigint& other)
{
	*this = other;
}

static std::string	ft_reverse(std::string digits)
{
	std::string	res = "";

	for (int i = digits.length() - 1; i >= 0; i--)
		res.push_back(digits[i]);
	return res;
};

static std::string	ft_add(const bigint& num1, const bigint& num2)
{
	std::string	str1 = ft_reverse(num1.digits);
	std::string str2 = ft_reverse(num2.digits);
	std::string	res;
	int	len1 = str1.length();
	int	len2 = str2.length();
	int	diff;

	if (len1 < len2)
	{
		diff = len2 - len1;
		while (diff > 0)
		{
			str1.push_back('0');
			diff--;
		}
	}
	else if (len1 > len2)
	{
		diff = len1 - len2;
		while (diff > 0)
		{
			str2.push_back('0');
			diff--;
		}
	}

	int	len = str1.length();
	int	carry = 0;
	int	temp;
	int	digit1;
	int	digit2;

	for (int i = 0; i < len; i++)
	{
		digit1 = str1[i] - '0';
		digit2 = str2[i] - '0';
		temp = digit1 + digit2 + carry;
		if (temp > 9)
		{
			carry = temp / 10;
			res.push_back((temp % 10) + '0');
		}
		else
			res.push_back(temp + '0');
	}
	if (carry)
		res.push_back(carry + '0');
	return (ft_reverse(res));
};

static unsigned int	str2uint(std::string str)
{
	std::stringstream	ss(str);
	unsigned int		res;

	ss >> res;
	return res;
}

bigint&	bigint::operator=(const bigint& other)
{
	digits = other.digits;
	return *this;
}

bigint	bigint::operator+(const bigint& other) const
{
	bigint	copy(other);

	copy.digits = "";
	copy.digits = ft_add(*this, other);
	return copy;
}

bigint&	bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint&	bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint	bigint::operator++(int)
{
	bigint temp = *this;
	*this += bigint(1);
	return temp;
}

bigint	bigint::operator<<(unsigned int num) const
{
	bigint	temp = *this;
	for (int i = 0; i < num; i++)
		temp.digits.push_back('0');
	return temp;
}

bigint	bigint::operator>>(unsigned int num) const
{
	bigint	temp = *this;
	int		len = this->digits.length();
	
	if (num > len)
		temp.digits = "0";
	else
	{
		for (int i = len; i >= len - num; i--)
			temp.digits[i] = 0;
	}
	return temp;
}

bigint&	bigint::operator<<=(unsigned int num)
{
	*this = *this << num;
	return *this;
}

bigint&	bigint::operator>>=(unsigned int num)
{
	*this = *this >> num;
	return *this;
}

bigint	bigint::operator<<(const bigint& other) const
{
	bigint	temp;
	temp = *this << str2uint(other.digits);
	return temp;
}

bigint	bigint::operator>>(const bigint& other) const
{
	bigint	temp;
	temp = *this >> str2uint(other.digits);
	return temp;
}

bigint&	bigint::operator<<=(const bigint& other)
{
	*this = *this << str2uint(other.digits);
	return *this;
}

bigint&	bigint::operator>>=(const bigint& other)
{
	*this = *this >> str2uint(other.digits);
	return *this;
}

bool	bigint::operator==(const bigint& other) const
{
	if (digits == other.digits)
		return true;
	return false;
}

bool	bigint::operator!=(const bigint& other) const
{
	if (digits == other.digits)
		return false;
	return true;
}

bool	bigint::operator<(const bigint& other) const
{
	if (str2uint(digits) < str2uint(other.digits))
		return true;
	return false;
}

bool	bigint::operator>(const bigint& other) const
{
	if (str2uint(digits) > str2uint(other.digits))
		return true;
	return false;
}

bool	bigint::operator<=(const bigint& other) const
{
	if (str2uint(digits) <= str2uint(other.digits))
		return true;
	return false;
}

bool	bigint::operator>=(const bigint& other) const
{
	if (str2uint(digits) >= str2uint(other.digits))
		return true;
	return false;
}

std::ostream&	operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.digits;
	return output;
}
