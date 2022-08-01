#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Healthbar.h"
#include <cmath>
#include "PlayerState.h"



// enum PlayerAction
// {
//     SINGLE_PUNCH,
//     SPAM_PUNCH,
// };
class Player
{
private:
    sf::RectangleShape body;
    Animation animation;
    HealthBar healthbar;
    // unsigned int row;
    float speed;
    sf::Vector2f velocity;
    bool faceRight;
    bool playerORenemy;
    const float maxHeight;
    const float floor;
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, bool playerORenemy);
    ~Player();

    void Update(float deltaTime, sf::Vector2u wsize, bool player_or_enemy, bool checkCollision);

    void Player1_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision);
    void Player2_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision);

    void Draw(sf::RenderWindow& window);
    float playerPosition();
    friend class Animation;


    void currentHealth(float currentHealth);
    PlayerState player_state;
private:
    
    bool canJump;
    bool onProcess;
};

