#include <iostream>
#include "src/Controller/controller.h"

int main() {
    Track tr;
    Scenario scenario("/home/pyxel/Escritorio/UTEC/poo2/stickman_rider/res/img/min.jpg");
    tr.loadSong("/home/pyxel/Escritorio/UTEC/poo2/stickman_rider/res/tracks/forever.wav");
    std::vector<std::vector<float>>samps = tr.getSamps();
    std::vector<float> av = tr.getAverage();

/* Para dibujar las barras en consola:
    for(int i=0;i<samps.size();i++){
        std::cout<<i<<"\ts"<<"\t";
        for(int j=0;j<(int)(av[i]*200);j++){
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
*/
    Controller controller(scenario, tr);
    controller.drawScreen();
}