#include "../core/common.h"
#include "../core/screen.h"
#include "../core/keyboard.h"
#include <map>
#include <vector>

class SnakeScreen : public Screen
{
private:
    uint8_t snakeDir = KEY_RIGHT;
    GameState gameState;
    uint8_t gameSpeed = 1;
    uint16_t highScore = 0;
    
    Color dark = Color(31, 31, 31), light = Color(157, 195, 140);

    const uint8_t BOARD_WIDTH = 30, BOARD_HEIGHT = 20;
    std::map<uint8_t, std::array<int8_t, 2> > DIR_INFO = {
        {KEY_UP, {{0, -1}}},
        {KEY_DOWN, {{0, 1}}},
        {KEY_LEFT, {{-1, 0}}},
        {KEY_RIGHT, {{1, 0}}},
    };

    uint8_t foodPos[2] = {0, 0};
    uint16_t snakeLength = 3;
    uint8_t snakeBlocks[600][2];
    timetype lastUpdate;
    uint8_t option;

    void createNewFood();
    bool checkFoodCaptured();
    bool checkSnakeLoop();
    void moveSnake();
    void drawBlock(Display *display, uint16_t x, uint16_t y);
public:
    SnakeScreen(void (*returnCallBack)(int8_t menu, uint8_t option), void (*highScoreCallBack)(uint32_t highscore), uint32_t highscore, uint8_t option);
    ~SnakeScreen();

    void update(uint16_t deltaTimeMS);
    void draw(Display *display);
    void keyPressed(uint8_t key);
    void keyReleased(uint8_t key);
    void keyDown(uint8_t key);
};
