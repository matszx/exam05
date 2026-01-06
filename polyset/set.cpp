#include "set.hpp"
#include "searchable_array_bag.hpp"

set::set(searchable_bag& s_bag): bag(s_bag) {}

set::~set() {}

void	set::insert(int value)
{
	if (!has(value))
		bag.insert(value);
}

void	set::insert(int *array, int size)
{
	for (int i = 0; i < size; i++)
		this->insert(array[i]);
}

void	set::print() const
{
	bag.print();
}

void	set::clear()
{
	bag.clear();
}

bool	set::has(int value) const
{
	return bag.has(value);
}

const searchable_bag&	set::get_bag()
{
	return bag;
}
