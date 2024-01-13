#include "myheader.h"

void draw_game(game_data* game, plane_data* plane) {

    draw_background(game);
    draw_enemies(game);
    draw_plane(plane);
    al_draw_textf(game->Font, al_map_rgb(255, 255, 255), 75, 0, -1,"Player Score: %d", game->players[PLAYER_1].score);
    al_draw_textf(game->Font, al_map_rgb(255, 255, 255), 600, 0, -1,"Plane Health: %d", plane->health);
    

    al_flip_display();
}

void draw_background(game_data* game)
{
    al_clear_to_color(al_map_rgb(0, 0, 0));

    int img_w = al_get_bitmap_width(game->background);
    int img_h = al_get_bitmap_height(game->background);

    al_draw_scaled_bitmap(
        game->background, 0, 0, img_w, img_h, 0, 0, SCREEN_W, SCREEN_H, 0
    );
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

void draw_plane(plane_data* plane)
{
    al_draw_bitmap(plane->plane_img, plane->x, plane->y, 0);

    for (int j = 0; j < plane->num_bullets; ++j) 
        {
            al_draw_scaled_bitmap(
                plane->bullets[j].bullet,
                0, 0,
                al_get_bitmap_width(plane->bullets[j].bullet),
                al_get_bitmap_height(plane->bullets[j].bullet),
                plane->bullets[j].x,
                plane->bullets[j].y,
                plane->bullets[j].width,
                plane->bullets[j].height,
                0
            );
        }
}

void drawMenu(menu* button) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    int img_w = al_get_bitmap_width(button->menuBackgroundImage);
    int img_h = al_get_bitmap_height(button->menuBackgroundImage);
    al_draw_scaled_bitmap(
        button->menuBackgroundImage, 0, 0, img_w, img_h, 0, 0, SCREEN_W, SCREEN_H, 0
    );
    int startWidth = al_get_bitmap_width(button->startGameImage);
    int startHeight = al_get_bitmap_height(button->startGameImage);
    
    float startX = (SCREEN_W - startWidth) / 2.0;
    float startY = (SCREEN_H - startHeight) / 2.0 - 50.0;  // 調整 Y 座標

    al_draw_bitmap(button->startGameImage, startX, startY, 0);

    // 繪製 exit 按鈕
    int exitWidth = al_get_bitmap_width(button->exitGameImage);
    int exitHeight = al_get_bitmap_height(button->exitGameImage);
    float exitX = (SCREEN_W - exitWidth) / 2.0;
    float exitY = (SCREEN_H - exitHeight) / 2.0 + 50.0;
    
    al_draw_bitmap(button->exitGameImage, exitX, exitY, 0);

    int illustrateWidth = al_get_bitmap_width(button->illustrateImage);
    int illustrateHeight = al_get_bitmap_height(button->illustrateImage);
    float illustrateX = (SCREEN_W - exitWidth) / 2.0 - 200.0;
    float illustrateY = (SCREEN_H - exitHeight) / 2.0 + 150.0;

    al_draw_bitmap(button->illustrateImage, illustrateX, illustrateY, 0);



    al_flip_display();
}