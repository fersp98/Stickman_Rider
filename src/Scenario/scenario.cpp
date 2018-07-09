//
// Created by pyxel on 08/07/18.
//
#include "scenario.h"
#include <utility>

void Scenario::setPath(std::string _path) {
    path = std::move(_path);
}

std::string Scenario::getPath() {
    return path;
}

Scenario::Scenario(std::string _path) {
    path = _path;
}
