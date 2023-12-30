#include "myheader.h"

int main() {
    game_data game;

    if (initialize_all(&game, 5) != 0) {
        return -1;
    }

    Gamebackground_call(&game);

    cleanup(&game);

    return 0;
}
