//
// Created by pyxel on 08/07/18.
//
#include "Track.h"
#define STEREO 1

void Track::loadSong(std::string _path) {
    path = std::move(_path);
    song.load(path);
    numSamples = song.getNumSamplesPerChannel();
    sampleRate = song.getSampleRate();
    duration = static_cast<float>(song.getLengthInSeconds());
    sampSize = static_cast<int>(std::ceil(duration));

    //Setting samps:
    for(int i=0;i<sampSize;i++){
        std::vector<float> vec441;
        for(int j = i*sampleRate;j<sampleRate*(i+1);j++){
            auto sam = static_cast<float>(song.samples[STEREO][j]);
            if(sam != 0)
                vec441.push_back(sam);
        }
        if(!vec441.empty())
            samps.push_back(vec441);

//        else{
//            vec441 = {0};
//            samps.push_back(vec441);
//        }
    }
    sampSize = static_cast<int>(samps.size())-1;

    //setting average:
    for(auto&i:samps){
        float sum = 0;
        for(auto& j:i){
            sum += fabs(j);
        }
        average.push_back(sum/i.size());
    }
}

std::vector<std::vector<float>> Track::getSamps(){
    return samps;
}

std::vector<float> Track::getAverage(){
    return average;
}

std::string Track::getPath() {
    return path;
}

int Track::getNumSamples() {
    return numSamples;
}

int Track::getSampleRate() {
    return sampleRate;
}

float Track::getDuration() {
    return duration;
}

int Track::getSampSize() {
    return sampSize;
}
