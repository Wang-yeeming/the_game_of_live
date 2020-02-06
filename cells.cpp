//
// Created by Yeeming Wang on 2020/2/1.
//

#include "cells.h"

/**
 *
 * @param map
 * @param line
 * @param col
 */
cells::cells(char map[10][10]) {
    for (int line = 0; line < 10; line++) {
        for (int col = 0; col < 10; col++) {
            ///-------------------------------------------------------- 若为0则死，若为1则生
            cell[line][col].selfState = map[line][col] == 0 ? dead : alive;

            if (line > 0) {
                ///---------------------------------------------------- 上方
                cell[line][col].upCellState = map[line - 1][col] == 0 ? dead : alive;

                if (col > 0) {
                    ///------------------------------------------------ 左上
                    cell[line][col].ulCellState = map[line - 1][col - 1] == 0 ? dead : alive;
                }

                if (col < 9) {
                    ///------------------------------------------------ 右上
                    cell[line][col].urCellState = map[line - 1][col + 1] == 0 ? dead : alive;
                }
            }

            if (line < 9) {
                ///---------------------------------------------------- 下方
                cell[line][col].downCellState = map[line + 1][col] == 0 ? dead : alive;

                if (col > 0) {
                    ///------------------------------------------------ 左下
                    cell[line][col].dlCellState = map[line + 1][col - 1] == 0 ? dead : alive;
                }

                if (col < 9) {
                    ///------------------------------------------------ 右下
                    cell[line][col].drCellState = map[line + 1][col + 1] == 0 ? dead : alive;
                }
            }

            if (col > 0) {
                ///---------------------------------------------------- 左方
                cell[line][col].leftCellState = map[line][col - 1] == 0 ? dead : alive;
            }

            if (col < 9) {
                ///---------------------------------------------------- 右方
                cell[line][col].rightCellState = map[line][col + 1] == 0 ? dead : alive;
            }
        }
    }
}

void cells::drawCell() {
    for (int i = 0; i < 10; i++) {
        int yPos = i * 60;
        for (int j = 0; j < 10; j++) {
            int xPos = j * 60;
            ///-------------------------------------------------------- 若为生，在对应的坐标画一个黑色正方形
            if (cell[i][j].selfState == alive) {
                setfillcolor(BLACK);
                solidrectangle(xPos, yPos, xPos + 60, yPos + 60);
                setlinecolor(WHITE);
                rectangle(xPos, yPos, xPos + 60, yPos + 60);
                ///---------------------------------------------------- 若为死，在对应的坐标画一个白色正方形
            } else {
                setfillcolor(WHITE);
                solidrectangle(xPos, yPos, xPos + 60, yPos + 60);
                setlinecolor(BLACK);
                rectangle(xPos, yPos, xPos + 60, yPos + 60);
            }
        }
    }
}

void cells::playGame() {
    ///---------------------------------------------------------------- 设置标志位
    char indexChange[10][10] = {0};

    ///---------------------------------------------------------------- 转变细胞状态
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            unsigned sum = cell[i][j].upCellState + cell[i][j].urCellState + cell[i][j].rightCellState
                    + cell[i][j].drCellState + cell[i][j].downCellState + cell[i][j].dlCellState
                    + cell[i][j].leftCellState + cell[i][j].ulCellState;

            ///-------------------------------------------------------- 若活细胞周围有2或3个活细胞，则活细胞继续存活
            if (cell[i][j].selfState == alive) {
                if (sum == 2 || sum == 3) {
                    cell[i][j].selfState = alive;
                } else {
                    cell[i][j].selfState = dead;
                    indexChange[i][j] = 1;
                }
                ///---------------------------------------------------- 若死细胞周围恰有3个活细胞，则死细胞复活
            } else {
                if (sum == 3) {
                    cell[i][j].selfState = alive;
                    indexChange[i][j] = -1;
                } else {
                    cell[i][j].selfState = dead;
                }
            }
        }
    }

    ///---------------------------------------------------------------- 更新发生变化的细胞周围的细胞的存储数据
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (indexChange[i][j] > 0) {
                if (i > 0) {
                    ///------------------------------------------------ 更新正上方的细胞
                    cell[i - 1][j].downCellState = dead;

                    if (j > 0) {
                        ///-------------------------------------------- 更新左上方的细胞
                        cell[i - 1][j - 1].drCellState = dead;
                    }

                    if (j < 9) {
                        ///-------------------------------------------- 更新右上方的细胞
                        cell[i - 1][j + 1].dlCellState = dead;
                    }
                }

                if (i < 9) {
                    ///------------------------------------------------ 更新正下方的细胞
                    cell[i + 1][j].upCellState = dead;

                    if (j > 0) {
                        ///-------------------------------------------- 更新左下方的细胞
                        cell[i + 1][j - 1].urCellState = dead;
                    }

                    if (j < 9) {
                        ///-------------------------------------------- 更新右下方的细胞
                        cell[i + 1][j + 1].ulCellState = dead;
                    }
                }

                if (j > 0) {
                    ///------------------------------------------------ 更新正左方的细胞
                    cell[i][j - 1].rightCellState = dead;
                }

                if (j < 9) {
                    ///------------------------------------------------ 更新正右方的细胞
                    cell[i][j + 1].leftCellState = dead;
                }
            } else if (indexChange[i][j] < 0) {
                if (i > 0) {
                    ///------------------------------------------------ 更新正上方的细胞
                    cell[i - 1][j].downCellState = alive;

                    if (j > 0) {
                        ///-------------------------------------------- 更新左上方的细胞
                        cell[i - 1][j - 1].drCellState = alive;
                    }

                    if (j < 9) {
                        ///-------------------------------------------- 更新右上方的细胞
                        cell[i - 1][j + 1].dlCellState = alive;
                    }
                }

                if (i < 9) {
                    ///------------------------------------------------ 更新正下方的细胞
                    cell[i + 1][j].upCellState = alive;

                    if (j > 0) {
                        ///-------------------------------------------- 更新左下方的细胞
                        cell[i + 1][j - 1].urCellState = alive;
                    }

                    if (j < 9) {
                        ///-------------------------------------------- 更新右下方的细胞
                        cell[i + 1][j + 1].ulCellState = alive;
                    }
                }

                if (j > 0) {
                    ///------------------------------------------------ 更新正左方的细胞
                    cell[i][j - 1].rightCellState = alive;
                }

                if (j < 9) {
                    ///------------------------------------------------ 更新正右方的细胞
                    cell[i][j + 1].leftCellState = alive;
                }
            }
        }
    }
}
