
#include "Animation.h"

const float Animation::switchTime_p1[10][16]{
        // 1    2    3    4    5     6   7    8     9     10     11        12     13     14   15   
        {0.07,0.07, 0.07 , 0.07 ,0.07 ,0.07 ,0.07 ,0.07 , 0.07 ,  0.07  , 0.07  , 0.07 , 0.7, 0 , 0 },//IDLE-0
        // 1    2    3    4      5      6      7     8      9     10      11      12     13   14  15  
        {0.15, 0.5 ,0.15, 0.15, 0.15 , 0.5  , 0.15, 0.15 , 0.15 , 0.15  , 0.5 , 0.15 , 0.15, 0 , 0 },//PUNCH-1
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.01,0.015,0.1,0.1,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//WALK-2
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.1,0.1,0.1, 0 , 0 },//JUMP-3
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15        
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH-4
        // 1    2     3       4       5      6         7    8      9      10     11     12     13   14   15  
        {0.1  ,0.1,  0.4 ,  0.15 ,  0.15  ,  0.1 ,  0.40 , 0.15 ,  0.1  , 0.1 , 0.15, 0.15, 0.15,  0 , 0 },//KICK-5
        // 1    2   3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.2,0.3,0.15,0.15,0.15,0.15,0.1,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//REACTION-6
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//STAND_BLOCK-7
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH_BLOCK-8
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//JUMP_BLOCK-9

    };

const float Animation::switchTime_p2[10][16]{
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14   15   
        {0.07,0.07, 0.07 , 0.07 ,0.07 ,0.07 ,0.1 ,0.1 ,0.1 ,0.15,0.15,0.15,0.1, 0 , 0 },//IDLE-0
        // 1    2    3    4      5      6      7     8      9     10      11      12     13   14  15  
        {0.15, 0.5 ,0.15, 0.15, 0.15 , 0.5  , 0.15, 0.15 , 0.15 , 0.15  , 0.5 , 0.15 , 0.15, 0 , 0 },//PUNCH-1
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.01,0.015,0.1,0.1,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//WALK-2
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.1,0.1,0.1, 0 , 0 },//JUMP-3
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15        
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH-4
        // 1    2     3       4       5      6         7    8      9      10     11     12     13   14   15  
        {0.1  ,0.1,  0.1 ,  0.15 ,  0.45  ,  0.1 ,  0.10 , 0.15 ,  0.1  , 0.1 , 0.15, 0.15, 0.15,  0 , 0 },//KICK-5
        // 1    2   3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.2,0.3,0.15,0.15,0.15,0.15,0.1,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//REACTION-6
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//STAND_BLOCK-7
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//CROUCH_BLOCK-8
        // 1    2    3    4    5     6   7    8     9   10   11   12   13  14  15  
        {0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15,0.15, 0 , 0 },//JUMP_BLOCK-9

    };


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount)
{
    this->imageCount = imageCount;
    totalTime = 0;
    currentImage.x = 0;
    currentImage.y = 0;
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
    // previous_playerState=PlayerState::IDLE;
    input_status = InputStatus::isReleased;
    reaction_done = false;
    impact_phase = false;
    previous_playerState = PlayerState::IDLE;
    transition_phase = false;
}

Animation::~Animation()
{

}

void Animation::Update_p1(PlayerState player_state, float deltaTime, bool faceRight)
{   
    float s1 = switchTime_p1[player_state][currentImage.x];//checks for change is x image

    currentImage.y = player_state;
    totalTime += deltaTime;
    ;
    if(player_state != previous_playerState)
    {
        currentImage.x = 0;
        previous_playerState = player_state;
    }

    
    if (totalTime >= switchTime_p1[player_state][currentImage.x])
    {
        totalTime -= switchTime_p1[player_state][currentImage.x];
        currentImage.x++;
        if (currentImage.y == IDLE )
        {
            if(currentImage.x >= 9)
                currentImage.x = 0;
            
        }
        if (currentImage.y == WALK )
        {
            if(currentImage.x > 12)
                currentImage.x = 0;

        }

        else if(currentImage.y == PUNCH)
        {
            if(currentImage.x >12)
            {
                currentImage.x = 0;
                currentImage.y = IDLE;
                input_status = isReleased;
            }
            else
            {
                 currentImage.y=PUNCH;

            } 
        }

        else if (currentImage.y == JUMP)
        {
            if(currentImage.x >=8)
            {
                currentImage.x=0;
                currentImage.y = IDLE;
                input_status = isReleased;

            }
            else 
            {
                currentImage.y = JUMP;
            }
        }
        else if(currentImage.y == KICK)
        {
            // if(currentImage.x=0)    
            //     currentImage.x=8;
            if(currentImage.x > 9)
            {
                currentImage.x = 0;
                currentImage.y = IDLE;
                input_status = isReleased;

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
            if(currentImage.x >3)
            {
                currentImage.x = 0;
                currentImage.y = PlayerState::IDLE;
                input_status = isReleased;
                reaction_done = true;
            }
        }
        else if(currentImage.y == STAND_BLOCK)
        {
            if(currentImage.x >=1)
            {
                currentImage.x = 0;
            }
        }
        
       
    }
    
    float s2 = switchTime_p1[player_state][currentImage.x];
    if((s2-s1)>0.15 && s2 > 0.25) // here 0.15 must be differnce between main impact frame and normal frame
    {
        transition_phase = true;
    }
    else
    {
        transition_phase = false;
    }

    //this part is to know in which frame player actually exerts his force
    if(switchTime_p1[player_state][currentImage.x] > 0.25) 
    {
        impact_phase = true;
    }
    else
    {
        impact_phase = false;
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

void Animation::Update_p2(PlayerState player_state, float deltaTime, bool faceRight)
{   
    float s1 = switchTime_p2[player_state][currentImage.x];//checks for change is x image

    currentImage.y = player_state;
    totalTime += deltaTime;
    ;
    if(player_state != previous_playerState)
    {
        currentImage.x = 0;
        previous_playerState = player_state;
    }

    
    if (totalTime >= switchTime_p2[player_state][currentImage.x])
    {
        totalTime -= switchTime_p2[player_state][currentImage.x];
        currentImage.x++;
        if (currentImage.y == IDLE )
        {
            if(currentImage.x > 5)
                currentImage.x = 0;
            
        }
        if (currentImage.y == WALK )
        {
            if(currentImage.x > 11)
                currentImage.x = 0;

        }

        else if(currentImage.y == PUNCH)
        {
            if(currentImage.x >2)
            {
                currentImage.x = 0;
                currentImage.y = IDLE;
                input_status = isReleased;
            }
            else
            {
                 currentImage.y=PUNCH;

            } 
        }

        else if (currentImage.y == JUMP)
        {
            if(currentImage.x >=8)
            {
                currentImage.x=0;
                currentImage.y = IDLE;
                input_status = isReleased;

            }
            else 
            {
                currentImage.y = JUMP;
            }
        }
        else if(currentImage.y == KICK)
        {
            // if(currentImage.x=0)    
            //     currentImage.x=8;
            if(currentImage.x > 7)
            {
                currentImage.x = 0;
                currentImage.y = IDLE;
                input_status = isReleased;

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
            
            if(currentImage.x >3)
            {
                currentImage.x = 0;
                currentImage.y = PlayerState::IDLE;
                input_status = isReleased;
                reaction_done = true;
            }
        }
        else if(currentImage.y == STAND_BLOCK)
        {
            if(currentImage.x >=1)
            {
                currentImage.x = 0;
            }
        }
        
       
    }
    
    float s2 = switchTime_p2[player_state][currentImage.x];
    if((s2-s1)>0.15 && s2 > 0.25) // here 0.15 must be differnce between main impact frame and normal frame
    {
        transition_phase = true;
    }
    else
    {
        transition_phase = false;
    }

    //this part is to know in which frame player actually exerts his force
    if(switchTime_p2[player_state][currentImage.x] > 0.25) 
    {
        impact_phase = true;
    }
    else
    {
        impact_phase = false;
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



bool Animation::isImpactPhase()
{
    return impact_phase;
}

bool Animation::isTransitionPhase()
{
    return transition_phase;
}






