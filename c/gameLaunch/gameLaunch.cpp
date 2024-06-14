#include "controller.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

std::vector<std::string> commands = { "dump", "tick", "exit", "help" };

std::vector<char> ancestors_copy;
std::vector<char> extinction_copy;

std::string space_name;

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
        beq.add_ancestor(3);
        beq.add_extinction(2);
        beq.add_extinction(3);
        beq.Full_Step(-1);
    }
    else{
        int x_len = 0;
        int y_len = 0;
        std::ifstream ifile(fPath);
        if (ifile.is_open() == 0){
            throw std::invalid_argument("Error: search failed - no such file or directory");
        }
        char curr;
        ifile >> curr;
        if (curr == '#'){
            ifile >> curr;
            if (curr == 'N'){
                std::getline (ifile, space_name);
                while(curr != '#'){
                    space_name.push_back(curr);
                    ifile >> curr;
                }
            }
            else{
                throw std::invalid_argument("Error: wrong format of first line");
            }
            ifile >> curr;
            if (curr == 'S'){
                ifile >> curr;
                while(curr != 'x'){
                    if ((curr < 48) || (curr > 57)){
                        throw std::invalid_argument("Error: wrong format of second line - can contain only numbers");
                    }
                    x_len = x_len * 10 + (int(curr)-48);
                    ifile >> curr;
                }
                ifile >> curr;
                while(curr != '#'){
                    if ((curr < 48) || (curr > 57)){
                        throw std::invalid_argument("Error: wrong format of second line - can contain only numbers");
                    }
                    y_len = y_len * 10 + (int(curr)-48);
                    ifile >> curr;
                }
                if ((x_len < 2) || (y_len < 2)){
                    throw std::invalid_argument("Error: wrong format of second line - dimensions must be greater then 1");
                }
            }
            else{
                throw std::invalid_argument("Error: wrong format of second line");
            }
            ifile >> curr;
            if (curr == 'R'){
                ifile >> curr;
                if (curr == 'B'){
                    ifile >> curr;
                    while(curr != '/'){
                        if ((curr < 48) || (curr > 57)){
                            throw std::invalid_argument("Error: wrong format of third line");
                        }
                        ancestors_copy.push_back(char(curr-48));
                        ifile >> curr;
                    }
                    if (ancestors_copy.size() == 0){
                        throw std::invalid_argument("Error: must be at least one rule for cell generation");
                    }
                }
                else{
                    throw std::invalid_argument("Error: wrong format of third line");
                }
                ifile >> curr;
                if (curr == 'S'){
                    ifile >> curr;
                    while ((int(curr) > 47) && (int(curr) < 58)){
                        extinction_copy.push_back(char(curr-48));
                        ifile >> curr;
                    }
                    if (extinction_copy.size() == 0){
                        throw std::invalid_argument("Error: must be at least one rule for cell survivability");
                    }
                }
                else{
                    throw std::invalid_argument("Error: wrong format of third line");
                }
            }
            else{
                throw std::invalid_argument("Error: wrong format of third line");
            }
        }
        else{
            throw std::invalid_argument("Error: wrong format of first line");
        }
        custom_field global_space(x_len, y_len);
        for (int i = (y_len - 1); i >= 0; i--){
            for (int c = 0; c < x_len; c++){
                if (curr == 'a'){
                    global_space.change_cell(c, i);
                }
                else{
                    if (curr != '.'){
                        throw std::invalid_argument("Error: wrong format of field - use only 'a' or '.' characters");
                    }
                }
                ifile >> curr;
            }
        }
        mgame construct(global_space);
        controller Launcher(construct);
        for (int i = 0; i < int(ancestors_copy.size()); i++){
            Launcher.add_ancestor(ancestors_copy.at(i));
        }
        for (int i = 0; i < int(extinction_copy.size()); i++){
            Launcher.add_extinction(extinction_copy.at(i));
        }
        std::cout << space_name << std::endl;
        Launcher.Full_Step(-1);
    }
    return 0;
}
/*

*/
