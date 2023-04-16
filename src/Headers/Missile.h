#pragma once

#include <utility>

#include "Entity.h"

struct Missile : Entity {

    bool life = true;
    Player * player_who_shot;
    sf::Vector2f previousPosition = {0,0};

    Missile(sf::Sprite sprite, int movement_speed, int rotation_degree)
    : Entity{ std::move(sprite), static_cast<float>(movement_speed), rotation_degree} {}
};