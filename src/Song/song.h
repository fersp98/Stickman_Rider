//
// Created by pyxel on 08/07/18.
//

#ifndef STICKMAN_RIDER_SONG_H
#define STICKMAN_RIDER_SONG_H

#include <string>
#include "../../AudioFile/AudioFile.h"
#include <vector>
#include <cmath>
class Track{
    std::string path;
    AudioFile<double> song;
    int numSamples;
    int sampleRate;
    float duration;
    int sampSize;
    std::vector<std::vector<float>> samps;
    std::vector<float> average;
public:
    Track()= default;
    void loadSong(std::string);
    std::vector<std::vector<float>> getSamps();
    std::vector<float> getAverage();
    std::string getPath();
    int getNumSamples();
    int getSampleRate();
    float getDuration();
    int getSampSize();
};

#endif //STICKMAN_RIDER_SONG_H
