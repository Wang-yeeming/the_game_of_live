//
// Created by Yeeming Wang on 2020/2/1.
//

#ifndef THE_GAME_OF_LIVE_CELLS_H
#define THE_GAME_OF_LIVE_CELLS_H

#include "graphics.h"

/// 每个细胞可能存在2种状态：
/// 生、或者死
typedef enum {
    dead = 0,
    alive,
} stateCell;

///  左上状态域  上状态域  右上状态域
///          \    |    /
/// 左状态域 -- 细胞状态域 -- 右状态域
///          /    |    \
///  左下状态域  下指针域  右下状态域
struct singleCell{
    stateCell selfState;
    stateCell upCellState;
    stateCell downCellState;
    stateCell leftCellState;
    stateCell rightCellState;
    stateCell ulCellState;
    stateCell dlCellState;
    stateCell urCellState;
    stateCell drCellState;
};

class cells {
private:
    singleCell cell[10][10] = {dead};
public:
    explicit cells(char map[10][10]);
    void drawCell();
    void playGame();
};


#endif //THE_GAME_OF_LIVE_CELLS_H
