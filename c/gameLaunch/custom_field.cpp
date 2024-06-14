#include "custom_field.h"

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
