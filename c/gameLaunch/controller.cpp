#include "controller.h"

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
