//
//  gameController.cpp
//  finalProjectPlatformer
//
//  Created by Michael Krcmarik on 4/24/15.
//
//

#include "gameController.h"
#include "ofApp.h"

gameCtrl::gameCtrl()
{
    gameState = 0;
    xPos = 0;
    yPos = 500;
    score = 0;
    characterPos = 250;
    characterWidth = 75;
    jumpSlack = 50;
    jumpHeight = 150;
    collision = false;
    jumpPressed = false;
    isFalling = true;
    movingForward = false;
    movingBackward = false;
    onGround = false;
    
    
}

int gameCtrl::checkCollision(int boxLeft, int boxWidth, int boxTop, int boxHeight)
{
    if (characterPos < boxLeft + boxWidth &&
        characterPos + characterWidth > boxLeft &&
        yPos < boxTop + boxHeight &&
        characterWidth + yPos > boxTop)
    {
        collision = true;
        position = yPos;
    }
    
    else
    {
        collision = false;
    }
    
    if (collision == true && boxLeft - jumpSlack < characterPos && boxLeft + boxWidth + jumpSlack > characterPos + characterWidth)
    {
        yPos = position;
        preJumpHeight = yPos;
        isFalling = false;
        onGround = false;
    }
    
    if (collision == true && boxLeft>characterPos && yPos > boxTop)
    {
        movingForward = false;
    }
    
    if (collision == true && boxLeft<characterPos && yPos > boxTop)
    {
        movingBackward = false;
    }

}

void gameCtrl::gravityControl()
{
    if (collision != true && onGround == false && jumpPressed == false)
    {
        isFalling = true;
    }
}

int gameCtrl::getCharPos()
{
    return characterPos;
}

int gameCtrl::getCharWidth()
{
    return characterWidth;
}

int gameCtrl::getJumpSlack()
{
    return jumpSlack;
}

int gameCtrl::getJumpHeight()
{
    return jumpHeight;
}

void gameCtrl::generateRandomLevel()
{
//    int value = rand() % 5;
//    
//    if (value == 0)
//    {
//        
//    }
    for (int i=0; i<10; ++i) {
        height[i] = 600 - i*50;
    }
}

void gameCtrl::updateFrameBuffer(ofFbo myBuffer, ofImage gameBackground)
{
    myBuffer.begin();
    ofClear(255, 255, 255, 8);
    gameBackground.draw(0, 0);
    ofSetColor(255, 255, 255);
    generateRandomLevel();
    for (int i=0; i<10; ++i)
    {
        ofRect(xPos + 1000 + i*100, height[i], 100, 100);
    }
    myBuffer.end();
}
