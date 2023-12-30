#include "myheader.h"

void cleanup(game_data* game) {
    al_destroy_bitmap(game->background);
    al_destroy_display(game->display);
    al_destroy_event_queue(game->event_queue);
    al_destroy_sample(game->background_music);
}

void cleanup_enemies(game_data* game) {
    for (int i = 0; i < game->num_enemies; ++i) {
        al_destroy_bitmap(game->enemies[i].enemy_pic);

        for (int j = 0; j < game->enemies[i].num_bullets; ++j) {
            al_destroy_bitmap(game->enemies[i].bullets[j].bullet_pic);
        }

        al_destroy_display(game->enemies[i].enemy_display);
        al_destroy_event_queue(game->enemies[i].event_enemy_queue);
        al_destroy_timer(game->enemies[i].timer);
        al_destroy_timer(game->enemies[i].bullet_timer);
    }
}

void cleanup_plane(plane_data*plane){
    al_destroy_bitmap(plane->plane_img);
    al_destroy_display(plane->plane_display);
    al_destroy_event_queue(plane->event_plane_queue);
    al_destroy_timer(plane->plane_timer);
}