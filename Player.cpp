
#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float speed, bool playerORenemy, sf::Texture* spark) :
    Animation(texture, imageCount),
    healthbar(sf::Vector2f(500,30),sf::Vector2f(400,30),sf::Vector2f(500,30),playerORenemy),
    maxHeight{300.0f},
    floor{450.0f},
    ImpactForce(spark)
{
    this->speed = speed;
    faceRight = true;

    body.setSize(sf::Vector2f(166.f, 124.f));
    body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
    body.setScale(2.2, 2.2);
    body.setTexture(texture);   

    if (playerORenemy)
        body.setPosition(600.f, 500.f);
    if (!playerORenemy)
        body.setPosition(1000.f, 500.f);

    player_state = IDLE;
    canJump = true;
}

Player::~Player(){}

void Player::Update(float deltaTime, sf::Vector2u wsize, bool player_or_enemy, bool checkCollision)
{
    velocity.x = 0.f;
    velocity.y =0.f;
    
    //This segement is for making sure punch reaction is played at full
    if(!Animation::reaction_done)
    {
        if (player_or_enemy)  //to differentiate between player 1 and player 2
        {
            if(player_state == REACTION)
                Animation::input_status = InputStatus::isPressed;
        }
            //for player2
        else if (!player_or_enemy)
        {
            if(player_state == REACTION)
                Animation::input_status = InputStatus::isPressed;
        }
    }
    else    
        Animation::reaction_done = false;

    //REACTION RECOIL WORK
    
    //For player 1


    if (Animation::input_status == InputStatus::isReleased)
    {
        if (player_or_enemy)  //to differentiate between player 1 and player 2
        {
            Player1_input(player_or_enemy, wsize, checkCollision);
        }

        //for player2
        else if (!player_or_enemy)
        {
            Player2_input(player_or_enemy, wsize, checkCollision);
        }
    }
   
    // std::cout<<body.getPosition().y<<std::endl;
    // if (velocity.y !=0)
    // {
    //     // velocity.y = 0;
    //     // body.setPosition(body.getPosition().x, 450.0f);
    //     velocity.y += 981.0f * 0.5;
    // }
    // else
    // {
    //     velocity.y =0;
    // }
   // if (velocity.x == 0.0f && velocity.y ==0.0f)
    //{
      //  player_state = PlayerState::IDLE;
    //}


    if (velocity.x > 0.0f)
        faceRight = true;
    else if (velocity.x < 0.0f)
        faceRight = false;

    if(player_or_enemy)
        Animation::Update_p1(player_state, deltaTime, faceRight);
    else if(!player_or_enemy) //not of player_or enemy means it's player 2
        Animation::Update_p2(player_state, deltaTime, faceRight);


    //spritesheet navigate
    body.setTextureRect(Animation::uvRect);
    body.move(velocity*deltaTime);
    

    if(faceRight)
        ImpactForce::hit_spark.setPosition(body.getPosition().x + 125.f,body.getPosition().y - 70.f);
    else
        ImpactForce::hit_spark.setPosition(body.getPosition().x - 200.f,body.getPosition().y - 70.f);
}

void Player::currentHealth(float currentHealth)
{
    healthbar.healthUpdate(currentHealth);
}

void Player::Player1_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision)
{

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x || checkCollision)
                velocity.x = 0.f;
            else
            {
                velocity.x += speed;//
                player_state = PlayerState::WALK;
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if ((body.getPosition().x - body.getSize().x/2 <= 0)  )
                velocity.x = 0.f;
            else
            {
                velocity.x -= speed;
                player_state = PlayerState::WALK;
                // faceRight = true;//Test with single direction movement
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
        {
            // canJump = false;
             player_state = JUMP;
          // velocity.y = -sqrtf(2.0 * 981.f * maxHeight);
            //velocity.x = 0.001;
            Animation::input_status = isPressed;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                velocity.x = 0.f;
            else
            {
                //we divide by delta time by 1000 for holding.
                velocity.x += speed / 1000;
                player_state = PlayerState::PUNCH;
                Animation::input_status = isPressed;
            }  
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x -= speed / 1000;
                player_state = PlayerState::PUNCH;
                Animation::input_status = isPressed;
            }
            
        }

        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        // {
        //     if ((body.getPosition().x - body.getSize().x/2 <= 0) || checkCollision )
        //         velocity.x = 0.f;
        //     else
        //     {
        //         velocity.x -= speed/1000;
        //         player_state = PlayerState::PUNCH;
        //     }
        // }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x -= speed / 1000;
                player_state = PlayerState::CROUCH;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::CROUCH;
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::KICK;
                Animation::input_status = isPressed;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x-= speed / 1000;
                player_state = PlayerState::PUNCH;
                Animation::input_status = isPressed;
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::STAND_BLOCK;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::REACTION;
                Animation::input_status = isPressed;
            }
        }
        else
        {
        player_state = PlayerState::IDLE;
        }

        // for players to look at each other.
        if (body.getPosition().x == 600.f)
            faceRight = true;
}


void Player::Player2_input(bool player_or_enemy, sf::Vector2u wsize, bool checkCollision)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P ) &&sf::Keyboard::isKeyPressed(sf::Keyboard::Right ) )
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::STAND_BLOCK;
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P ) &&sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) )
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x -= speed / 1000;
                player_state = PlayerState::STAND_BLOCK;
            }
        }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                velocity.x = 0.f;
            else
            {
                //we divide by delta time by 1000 for holding.
                velocity.x += speed / 1000;
                player_state = PlayerState::PUNCH;
                Animation::input_status = isPressed;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                // velocity.x -= speed / 1000;
                player_state = PlayerState::PUNCH;
                Animation::input_status = isPressed;
                faceRight = false;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x -= speed / 1000;
                player_state = PlayerState::CROUCH;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                velocity.x += speed / 1000;
                player_state = PlayerState::CROUCH;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (body.getPosition().x + body.getSize().x/2 >= wsize.x)
                velocity.x = 0.f;
            else
            {
                velocity.x += speed;//
                player_state = PlayerState::WALK;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if ((body.getPosition().x - body.getSize().x/2 <= 0) || checkCollision )
                velocity.x = 0.f;
            else
            {
                velocity.x -= speed;
                player_state = PlayerState::WALK;
            }
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
        {
            canJump = true;
            player_state = JUMP;
           // velocity.y = -sqrtf(2.0 * 981.f * maxHeight);
           // velocity.x = -0.001;
        }

        

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                // velocity.x += speed / 1000;
                player_state = PlayerState::KICK;
                Animation::input_status = isPressed;
            }
        }

        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
        {
            if (body.getPosition().x - body.getSize().x/2 <= 0)
                velocity.x = 0;
            else
            {
                // velocity.x += speed / 1000;
                player_state = PlayerState::REACTION;
                Animation::input_status = isPressed;
            }
        }
        else
        {
        player_state = PlayerState::IDLE;
        }
        // for players to look at each other.
        if (body.getPosition().x == 1000.f)
            faceRight = false;
}






void Player::Draw(sf::RenderWindow& window)
{
    healthbar.Draw(window);
    window.draw(body);
    // ImpactForce::Draw(window);
}




float Player::playerPosition()
{
    return body.getPosition().x;
}

bool Player::isFacingRight()
{
    return faceRight;
}

