#include "../core/common.h"
#include "../core/screen.h"
#include "../core/keyboard.h"

#define MINE_BOARD_WIDTH 20
#define MINE_BOARD_HEIGHT 15

enum STATETYPE {
    CLOSE = 1, 
    OPEN = 2, 
    FLAG = 3, 
    DOUBT = 4, 
};

class MineScreen : public Screen
{
private:
    uint8_t board[MINE_BOARD_WIDTH*MINE_BOARD_HEIGHT];
    STATETYPE state[MINE_BOARD_WIDTH*MINE_BOARD_HEIGHT];
    uint8_t selectedX, selectedY;
    GameState gameState;
    uint8_t option;
    uint8_t TOTAL_MINES = 38;

    void resetBoard();
    void printBoard();
    void chainOpen(uint8_t x, uint8_t y);
public:
    MineScreen(void (*returnCallBack)(int8_t menu, uint8_t option), void (*highScoreCallBack)(uint32_t highscore), uint32_t highscore, uint8_t option);
    ~MineScreen();

    void update(uint16_t deltaTimeMS);
    void draw(Display *display);
    void keyPressed(uint8_t key);
    void keyReleased(uint8_t key);
    void keyDown(uint8_t key);
};
