#pragma once

#include <SFML/Graphics.hpp>
#include <utility>

struct Animation {
    sf::Sprite sprite;
    int frameWidth;
    int frameHeight;
    int numFrames;
    int currentFrame;
    int frameDuration;
    int elapsedTime;
    bool finished;

    Animation(sf::Sprite sprite, int frameWidth, int frameHeight, int numFrames, int frameDuration) :
            sprite(std::move(sprite)),
            frameWidth(frameWidth),
            frameHeight(frameHeight),
            numFrames(numFrames),
            currentFrame(0),
            frameDuration(frameDuration),
            elapsedTime(0),
            finished(false)
    {
        this->sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    }

    void update() {
        elapsedTime += 1;
        if (elapsedTime >= frameDuration) {
            elapsedTime = 0;
            currentFrame = (currentFrame + 1) % numFrames;
            int left = currentFrame * frameWidth;
            sprite.setTextureRect(sf::IntRect(left, 0, frameWidth, frameHeight));
        }
        if (currentFrame == numFrames - 1) {
            finished = true;
        }
    }
};