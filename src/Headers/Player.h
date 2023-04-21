#pragma once
#include <utility>

#include "Entity.h"
const int max_bullets = 120;

struct Player : Entity {
    int id = 0;
    int hp = 0;
    int kills = 0;
    int deaths = 0;
    int shootDelay = 5;
    int timeSinceLastShot = 0;
    int bullets = 120;

    Player(){}
    Player(sf::Sprite sprite, float movement_speed, int rotation_degree, int hp, int id)
        : Entity{ std::move(sprite), movement_speed, rotation_degree}, hp{hp}, id{id}{}

};
