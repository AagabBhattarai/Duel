
#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);

}

Animation::~Animation()
{

}

void Animation::Update(PlayerState player_state, float deltaTime, bool faceRight)
{
    currentImage.y = player_state;
    totalTime += deltaTime;
    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.y == IDLE || currentImage.y == PUNCH || currentImage.y || WALK)
        {
            if(currentImage.x >= 13)
                currentImage.x = 0;
        }
        if (currentImage.y == JUMP)
        {
            if(currentImage.x >=9)
            {
                currentImage.x=0;
                player_state = IDLE;
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