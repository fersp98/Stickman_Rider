//
// Created by pyxel on 08/07/18.
//

#include "controller.h"
Controller::Controller() = default;

Controller::Controller(Scenario &_scene, Track &_song) {
    scenario = _scene;
    track = _song;
}

void Controller::drawScreen() {
    sf::Clock clock;
    int tiempo_ant = 0,R,G,B;

    //Window Properties
    unsigned int height,width;
    height = sf::VideoMode::getDesktopMode().height;
    width = sf::VideoMode::getDesktopMode().width;
    sf::RenderWindow window(sf::VideoMode(width,height),"Audio Visualizer");
    sf::Texture BackgroundTexture;
    sf::Sprite background;
    sf::Vector2u TextureSize;
    sf::Vector2u WindowSize;
    if(BackgroundTexture.loadFromFile(scenario.getPath())){
        TextureSize = BackgroundTexture.getSize();
        WindowSize = window.getSize();

        float scaleX = (float) WindowSize.x/TextureSize.x;
        float scaleY = (float) WindowSize.y/TextureSize.y;
        background.setTexture(BackgroundTexture);
        background.setScale(scaleX,scaleY);
    } else
        std::cout<<"Error Loading Background :("<<std::endl;
    //Music Properties
    sf::Music music;
    if (!music.openFromFile(track.getPath()))
        std::cout<<"Error Loading Track :("<<std::endl; // error
    music.play();


    //Drawing Bars
    std::vector<sf::ConvexShape> barra;
    int len = width/track.getSampSize();
    int posx = 1;
    std::vector<float> av = track.getAverage();


    for(int i=0;i<av.size();i++)
    {
        auto y = height/2-10-(int)(av[i]*300);
        //std::cout<<y<<std::endl;
        //std::cout<<i<<" "<<x<<" " << y<<std::endl;
        barra.push_back(sf::ConvexShape());
        barra[i].setPointCount(4);
        barra[i].setPoint(0,sf::Vector2f(posx,y));
        barra[i].setPoint(1,sf::Vector2f(posx,height/2-10));
        barra[i].setPoint(2,sf::Vector2f(posx+len,height/2-10));
        barra[i].setPoint(3,sf::Vector2f(posx+len,y));
        barra[i].setFillColor(sf::Color::Transparent);
        posx += len+1;
    }

    //Rendering Window
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        window.draw(background);

        for(int i=0;i<av.size();i++) {
            window.draw(barra[i]);
        }

        sf::Time elapsed1 = clock.getElapsedTime();
        if(tiempo_ant!=int(elapsed1.asSeconds())){
            barra[int(elapsed1.asSeconds())-1].setFillColor(sf::Color(255-(int)elapsed1.asSeconds(),255-(int)elapsed1.asSeconds(),(int)elapsed1.asSeconds()));
            tiempo_ant= int(elapsed1.asSeconds());
            if(int(elapsed1.asSeconds()) == track.getSampSize()){
                std::cout<<elapsed1.asSeconds()<<"\t"<<track.getSampSize();
                std::cout<<" Ya terminó prros >:(" <<std::endl;
                window.close();
                break;
            }
        }

        window.display();
    }
}
