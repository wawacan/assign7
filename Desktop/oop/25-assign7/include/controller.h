#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <chrono>
#include <termios.h>
#include <vector>
#include "view.h"
#include "gameManager.h"

class Controller{

public:
       
    Controller(View&);
    void run();
private:
    Direction inputToDir(int keyInput);
    void update();
    GameManager _game;

    // View
    View& _view; 
};

static struct termios old_termios, new_termios;
void reset_terminal();
void configure_terminal();
int read_input();

#endif
