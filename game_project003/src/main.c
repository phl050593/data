#include "myheader.h"

int main() {
    game_data game;
    plane_data plane;
    menu button;

    menu_call();
    
    cleanup(&game);
    cleanup_enemies(&game);
    cleanup_plane(&plane);
    cleanupMenu(&button);    
      
    return 0;
}
