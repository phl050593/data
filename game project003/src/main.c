#include "myheader.h"

int main() {
    game_data game;
    plane_data plane;
    menu button;
    if (initialize_all(&game, &plane , 5) != 0) {
        return -1;
    }

    menu_call();    
    return 0;
}
