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
#define PLANE_MIN 0
#define PLANE_MAX 700
#define PLANE_SIZE 40

#define MAX_PLANE_BULLETS 1
#define PLANE_BULLET_UPDATE_TIMER 0.005

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

typedef struct plane_data {
    float x;
    float y;
    ALLEGRO_BITMAP* plane_img;
    ALLEGRO_DISPLAY* plane_display;
    ALLEGRO_TIMER* plane_timer;
    ALLEGRO_TIMER* plane_bullet_timer;
    ALLEGRO_EVENT_QUEUE* event_plane_queue;
    ALLEGRO_EVENT_QUEUE* event_plane_bullet_queue;
    plane_bullet bullets[MAX_PLANE_BULLETS];
    int num_bullets;
    int width;
    int height;
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
typedef struct menu
{
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* event_queue;
    ALLEGRO_BITMAP* startGameImage;
    ALLEGRO_BITMAP* exitGameImage;
    ALLEGRO_BITMAP* menuBackgroundImage;
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
typedef struct menu2
{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_BITMAP *continueButton;
    ALLEGRO_BITMAP *exit2Button;
    float continueX;
    float continueY;
    float exit2X;
    float exit2Y;
    bool isXInButtonRange_continue;
    bool isYInButtonRange_continue;
    bool isXInButtonRange_exit2;
    bool isYInButtonRange_exit2;
    bool Exitgame;
    bool gamePaused;
    bool gameContinue;
    } menu2;


void Gamebackground_call(game_data* game, plane_data* plane);
void draw_enemies(game_data* game);
void draw_game(game_data* game, plane_data* plane);
void draw_background(game_data* game);
void draw_plane(plane_data* plane);

void cleanup(game_data* game);
void cleanup_enemies(game_data* game);
void cleanup_plane(plane_data*plane);

void update_enemy_positions(game_data* game);
void fire_bullet(enemy_data* enemy);
void fire_plane_bullet(plane_data* plane);

int initialize_all(game_data* game,plane_data* plane, int num_enemies);
int initialize_game(game_data* game, int num_enemies);
int initialize_enemies(enemy_data* enemies, int num_enemies, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue);
void initialize_bullet(enemy_data* enemy, int index);
void initialize_plane_bullet(plane_data* enemy, int index);
int initialize_plane(plane_data* plane);


void movePlane(plane_data* plane, const ALLEGRO_KEYBOARD_EVENT* kbEvent);

int initializeButton(menu* button);
void drawMenu(menu* button);
void cleanupMenu(menu* button);
void handleInput(ALLEGRO_EVENT *ev, menu *button, game_data *game);
void menu_call();

int initializeMenu2(menu2 *button2);
void handleInput2(ALLEGRO_EVENT *ev ,menu2 *button2);
void cleanupMenu2(menu2 *button2);
void drawMenu2(menu2 *button2);
void menu2_call();

#endif // _MYHEADER_H_