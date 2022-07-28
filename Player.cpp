
#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, bool playerORenemy) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(166.f, 116.f));
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);

    body.setTexture(texture);

    if (playerORenemy)
        body.setPosition(600.f, 450.f);
    if (!playerORenemy)
        body.setPosition(1000.f, 450.f);
}

Player::~Player()
{

}


//playerORenemy and player_or_enemy does same thing, i was afraid to use same name for some reason
void Player::Update(float deltaTime, sf::Vector2u wsize, bool player_or_enemy, bool checkCollision)
{
    sf::Vector2f movement(0.f, 0.f);
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
    body.setScale(2, 2);

    //For player 1
    if (player_or_enemy)  //to differentiate between player 1 and player 2
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                movement.x = 0.f;
            else
            {
                movement.x += speed * deltaTime / 1000;
                row = 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                movement.x = 0;
            else
            {
                movement.x -= speed * deltaTime / 1000;
                row = 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if ((body.getPosition().x + body.getSize().x/2 >= wsize.x) || checkCollision)
                movement.x = 0.f;

            else
            {
                movement.x += speed * deltaTime;
                row = 2;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                movement.x = 0.f;
            else
            {
                movement.x -= speed * deltaTime;
                row = 2;
            }
        }
        if (body.getPosition().x == 600.f)
            faceRight = true;
    }

    //for player2
    else if (!player_or_enemy)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                movement.x = 0.f;
            else
            {
                //we divide by delta time by 1000 for holding.
                movement.x += speed * deltaTime / 1000;
                row = 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                movement.x = 0;
            else
            {
                movement.x -= speed * deltaTime / 1000;
                row = 1;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                movement.x = 0.f;
            else
            {
                movement.x += speed * deltaTime;//
                row = 2;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if ((body.getPosition().x - body.getSize().x/2 <= 0) || checkCollision )
                movement.x = 0.f;
            else
            {
                movement.x -= speed * deltaTime;
                row = 2;
            }
        }
        // for players to look at each other.
        if (body.getPosition().x == 1000.f)
            faceRight = false;
    }

    if (movement.x == 0.0f)
    {
        row = 0;
    }


    if (movement.x > 0.0f)
        faceRight = true;
    else if (movement.x < 0.0f)
        faceRight = false;

    animation.Update(row, deltaTime, faceRight);
    //spritesheet navigate
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}


float Player::playerPosition()
{
    return body.getPosition().x;
}