#include <iostream>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <termios.h>
#include <chrono>
#include "environment.h"
#include "controller.h"
#include "gameManager.h"
#include "gameObjectFactory.h"

Controller::Controller(View& view) : _view(view){
}

void Controller::run() {
    // initial setup
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    configure_terminal();

    // init state
    int input = -1;
    clock_t start, end;
    // Main loop
    while (true) {
        start = clock();
        // game loop goes here
        input = read_input();
        // ESC to exit program
        if(input==27)break;

        Direction dir = inputToDir(input);
        if (dir != NONE){
            _game.handleInput(dir);
        }

        _game.update();
        _view.resetLatest();
        _game.updateView(_view);
        // _view.updateGameObject(obj);
        _view.render();

        if (_game.isGameOver()) {
            std::cout << "\nGame Over. You lose.\n" << std::flush;

            // 清除這行訊息
            std::cout << "\r\033[K" << std::flush;
            break;
        }
        if (_game.isWin()) {
            std::cout << "\nYou Win!\n" << std::flush;

            // 清除這行訊息
            std::cout << "\r\033[K" << std::flush;
            break;
        }

        end = clock();
        // frame rate normalization
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        if(time_taken > SPF) continue;
        int frameDelay = int((SPF - time_taken) * 1000); // 0.1 seconds
        if(frameDelay > 0) std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay)); // frame delay
    }
}


Direction Controller::inputToDir(int keyInput){
    if(keyInput == -1)return NONE;

    if(keyInput == 'w' || keyInput == 'W'){
        return UP;
    }

    if(keyInput == 'a' || keyInput == 'A'){
        return LEFT;
    }

    if(keyInput == 's' || keyInput == 'S'){
        return DOWN;
    }

    if(keyInput == 'd' || keyInput == 'D'){
        return RIGHT;
    }
    return NONE;
}

void Controller::update(){

}
void reset_terminal() {
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

// terminal initial configuration setup
void configure_terminal() {
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios; // save it to be able to reset on exit

    new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("\e[?25l"); // hide cursor
    std::atexit(reset_terminal);
}


int read_input() {
    fflush(stdout);
    char buf[4096]; // maximum input buffer
    int n = read(STDIN_FILENO, buf, sizeof(buf));
    return n > 0 ? buf[n - 1] : -1;
}
