#include "mgame.h"

class controller{
public:
    controller(const mgame& x);
    ~controller() = default;

    void Full_Step(int);
    void add_ancestor(char);
    void add_extinction(char);

    void dump();
    void tick();
    void exit();
    void help();
private:
    std::vector<char> ancestors;
    std::vector<char> extinction;
    mgame GameState;
};
