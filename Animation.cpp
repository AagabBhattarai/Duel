
#include "Animation.h"

const float Animation::switchTime[10][16]{
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14   15   
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.1, 0 , 0 },//IDLE-0
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.75,0.1f,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//PUNCH-1
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//WALK-2
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.1f, 0 , 0 },//JUMP-3
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15        
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH-4
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//KICK-5
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.1f,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//REACTION-6
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//STAND_BLOCK-7
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH_BLOCK-8
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//JUMP_BLOCK-9

    };


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime_O)
{
    this->imageCount = imageCount;
    this->switchTime_O = switchTime_O;
    totalTime = 0;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
    
    previous_playerState=PlayerState::IDLE;
}

Animation::~Animation()
{

}

void Animation::Update(PlayerState player_state, float deltaTime, bool faceRight)
{   
    // if(!(previous_playerState==PUNCH || previous_playerState==REACTION || previous_playerState==JUMP))
        currentImage.y = player_state;
    totalTime += deltaTime;
 
        // if(switchTime[player_state][currentImage.x] != 0.1f)
        // {
        //     currentImage.y = previous_playerState;
        // }
        // else
        // {
        //     previous_playerState = player_state;
        // }

    // bool hold;
    if (totalTime >= switchTime[player_state][currentImage.x])
    {
        totalTime -= switchTime[player_state][currentImage.x];
        currentImage.x++;

        if (currentImage.y == IDLE ||  currentImage.y || WALK)
        {
            if(currentImage.x >= 13)
                currentImage.x = 0;
        }
        if (currentImage.y == JUMP)
        {
            if(currentImage.x >=8)
            {
                currentImage.x=0;
                player_state = IDLE;
            }
        }
        else if(currentImage.y == KICK)
        {
            if(currentImage.x >=16)
            {
                currentImage.x = 0;
                player_state = IDLE;
            }
        }
        else if(currentImage.y == CROUCH)
        {
            if(currentImage.x >=2)
            {
                currentImage.x = 1;
            }
        }
        else if(currentImage.y == REACTION)
        {
            if(currentImage.x >=13)
            {
                currentImage.x = 0;
                previous_playerState = IDLE;
            }
        }
        else if(currentImage.y == STAND_BLOCK)
        {
            if(currentImage.x >=1)
            {
                currentImage.x = 0;
                player_state = IDLE;
            }
        }
        else if(currentImage.y == PUNCH)
        {
            if(currentImage.x >2)
            {
                currentImage.x = 0;
                previous_playerState = IDLE;
            }
        }
        
    }


    uvRect.top = currentImage.y * uvRect.height;

    if (faceRight)
    {
        uvRect.left = currentImage.x * abs(uvRect.width);
        uvRect.width = abs(uvRect.width);
    }
    else

    {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}




