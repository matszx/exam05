#include "vect2.hpp"

vect2::vect2()
{
	_x = 0;
	_y = 0;
}

vect2::vect2(int x, int y)
{
	_x = x;
	_y = y;
}

vect2::vect2(const vect2& other)
{
	*this = other;
}

vect2::~vect2() {}

vect2&	vect2::operator=(const vect2& other)
{
	_x = other._x;
	_y = other._y;
	return *this;
}

int		vect2::operator[](int index) const
{
	if (!index)
		return _x;
	return _y;
}

int&	vect2::operator[](int index)
{
	if (!index)
		return _x;
	return _y;
}

vect2	vect2::operator+(const vect2& other) const
{
	int x = _x + other._x;
	int y = _y + other._y;
	return (vect2(x, y));
}

vect2&	vect2::operator++()
{
	_x += 1;
	_y += 1;
	return *this;
}

vect2	vect2::operator++(int)
{
	vect2	temp = *this;
	++(*this);
	return temp;
}

vect2&	vect2::operator+=(const vect2& other)
{
	_x += other._x;
	_y += other._y;
	return *this;
}

vect2	vect2::operator-(const vect2& other) const
{
	int x = _x - other._x;
	int y = _y - other._y;
	return (vect2(x, y));
}

vect2&	vect2::operator--()
{
	_x -= 1;
	_y -= 1;
	return *this;
}

vect2	vect2::operator--(int)
{
	vect2	temp = *this;
	_x -= 1;
	_y -= 1;
	return temp;
}

vect2&	vect2::operator-=(const vect2& other)
{
	_x -= other._x;
	_y -= other._y;
	return *this;
}

vect2	vect2::operator-() const
{
	return vect2(-_x, -_y);
}

vect2	vect2::operator*(int num) const
{
	return vect2(_x * num, _y * num);
}

vect2&	vect2::operator*=(int num)
{
	_x *= num;
	_y *= num;
	return *this;
}

vect2	vect2::operator*(const vect2& other) const
{
	return vect2(_x * other._x, _y * other._y);
}

vect2&	vect2::operator*=(const vect2& other)
{
	_x *= other._x;
	_y *= other._y;
	return *this;
}

bool	vect2::operator==(const vect2& other) const
{
	if (_x == other._x && _y == other._y)
		return true;
	return false;
}

bool	vect2::operator!=(const vect2& other) const
{
	if (_x != other._x || _y != other._y)
		return true;
	return false;
}

std::ostream&	operator<<(std::ostream& output, const vect2& obj)
{
	std::cout << "{" << obj[0] << ", " << obj[1] << "}";
	return output;
}

vect2	operator*(int num, const vect2& other)
{
	return vect2(other._x * num, other._y * num);
}
