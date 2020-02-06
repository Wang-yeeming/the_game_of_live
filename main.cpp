#include <iostream>
#include "cells.h"

using namespace std;

char map[10][10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
                    0, 0, 1, 1, 0, 1, 1, 0, 0, 0,
                    0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
                    0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
                    0, 1, 1, 0, 0, 0, 1, 1, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void delay() {
    for (int i = 0; i < 65535; i++) {
        for (int j = 0; j < 1024; j++);
    }
}

/**
 *
 * @param argv
 * @param argc
 * @return
 */
int main(int argv, char* argc[]) {
    cout << "The Game of Live." << endl;
    initgraph(600, 600);
    cells cell(map);
    cell.drawCell();
    while(1) {
        delay();
        cell.playGame();
        cell.drawCell();
    }
    return 0;
}
