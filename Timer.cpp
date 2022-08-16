
#include "Timer.h"


Timer::Timer(sf::Font& font, int time)
{
    this->text.setFont(font);
    this->time = time;
}

void Timer::update(int time)
{
    this->time = 90-time;
    std::string str = std::to_string(this->time);
    text.setString(str);
    text.setCharacterSize(90);
    text.setFillColor(sf::Color::Red);
    text.setPosition(658,10);
    text.setStyle(sf::Text::Bold);
}
void Timer::Draw(sf::RenderWindow& window)
{
    window.draw(text);
}
Timer::~Timer()
{

}

