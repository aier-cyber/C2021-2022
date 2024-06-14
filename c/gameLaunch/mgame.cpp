#include "mgame.h"
#include <algorithm>

bool contaitment(int item, std::vector<char> x){
    char char_item = char(item);
    if ( std::find(x.begin(), x.end(), char_item) != x.end() )
        return true;
    else
        return false;
}

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
            if ((contaitment(universe_copy.family_size(i, c), ancestors)) && (this->universe.at(i,c) == 0)){
                this->universe.change_cell(i, c);
                continue;
            }
            if ((this->universe.at(i,c) == 1) && !(contaitment(universe_copy.family_size(i, c), extinction))){
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

