#include "custom_field.h"
#include <string>
#include <iostream>

bool contaitment(int item, std::vector<char> x);

class mgame{
public:
    mgame();
	mgame(const custom_field& a);
	~mgame() = default;

	int family_size(int, int);
	void born_die(std::vector<char>, std::vector<char>);

	void show_universe();

	void hold();
private:
    custom_field universe;
};

