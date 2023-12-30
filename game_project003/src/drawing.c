#include "myheader.h"

void draw_game(game_data* game) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    int img_w = al_get_bitmap_width(game->background);
    int img_h = al_get_bitmap_height(game->background);

    al_draw_scaled_bitmap(
        game->background, 0, 0, img_w, img_h, 0, 0, SCREEN_W, SCREEN_H, 0
    );

    draw_enemies(game);

    al_flip_display();
}

void draw_enemies(game_data* game) {
    for (int i = 0; i < game->num_enemies; ++i) {
        al_draw_bitmap(game->enemies[i].enemy_pic, game->enemies[i].x, game->enemies[i].y, 0);
        al_draw_scaled_bitmap(
            game->enemies[i].enemy_pic, 0, 0, al_get_bitmap_width(game->enemies[i].enemy_pic),
            al_get_bitmap_height(game->enemies[i].enemy_pic), game->enemies[i].x, game->enemies[i].y,
            game->enemies[i].width, game->enemies[i].height, 0
        );

        for (int j = 0; j < game->enemies[i].num_bullets; ++j) 
        {
            al_draw_scaled_bitmap(
                game->enemies[i].bullets[j].bullet_pic,
                0, 0,
                al_get_bitmap_width(game->enemies[i].bullets[j].bullet_pic),
                al_get_bitmap_height(game->enemies[i].bullets[j].bullet_pic),
                game->enemies[i].bullets[j].x,
                game->enemies[i].bullets[j].y,
                game->enemies[i].bullets[j].width,
                game->enemies[i].bullets[j].height,
                0
            );
        }
    }
}