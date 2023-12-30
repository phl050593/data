#ifndef _MYHEADER_H_
#define _MYHEADER_H_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define SCREEN_W 700
#define SCREEN_H 860
#define MAX_ENEMIES 10
#define MAX_BULLETS 50
#define BULLET_UPDATE_TIMER 0.5

#define BALL_SIZE 40
#define PLANE_MOVE 5
#define PLANE_MIN 30
#define PLANE_MAX 580
#define PLANE_SIZE 40


typedef struct enemy_bullet_data {
    float x;
    float y;
    float vy;
    ALLEGRO_BITMAP* bullet_pic;
    int width;
    int height;
} enemy_bullet;

typedef struct plane_data {
    int x;
    int y;
    ALLEGRO_BITMAP* plane_img;
    ALLEGRO_DISPLAY* plane_display;
    ALLEGRO_TIMER* plane_timer;
    ALLEGRO_EVENT_QUEUE* event_plane_queue;
} plane_data;

typedef struct enemy_data {
    float x;
    float y;
    float vx;
    float vy;
    ALLEGRO_DISPLAY* enemy_display;
    ALLEGRO_BITMAP* enemy_pic;
    ALLEGRO_EVENT_QUEUE* event_enemy_queue;
    ALLEGRO_TIMER* timer;
    ALLEGRO_TIMER* bullet_timer;
    ALLEGRO_SAMPLE* shoot_sound;
    int width;
    int height;
    enemy_bullet bullets[MAX_BULLETS];
    int num_bullets;
} enemy_data;

typedef struct game_data {
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP* background;
    ALLEGRO_EVENT_QUEUE* event_queue;
    enemy_data enemies[MAX_ENEMIES];
    int num_enemies;
    ALLEGRO_SAMPLE* background_music;
    ALLEGRO_SAMPLE_INSTANCE* background_music_instance;
} game_data;


void Gamebackground_call(game_data* game, plane_data* plane);
void draw_enemies(game_data* game);
void draw_game(game_data* game, plane_data* plane);
void draw_background(game_data* game);
void draw_plane(plane_data* plane);

void cleanup(game_data* game);
void cleanup_enemies(game_data* game);

void update_enemy_positions(game_data* game);
void fire_bullet(enemy_data* enemy);

int initialize_all(game_data* game,plane_data* plane, int num_enemies);
int initialize_game(game_data* game, int num_enemies);
int initialize_enemies(enemy_data* enemies, int num_enemies, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void initialize_bullet(enemy_data* enemy, int index);
int initialize_plane(plane_data* plane);


void movePlane(plane_data* plane, const ALLEGRO_KEYBOARD_EVENT* kbEvent);


#endif // _MYHEADER_H_