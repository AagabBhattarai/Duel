
#include "Healthbar.h"

HealthBar::HealthBar(sf::Vector2f outline, sf::Vector2f health, sf::Vector2f damage, bool player1_or_player2)
{
    this->outline.setSize(sf::Vector2f(outline.x,outline.y));
    this->health.setSize(sf::Vector2f(health.x,health.y));
    this->damage.setSize(sf::Vector2f(damage.x,damage.y));
    
    //Set color for various rectangles
    this->damage.setFillColor(sf::Color::Red);
    this->health.setFillColor(sf::Color(255,129,0));
    this->outline.setFillColor(sf::Color::Transparent);

    //set outline
    this->outline.setOutlineThickness(2);
    this->outline.setOutlineColor(sf::Color::White);

    if(player1_or_player2)//if player = player1 then true
    {
        this->outline.setPosition(sf::Vector2f(0,30));
        this->health.setPosition(sf::Vector2f(0,30));
        this->damage.setPosition(sf::Vector2f(0,30));
    }
    else if(!player1_or_player2)
    {
        this->outline.setPosition(sf::Vector2f(1366,30));
        this->health.setPosition(sf::Vector2f(1366,30));
        this->damage.setPosition(sf::Vector2f(1366,30));
        this->damage.setScale(-1,1);
        this->outline.setScale(-1,1);
        this->health.setScale(-1,1);
    }

}

HealthBar::~HealthBar()
{

}

void HealthBar::healthUpdate(float currentHealth)
{   
    health.setSize(sf::Vector2f(currentHealth,30.0f));
}

void HealthBar::Draw(sf::RenderWindow& window)
{
    window.draw(outline);
    window.draw(damage);
    window.draw(health);
}