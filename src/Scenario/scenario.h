//
// Created by pyxel on 08/07/18.
//

#ifndef STICKMAN_RIDER_SCREEN_H
#define STICKMAN_RIDER_SCREEN_H

#include <string>
class Scenario{
    std::string path;
public:
    Scenario()= default;
    explicit Scenario(std::string _path);
    void setPath(std::string);
    std::string getPath();
};
#endif //STICKMAN_RIDER_SCREEN_H
