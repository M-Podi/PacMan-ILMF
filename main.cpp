#include "Menu.h"

int main() {

    auto &menu = Menu::get_menu();

    while(menu.getWindow().isOpen()){
        menu.update();
        menu.render();
    }
    return 0;
}




