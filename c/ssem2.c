#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>
#include <numeric>
#include <string>
#include <functional>

class Str
{
public:
	using refenrce = char&;
	using const_refenrce = char;

	friend std::ostream& operator<<(std::ostream& ss, const Str& str);
	Str(const char* buf)
	{
		this->size = strlen(buf);
		arr = new char[size + 1];
		memcpy(arr, buf, (size + 1) * sizeof(char));
	}
	~Str()
	{
		delete[] arr;
	}

	char& operator[](size_t index)
	{
		//for (size_t i = 0; i < size; i++)
		//{
		//	if (index == 0)
		//	{
		//		return arr[i];
		//	}
		//	if (arr[i] == ' ')
		//	{
		//		--index;
		//	}
		//}
		//return arr[size+1];
		return arr[index];

	}
	const char& operator[](size_t index) const
	{
		return const_cast<Str*>(this)->operator[](index);
	}

	//refenrce operator[](size_t index)
	//{
	//	return const_cast<char&>(const_cast<const Str*>(this)->operator[](index));
	//}
	//const_refenrce operator[](size_t index) const
	//{
	//	return arr[index];
	//}

	class iterator
	{
		char* pos;
		std::string d;
	public:
		iterator(char* pos_, std::string dilim )
			: pos(pos_), d(dilim)
		{
		}
		iterator(char* pos_)
			: pos(pos_), d(" ")
		{
		}
		~iterator() = default;

		iterator& operator++()
		{
			while (*pos != ' ' && *pos != '\0')
			{
				pos++;
			}
			pos++;
			return *this;
		}
		bool operator==(const iterator& rh)
		{
			return pos == rh.pos;
		}
		bool operator!=(const iterator& rh)
		{
			return !(*this == rh);
		}
		Str operator*()
		{
			char buf[1000];
			char* p = pos;
			size_t i;
			for (i = 0; *p != ' '; i++, ++p)
			{
				buf[i] = *p;
			}
			buf[i] = '\0';
			return Str(buf);
		}
	};

	iterator begin()
	{
		return iterator(arr, std::string("., "));
	}
	iterator end()
	{
		return iterator(&(arr[size]));
	}


private:
	//char& get(size_t index) const
	//{
	//	return arr[index];
	//}

	char* arr;
	size_t size;
};

std::ostream& operator<<(std::ostream& ss, const Str& str)
{
	ss << std::string(str.arr);
	return ss;
}


void f(const Str& str)
{
	char c = str[0];
	//str[0] = 'z';
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char buf[1000];
	gets_s(buf);
	//scanf("%s", &buf);
	Str str(buf);

	//for (size_t i = 0; i < 3; i++)
	//{
	//	printf("%c\n", str[i]);
	//}

	for (auto it = str.begin(); it != str.end(); ++it)
	{
		auto e = *it;
		//printf("%s\n", e);
	}

	for (auto e : str)	//e == *it
	{
		//printf("%s\n", e);

		std::cout << e << std::endl;

	}


	return 0;
}
