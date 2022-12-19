#include "Menu.h"

int main() {

    Menu menu;

    while(menu.getWindow().isOpen()){
        menu.update();
        menu.render();
    }
    return 0;
}
//#include<iostream>
//#include "SFML/Graphics.hpp"
//#include "Entity.h"
//#include "Map.h"
//#include "Pacman.h"
//#include "Player.h"
//std::vector<std::string> map_sketch = {
//        " ################### ",
//        " #........#........# ",
//        " #o##.###.#.###.##o# ",
//        " #.................# ",
//        " #.##.#.#####.#.##.# ",
//        " #....#...#...#....# ",
//        " ####.### # ###.#### ",
//        "    #.#   0   #.#    ",
//        "#####.# ##=## #.#####",
//        "     .  #123#  .     ",
//        "#####.# ##### #.#####",
//        "    #.#       #.#    ",
//        " ####.# ##### #.#### ",
//        " #........#........# ",
//        " #.##.###.#.###.##.# ",
//        " #o.#.....P.....#.o# ",
//        " ##.#.#.#####.#.#.## ",
//        " #....#...#...#....# ",
//        " #.######.#.######.# ",
//        " #.................# ",
//        " ################### "
//};
//int main() {
//    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pac-Man ILMF",sf::Style::Fullscreen);
//    window.setVerticalSyncEnabled(true);
//    //Pacman pacman(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size());
//    Map map(map_sketch.size(),window.getSize().y,window.getSize().x,map_sketch);
//    //map.Innit(map_sketch.size(),window.getSize().y,window.getSize().x,map_sketch);
//    sf::Clock clock;
////    sf::Vector2f pacpos=sf::Vector2f(map.getPac_pos());
//    //pacman.setPosition(sf::Vector2f(424,510));
//    //pacman.setPosition(sf::Vector2f(475, 459));
//    std::vector<std::shared_ptr<Entity>> entities;
//    entities.push_back(std::make_shared<Pacman>(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size()));
//    entities.back()->setPosition(map.getPac_pos());
//    sf::Event ev;
//
//    Player player("");
//
//    while (window.isOpen()) {
//        const float deltaTime=clock.restart().asSeconds();
//        while (window.pollEvent(ev)) {
//            if (ev.type == sf::Event::Closed) window.close();
//        }
//        for(const auto&entity:entities){
//            entity->handleMovement(map.getWalls());
//            entity->move(map.getPoints(),map.getPowerup(),map_sketch,window.getSize().x);
//            entity->update2(deltaTime);
//        }
//
//        window.clear(sf::Color(0, 0, 0));
//        map.drawTo(window);
//        for(const auto&entity:entities){
//            entity->drawTo(window);
//        }
//
//        window.display();
//        std::cout<<map.getPoints().size()<<"\n";
//    }
//}
