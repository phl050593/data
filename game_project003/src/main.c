#include "myheader.h"

int main() {
    game_data game;
    plane_data plane;
    if (initialize_all(&game, &plane , 5) != 0) {
        return -1;
    }

    Gamebackground_call(&game,&plane);

    cleanup(&game);

    return 0;
}
