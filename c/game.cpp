#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

char field_case = {};
std::vector<std::string> commands = { "dump", "tick", "exit", "help" };

std::vector<char> ancestors_copy;
std::vector<char> extinction_copy;

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

custom_field::custom_field(){
}
//< v v v v > - x is first coordinate, (0,0) is left/bottom corner
custom_field::custom_field(int weight, int height){
    std::vector<char> resize_helper;
    resize_helper.resize(height, 0);
    this->field.resize(weight, resize_helper);
}

custom_field::custom_field(const custom_field& a){
    this->field = a.field;
}

char custom_field::at(int x, int y){
    return (this->field.at(x)).at(y);
}

void custom_field::change_cell(int x, int y){
    if((this->field.at(x)).at(y)){
        (this->field.at(x)).at(y) = 0;
    }
    else{
        (this->field.at(x)).at(y) = 1;
    }
}

int custom_field::size_x(){
    return this->field.size();
}

int custom_field::size_y(){
    return (this->field.at(0)).size();
}


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

mgame::mgame(){
}

mgame::mgame(const custom_field& a){
    this->universe = a;
}

int mgame::family_size(int x, int y){
    int res = 0;
    int curr_x;
    int curr_y;
    for (int a = x-1; a < x+2; a++){
        for (int b = y-1; b < y+2; b++){
            if ((a == x) && (b == y)){
                continue;
            }
            curr_x = a;
            curr_y = b;
            if (a == -1){
                curr_x = this->universe.size_x()-1;
            }
            if (a == this->universe.size_x()){
                curr_x = 0;
            }
            if (b == -1){
                curr_y = this->universe.size_y()-1;
            }
            if (b == this->universe.size_y()){
                curr_y = 0;
            }
            if (this->universe.at(curr_x, curr_y)){
                res++;
            }
        }
    }
    return res;
}

void mgame::born_die(std::vector<char> ancestors, std::vector<char> extinction){
    custom_field copied(this->universe);
    mgame universe_copy(copied);
    for (int i = 0; i < this->universe.size_x(); i++){
        for (int c = 0; c < this->universe.size_y(); c++){
            if ((universe_copy.family_size(i, c) == 3) && (this->universe.at(i,c) == 0)){
                this->universe.change_cell(i, c);
            }
            if ((this->universe.at(i,c) == 1) && ((universe_copy.family_size(i, c) < 2) || (universe_copy.family_size(i, c) > 3))){
                    this->universe.change_cell(i, c);
            }
        }
    }
}

void mgame::show_universe(){
    std::string field_mask = "";
    for (int i = this->universe.size_y()-1; i > -1; i--){
        for (int c = 0; c < this->universe.size_x(); c++){
            if (this->universe.at(c,i) == 1){
                field_mask.append("0");
            }
            else{
                field_mask.append(".");
            }
        }
        field_mask.append("\n");
    }
    std::cout << field_mask << std::endl;
}

void mgame::hold(){
    for (int i = 0; i < 30000000; i++){
            i++;
    }
}

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

controller::controller(const mgame& x){
    this->GameState = x;
}

void controller::Full_Step(int i){
    if (i == -1){
        while(1){
            this->GameState.show_universe();
            this->GameState.born_die(this->ancestors, this->extinction);
            this->GameState.hold();
        }
    }
    else{
        this->GameState.show_universe();
        while(i > 0){
            this->GameState.hold();
            this->GameState.born_die(this->ancestors, this->extinction);
            this->GameState.show_universe();
        }
    }
}

void controller::add_ancestor(char x){
    this->ancestors.push_back(x);
}

void controller::add_extinction(char x){
    this->extinction.push_back(x);
}

int main(){

    std::cout << "Type 0 if you don't want to give any file" << std::endl;
    std::cout << "Otherwise type full path to file" << std::endl;

    std::string fPath;
    std::cin >> fPath;
    if (fPath == "0"){
        custom_field null_enter(10, 10);
        null_enter.change_cell(1, 3);
        null_enter.change_cell(2, 2);
        null_enter.change_cell(2, 1);
        null_enter.change_cell(1, 1);
        null_enter.change_cell(0, 1);
        mgame gtest(null_enter);
        controller beq(gtest);
        while(1){
            beq.Full_Step(-1);
        }
    }
    else{
        std::ifstream ifile(fPath);
        while (ifile.is_open() == 0){
            std::cout << "Search error" << std::endl;
            std::cout << "No such file or directory" << std::endl;
            std::cout << "Try again" << std::endl;
            std::string fPath;
            std::cin >> fPath;
            std::ifstream ifile(fPath);
        }
        char curr;
        for (int u = 0; u < 3; u++){
            ifile >> curr;
            if (curr == '#'){
                ifile >> curr;
                if (curr == 'N'){

                }
                if (curr == 'S'){

                }
                if (curr == 'R'){

                }
            }
            else{
                std::cout << "File parsing error: wrong format" << std::endl;
            }
        }
    }
    return 0;
}
