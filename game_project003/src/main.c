#include "myheader.h"

int main() {

    game_data game;
    plane_data plane;
    player_data *players = game.players;

    game.Font = NULL;


    if (initialize_all(&game, &plane , 5) != 0) {
        return -1;
    }
    game.Font = al_load_ttf_font("assets/arial.ttf", 16, 0); 
                                                                                        
    Gamebackground_call(&game,&plane);
        
    cleanup(&game);
    cleanup_enemies(&game);
    cleanup_plane(&plane);
    
    return 0;
}
