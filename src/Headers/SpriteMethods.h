//
// Created by alexey on 4/12/23.
//

#ifndef BLAST_SPRITEMETHODS_H
#define BLAST_SPRITEMETHODS_H

#include <SFML/Graphics.hpp>

void config_sprite(sf::Sprite &sprite){
    sprite.setOrigin((float)sprite.getTexture()->getSize().x / 2.f, (float)sprite.getTexture()->getSize().y / 2.f);
}

bool collision(sf::Sprite& a, sf::Sprite& b, bool a_can_move = true, bool b_can_move = true) {
    if (a.getGlobalBounds().intersects(b.getGlobalBounds())) {

        sf::FloatRect overlap;
        a.getGlobalBounds().intersects(b.getGlobalBounds(), overlap);

        sf::Vector2f push;
        if (overlap.width < overlap.height) {
            push.x = overlap.width * (a.getPosition().x < b.getPosition().x ? -1 : 1);
        } else {
            push.y = overlap.height * (a.getPosition().y < b.getPosition().y ? -1 : 1);
        }

        // Push back the sprites
        if (a_can_move && b_can_move) {
            a.move(push / 2.0f);
            b.move(-push / 2.0f);
        } else if (a_can_move) {
            a.move(push);
        } else if (b_can_move) {
            b.move(-push);
        }

        return true;
    }
    return false;
}

#endif //BLAST_SPRITEMETHODS_H