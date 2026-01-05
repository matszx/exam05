#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

class bigint
{
	public:
		std::string digits;

		bigint();
		bigint(unsigned int num);
		bigint(const bigint& src);
		//~bigint();
		
		bigint&	operator=(const bigint& other);

		bigint	operator+(const bigint& other) const;
		bigint&	operator+=(const bigint& other);

		bigint&	operator++();
        bigint	operator++(int);

		bigint  operator<<(unsigned int num) const;
		bigint  operator>>(unsigned int num) const;
		bigint&	operator<<=(unsigned int num);
		bigint&	operator>>=(unsigned int num);

        bigint	operator<<(const bigint& other) const;
        bigint	operator>>(const bigint& other) const;
        bigint&	operator<<=(const bigint& other);
        bigint&	operator>>=(const bigint& other);

		bool	operator==(const bigint& other) const;
		bool    operator!=(const bigint& other) const;
		bool    operator<(const bigint& other) const;
		bool    operator>(const bigint& other) const;
		bool    operator<=(const bigint& other) const;
		bool    operator>=(const bigint& other) const;
};

std::ostream&	operator<<(std::ostream& output, const bigint& obj);
