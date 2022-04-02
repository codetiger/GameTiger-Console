#include "ticscreen.h"
#include <algorithm> 

TicScreen::TicScreen(void (*rcb)(int8_t menu), void (*hscb)(uint32_t highscore), uint32_t highscore) {
    printf("Tic screen loading...");
    this->screenId = 6;
    this->type = Type::GAME;
    this->returnCallBack = rcb;
    this->highScoreCallBack = hscb;
    this->gameState = PLAYING;
    this->turn = ((rand() % 100) % 2) == 0 ? O_TIC : X_TIC;
    this->won = E_TIC;
    this->moveCount = 0;
    this->sx = this->sy = 0;
    std::random_shuffle(&pInd[0], &pInd[8]);

    for (uint8_t y = 0; y < TIC_BOARDSIZE; y++)
        for (uint8_t x = 0; x < TIC_BOARDSIZE; x++)
            board.setCellValue(x, y, E_TIC);
    printBoard();
    font.setAlpha(255);
    printf("Done\n");
}

TicScreen::~TicScreen() {

}

void TicScreen::update(uint16_t deltaTimeMS) {
    if(turn == X_TIC && this->gameState == PLAYING) {
        board.setCellValue(bestMove(board, this->moveCount), X_TIC);
        this->moveCount++;
        turn = O_TIC;
        if(checkGameOver())
            this->gameState = LOST;
    }
}

void TicScreen::draw(Display *display) {
    display->clear(Color(100, 71, 195));
    for (uint8_t y = 0; y < TIC_BOARDSIZE; y++) {
        for (uint8_t x = 0; x < TIC_BOARDSIZE; x++) {
            if(board.getCellValue(x, y) == E_TIC)
                tttblocks.drawSprite(display, 'e', 30+x*60, 30+y*60);
            else if(board.getCellValue(x, y) == O_TIC)
                tttblocks.drawSprite(display, 'o', 30+x*60, 30+y*60);
            else if(board.getCellValue(x, y) == X_TIC)
                tttblocks.drawSprite(display, 'x', 30+x*60, 30+y*60);
        }
    }

    font.drawSprites(display, "TIC TAC TOE", 90, 10);
    if(turn == O_TIC)
        display->rect(30+this->sx*60, 30+this->sy*60, 60, 60, Color(0, 255, 0));
    
    if(this->gameState == PLAYING) {
        font.drawSprites(display, "TURN", 240, 140);
        if(turn == O_TIC)
            font.drawSprites(display, "YOU", 242, 160);
        else
            font.drawSprites(display, "COMP", 240, 160);
    } else {
        std::string str = "";
        if(won == O_TIC)
            str = "YOU WON";
        else if(won == X_TIC)
            str = "COMPUTER WON";
        else
            str = "GAME DRAW";
        uint8_t width = font.getWidth(str);
        font.drawSprites(display, str, (240-width)/2, 215);
    }
}

bool TicScreen::checkGameOver() {
    won = board.getWinner();
    if(won != E_TIC)
        return true;

    if(!board.isFull())
        return false;

    won = E_TIC;
    return true;
}

int16_t TicScreen::minimax(TicBoard b, uint16_t depth, bool isAI) {
	int16_t score = 0, bestScore = isAI ? -999 : 999;
	if (board.getWinner() != E_TIC)
        return isAI ? -1 : 1;
	else if(depth < 9) {
        for(int i = 0; i < TIC_BOARDSIZE*TIC_BOARDSIZE; i++) {
            if (board.getCellValue(pInd[i]) == E_TIC) {
                board.setCellValue(pInd[i], isAI ? X_TIC : O_TIC);
                score = minimax(board, depth + 1, !isAI);
                board.setCellValue(pInd[i], E_TIC);
                if((isAI && score > bestScore) || (!isAI && score < bestScore))
                    bestScore = score;
            }
        }
        return bestScore;
    } else
        return 0;
}

uint8_t TicScreen::bestMove(TicBoard b, uint8_t moveCount) {
	uint8_t index = 0;
	int16_t score = 0, bestScore = -999;
    for(int i = 0; i < TIC_BOARDSIZE*TIC_BOARDSIZE; i++) {
        if (board.getCellValue(pInd[i]) == E_TIC) {
            board.setCellValue(pInd[i], X_TIC);
            score = minimax(board, moveCount+1, false);
            board.setCellValue(pInd[i], E_TIC);
            if(score > bestScore) {
                bestScore = score;
                index = pInd[i];
            }
        }
    }
    return index;
}

void TicScreen::printBoard() {
    for (uint8_t y = 0; y < TIC_BOARDSIZE; y++) {
        for (uint8_t x = 0; x < TIC_BOARDSIZE; x++) {
            printf("%d\t", board.getCellValue(x, y));
        }
        printf("\n");
    }
    printf("Value %d\n", board.value);
}

void TicScreen::keyPressed(uint8_t key) {
    if(key == KEY_DOWN) {
        this->sy = (this->sy < TIC_BOARDSIZE-1) ? this->sy+1 : this->sy;
    } else if(key == KEY_UP) {
        this->sy = (this->sy > 0) ? this->sy-1 : this->sy;
    } else if(key == KEY_RIGHT) {
        this->sx = (this->sx < TIC_BOARDSIZE-1) ? this->sx+1 : this->sx;
    } else if(key == KEY_LEFT) {
        this->sx = (this->sx > 0) ? this->sx-1 : this->sx;
    } else if(key == KEY_A) {
        if(this->gameState == PLAYING && turn == O_TIC && board.getCellValue(this->sx, this->sy) == E_TIC) {
            board.setCellValue(this->sx, this->sy, O_TIC);
            turn = X_TIC;
            this->moveCount++;
            if(checkGameOver())
                this->gameState = LOST;
        }
    } else if(key == KEY_B) {
        if(this->gameState == LOST)
            this->returnCallBack(4);
    }
    printBoard();
}

void TicScreen::keyReleased(uint8_t key) {

}

void TicScreen::keyDown(uint8_t key) {

}
