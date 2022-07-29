#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Healthbar.h"
class Player
{
private:
    sf::RectangleShape body;
    Animation animation;
    HealthBar healthbar;
    unsigned int row;
    float speed;
    bool faceRight;
    bool playerORenemy;
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, bool playerORenemy);
    ~Player();

    void Update(float deltaTime, sf::Vector2u wsize, bool player_or_enemy, bool collisionCheck);
    void Draw(sf::RenderWindow& window);
    float playerPosition();
};

