#include "Menu.h"

int main() {

    Menu menu;

    while(menu.getWindow().isOpen()){
        menu.update();
        menu.render();
    }
    return 0;
}
