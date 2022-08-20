#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Healthbar.h"
#include <cmath>
#include "PlayerState.h"
#include "Impact_force.h"


class Player: public Animation, public ImpactForce, public HealthBar
{
private:
    sf::RectangleShape body;
    // HealthBar healthbar;
    float speed;
    sf::Vector2f velocity;
    bool faceRight;
    bool playerORenemy;
    const float maxHeight;
    const float floor;
    bool gravity_starts;
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float speed, bool playerORenemy, sf::Texture* spark);
    ~Player();

    void Update(float deltaTime, sf::Vector2u wsize, bool player_or_enemy, bool checkCollision);

    void Player1_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision);
    void Player2_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision);

    void Draw(sf::RenderWindow& window);
    float playerPosition_x();
    float playerPosition_y();


    void currentHealth(float currentHealth);
    bool isFacingRight();
    bool isCombo();

public:
    PlayerState player_state;
private:
    
    bool canJump;
};

