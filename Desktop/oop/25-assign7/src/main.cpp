#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "view.h"
#include "controller.h"
#include "AnsiPrint.h"
/**
 * Print my id
 * */
void
PrintMyID(std::string studId) {

    std::string str = "ID: " + studId;
    std::cout << AnsiPrint(str.c_str(),YELLOW,RED, true, true) << std::endl << std::endl;
}



int main(){
    std::srand(std::time(nullptr));
    View view;
    Controller controller(view);
    controller.run();
    PrintMyID("111304056");
}
