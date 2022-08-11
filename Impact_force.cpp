#include "Impact_force.h"

ImpactForce::ImpactForce(sf::Texture* texture)
{   
    spark_uv.top = 0;
    spark_uv.left  = 0;
    spark_uv.width = texture->getSize().x / 4.0;
    spark_uv.height = texture->getSize().y / 1.0;

    hit_spark.setTexture(texture);
    hit_spark.setSize(sf::Vector2f(146.f,104.f));
    hit_spark.setTextureRect(spark_uv);
    hit_spark.setScale(0.5,0.5);
}