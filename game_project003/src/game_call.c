#include "myheader.h"

void menu_call() {
    game_data game;
    plane_data plane;
    menu button;



    if (initializeButton(&button) != 0) {
        fprintf(stderr, "Initialization failed!\n");
        return;
    }
    
    while (1) {
        drawMenu(&button);

        ALLEGRO_EVENT ev;

        if (al_get_next_event(button.event_queue, &ev)) {
            handleInput(&ev, &button, &game);
           
            if(button.isPressed){
                cleanupMenu(&button);
                initialize_all(&game, &plane , 5);
                game.Font = NULL;
                game.Font = al_load_ttf_font("assets/arial.ttf", 16, 0);
                Gamebackground_call(&game,&plane);
                printf("Switching to game\n");
                cleanup(&game);
                cleanup_enemies(&game);
                cleanup_plane(&plane);
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || button.shouldExit) {
            button.shouldExit = true;
            printf("exit\n");
            cleanupMenu(&button);
            cleanup(&game);
            cleanup_enemies(&game);
            cleanup_plane(&plane);

            break;
        }

        }
    }

}


void Gamebackground_call(game_data* game, plane_data* plane) {
    al_play_sample_instance(game->background_music_instance);
    printf("gamebackground call\n");
    while (1) {
        update_enemy_positions(game,plane);
        draw_game(game, plane);
        fire_plane_bullet(plane);

        ALLEGRO_EVENT ev;
        ALLEGRO_EVENT plane_ev;

        al_wait_for_event(game->event_queue, &ev);
        al_wait_for_event(plane->event_plane_queue, &plane_ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || (plane_ev.type == ALLEGRO_EVENT_KEY_DOWN && plane_ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
            break; 
        } else if (plane_ev.type == ALLEGRO_EVENT_KEY_DOWN || plane_ev.type == ALLEGRO_EVENT_KEY_UP) {
            movePlane(plane, &plane_ev.keyboard);
        }
    }
    
    cleanup_enemies(game);
}

