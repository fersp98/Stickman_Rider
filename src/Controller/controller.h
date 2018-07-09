//
// Created by pyxel on 08/07/18.
//

#ifndef STICKMAN_RIDER_CONTROLLER_H
#define STICKMAN_RIDER_CONTROLLER_H

#include "../Song/song.h"
#include "../Scenario/scenario.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

class Controller{
    Track track;
    Scenario scenario;
public:
    Controller();
    Controller(Scenario &_scenario, Track &_track);
    void drawScreen();
};

#endif //STICKMAN_RIDER_CONTROLLER_H
