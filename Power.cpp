#include "Power.h"

#include "Impact_force.h"

Power::Power(sf::Texture* texture)
{   
    spark_uv.top = 0;
    spark_uv.left  = 0;
    spark_uv.width = texture->getSize().x / 5.0;
    spark_uv.height = texture->getSize().y / 1.0;

    power_spark.setTexture(texture);
    power_spark.setSize(sf::Vector2f(103.75f,62.f));
    power_spark.setTextureRect(spark_uv);
    power_spark.setScale(-2,2);
    power_spark.setOrigin(power_spark.getSize().x / 2, power_spark.getSize().y / 2);
}
void Power::setPosition(sf::Vector2f power_position, bool left_or_right)
{
    power_spark.setPosition(power_position.x, power_position.y);
    if(left_or_right == true) //when true power is right facing
        power_spark.setScale(2.5,2.5);
    else
        power_spark.setScale(-2.5,2.5);
}
void Power::Update(int left)
{   
    spark_uv.left = left * spark_uv.width;
    power_spark.setTextureRect(spark_uv);
}

void Power::Draw(sf::RenderWindow& window)
{
    window.draw(power_spark);
}