
// #ifndef WEAPON_DATA_H
// #define WEAPON_DATA_H

// #include <stdio.h>
// #include <allegro5/allegro.h>
// #include <allegro5/allegro_image.h>
// #include <allegro5/allegro_audio.h>
// #include <allegro5/allegro_acodec.h>
// #include <allegro5/allegro_font.h>
// #include <allegro5/allegro_ttf.h>
// #define MAX_WEAPON_BULLETS 5
// #define WEAPON_BULLET_UPDATE_TIMER 0.0167 //the speed of the weapon bullet

// typedef struct weapon_data {
//     float x;
//     float y;
//     float vx;
//     float vy;

//     ALLEGRO_BITMAP *weapon_img;
//     ALLEGRO_DISPLAY *weapon_display;
//     ALLEGRO_TIMER* timer;
//     ALLEGRO_TIMER *weapon_timer;
//     ALLEGRO_TIMER *weapon_bullet_timer;
//     ALLEGRO_EVENT_QUEUE* event_queue;
//     ALLEGRO_EVENT_QUEUE *event_weapon_queue;
//     ALLEGRO_EVENT_QUEUE *event_weapon_bullet_queue;
//     weapon_bullet bullets[MAX_WEAPON_BULLETS];

//     int num_bullets;
//     int width;
//     int height;
//     int hit_count;
//     int destroy_weapon;

// } weapon_data;

// typedef struct weapon_bullet_data {
//     float x;
//     float y;
//     float vy;
//     ALLEGRO_BITMAP* bullet;
//     int width;
//     int height;
// } weapon_bullet;

// void weapon_initial(weapon_data *weapon);
// void weapon_initial_bullet(weapon_bullet *weapon);
// void weapon_draw(weapon_data *weapon); 
// void weapon_fire(weapon_data *weapon);
// void weapon_bullet_draw(weapon_bullet *weapon);
// void weapon_bullet_move(weapon_bullet *weapon, int x, int y);
// void weapon_bullet_update(weapon_bullet *weapon);
// void weapon_bullet_collide_enemy(weapon_bullet *weapon, enemy_data *enemy);
// void weapon_bullet_destroy_enemy(weapon_bullet *weapon);
// void weapon_bullet_destroy(weapon_bullet *weapon);
// void weapon_destroy(weapon_data *weapon);

// #endif
