//
//  gameController.h
//  finalProjectPlatformer
//
//  Created by Michael Krcmarik on 4/24/15.
//
//

#ifndef __finalProjectPlatformer__gameController__
#define __finalProjectPlatformer__gameController__

#include <stdio.h>
#include "ofApp.h"

class gameCtrl
{
private:
    int characterPos;
    int characterWidth;
    int jumpSlack;
    int jumpHeight;
public:
    int height[10000];
    bool collision;
    bool jumpPressed;
    bool isFalling;
    bool movingForward;
    bool movingBackward;
    bool onGround;
    int score;
    int mapPosition;
    int gameState;
    float xPos;
    float yPos;
    float preJumpHeight;
    float position;
    gameCtrl();
    int checkCollision(int boxLeft, int boxWidth, int boxTop, int boxHeight);
    void gravityControl();
    int getCharPos();
    int getCharWidth();
    int getJumpSlack();
    int getJumpHeight();
    void generateRandomLevel();
    void updateFrameBuffer(ofFbo myBuffer, ofImage gameBackground);
};

#endif /* defined(__finalProjectPlatformer__gameController__) */
