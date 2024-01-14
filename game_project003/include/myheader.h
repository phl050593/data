#ifndef _MYHEADER_H_
#define _MYHEADER_H_

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SCREEN_W 700
#define SCREEN_H 860
#define MAX_ENEMIES 100
#define MAX_BULLETS 70
#define BULLET_UPDATE_TIMER 0.05
#define NEW_ENEMY_COUNT 2
#define BALL_SIZE 40
#define PLANE_MOVE 20
#define PLANE_MIN 0
#define PLANE_MAX 700
#define PLANE_SIZE 40
#define MAX_ENEMIES_LEVEL2 6
#define MAX_ENEMIES_LEVEL3 6
#define MAX_ENEMIES_LEVEL4 8
#define MAX_PLANE_BULLETS 1
#define PLANE_BULLET_UPDATE_TIMER 0.005

#define PLAYER_1 0
#define N_PLAYER 4 //先放著沒有用

typedef struct player_data {
    char name[20];
    int score;
} player_data;

typedef struct enemy_bullet_data {
    float x;
    float y;
    float vy;
    ALLEGRO_BITMAP* bullet_pic;
    int width;
    int height;
} enemy_bullet;

typedef struct plane_bullet_data {
    float x;
    float y;
    float vy;
    ALLEGRO_BITMAP* bullet;
    int width;
    int height;
 
} plane_bullet;

typedef struct plane_bullet_data2
{
    float x;
    float y;
    float vy;
    ALLEGRO_BITMAP *bullet;
    int width;
    int height;

} plane_bullet2;

typedef struct plane_data {
    float x;
    float y;
    ALLEGRO_BITMAP* plane_img;
    ALLEGRO_DISPLAY* plane_display;
    ALLEGRO_TIMER* plane_timer;
    ALLEGRO_TIMER* plane_bullet_timer;
    ALLEGRO_TIMER* plane_bullet_timer2;
    ALLEGRO_EVENT_QUEUE* event_plane_queue;
    ALLEGRO_EVENT_QUEUE* event_plane_bullet_queue;
    ALLEGRO_EVENT_QUEUE* event_plane_bullet_queue2;
    plane_bullet bullets[MAX_PLANE_BULLETS];
    plane_bullet2 bullets2[MAX_PLANE_BULLETS];
    int num_bullets;
    int num_bullets2;
    int width;
    int height;
    int health;
    
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
    int hit_count;
    int destroy_enemy;
    
} enemy_data;

typedef struct game_data {
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP* background;
    ALLEGRO_EVENT_QUEUE* event_queue;
    enemy_data enemies[MAX_ENEMIES];
    int num_enemies;
    ALLEGRO_SAMPLE* background_music;
    ALLEGRO_SAMPLE_INSTANCE* background_music_instance;
    ALLEGRO_TIMER* bullet_spawn_timer;
    ALLEGRO_FONT *Font;
    player_data players[N_PLAYER];
    ALLEGRO_BITMAP* pause_image;
    ALLEGRO_BITMAP* win_image;
    ALLEGRO_BITMAP* lose_image;
    ALLEGRO_FONT* level1_Font;
    ALLEGRO_FONT* level2_Font;
    ALLEGRO_FONT* level3_Font;
    ALLEGRO_FONT* level4_Font;
} game_data;

typedef struct menu
{
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_BITMAP* startGameImage;
    ALLEGRO_BITMAP* exitGameImage;
    ALLEGRO_BITMAP* menuBackgroundImage;
    ALLEGRO_BITMAP* illustrateImage;
    ALLEGRO_BITMAP* nameImage;
    float nameX;
    float nameY;
    float illustrateX;
    float illustrateY;
    float startX;
    float startY;
    float exitX;
    float exitY;
    bool isPressed;
    bool isXInButtonRange;
    bool isYInButtonRange;
    bool isXInButtonRange_exit;
    bool isYInButtonRange_exit;
    bool shouldExit;
} menu;

void initPlayers(player_data *players, int nPlayer);
//void getScore(game_data *game_dataPtr, plane_data* planePtr, int player);

void Gamebackground_call(game_data* game, plane_data* plane);
void draw_enemies(game_data* game);
void draw_game(game_data* game, plane_data* plane);
void draw_background(game_data* game);
void draw_plane(game_data *game, plane_data *plane);
void drawlevel(game_data*game, int picture_number);

void cleanup(game_data *game);
void cleanup_enemies(game_data* game);
void cleanup_plane(plane_data*plane);

void update_enemy_positions(game_data* game, plane_data* plane);
void fire_bullet(enemy_data* enemy);
void fire_plane_bullet(plane_data* plane);
void fire_plane_bullet2(plane_data *plane);

int initialize_all(game_data* game,plane_data* plane, int num_enemies);
int initialize_game(game_data* game, int num_enemies);
int initialize_enemies(enemy_data* enemies, int num_enemies, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void initialize_bullet(enemy_data* enemy, int index);
void initialize_plane_bullet(plane_data *plane, int index);
void initialize_plane_bullet2(plane_data *plane, int index);
int initialize_plane(plane_data* plane);



int initializeButton(menu* button);
void drawMenu(menu* button);
void cleanupMenu(menu* button);
void handleInput(ALLEGRO_EVENT *ev, menu *button, game_data *game);
void menu_call();


void movePlane(plane_data* plane, const ALLEGRO_KEYBOARD_EVENT* kbEvent);

int check_collision(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2);

void check_and_remove_bullet_collision(game_data* game, plane_data* plane);
int check_collision_with_existing(game_data* game, enemy_data* new_enemy);

void spawn_new_enemies(game_data* game);
void spawn_new_enemies2(game_data* game);
void spawn_new_enemies3(game_data* game);
#endif // _MYHEADER_H_