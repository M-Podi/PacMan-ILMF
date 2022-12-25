#include "Menu.h"

int main() {

    auto &menu = Menu::get_menu();

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
//#include "Ghosts.h"
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
//    Map map(map_sketch.size(),window.getSize().y,window.getSize().x,map_sketch);
//    sf::Clock clock;
//    std::vector<std::shared_ptr<Entity>> entities;
//    entities.push_back(std::make_shared<Pacman>(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size()));
//    entities.back()->setPosition(map.getPac_pos());
//    std::vector<sf::Texture> colors;
//    colors.push_back(sf::Texture());
//    colors.back()=Resources::BlueG;
//    colors.push_back(sf::Texture());
//    colors.back()=Resources::RedG;
//    colors.push_back(sf::Texture());
//    colors.back()=Resources::OrangeG;
//    colors.push_back(sf::Texture());
//    colors.back()=Resources::PinkG;
//    std::vector<sf::Vector2f> GhostPos=map.getGhost_pos();
//    for(int i=0;i<GhostPos.size();i++){
//        entities.push_back(std::make_shared<Ghosts>(window.getSize().y/map_sketch.size(),window.getSize().y/map_sketch.size(),colors[i]));
//        entities.back()->setPosition(GhostPos[i]);
//    }
//    sf::Event ev;
//
//    Player player("aa");
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
//    }
//}
