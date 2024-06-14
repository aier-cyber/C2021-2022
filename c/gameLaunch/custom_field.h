#include <vector>
class custom_field{
public:
    custom_field();
    custom_field(int, int);
    custom_field(const custom_field&);
    ~custom_field() = default;

    char at(int, int);
    void change_cell(int, int);
    int size_x();
    int size_y();
private:
    std::vector<std::vector<char>> field;
};

