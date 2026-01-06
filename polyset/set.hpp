#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag&	bag;
	public:
		set() = delete;
		set(const set& source) = delete;
		set&	operator=(const set& source) = delete;

		set(searchable_bag& s_bag);
		~set();

		void	insert(int);
		void	insert(int *array, int size);
		void	print() const;
		void	clear();

		bool	has(int value) const;
		const searchable_bag&	get_bag();
};
