#include "myheader.h"
#include "weapon_data.h"

int initialize_all(game_data* game, plane_data* plane, int num_enemies) {
    al_init_font_addon();
    al_init_ttf_addon();

    if (!al_init() || !al_init_image_addon() || !al_install_audio() || !al_init_acodec_addon()|| !al_install_keyboard()) {
        printf("initial failed\n");
        return -1;
    }

    if (!al_reserve_samples(2)) {
        printf("reserve audio failed\n");
        return -1;
    }

    if (initialize_game(game, num_enemies) != 0) {
        printf("initaial game failed\n");
        return -1;
    }
    if (initialize_enemies(game->enemies, game->num_enemies, game->display, game->event_queue) != 0) {
        printf("initaial enemy failed\n");
        return-1;
    }
    if (initialize_plane(plane) != 0) {
        printf("initaial plane failed\n");
        return-1;
    }

    

    return 0;
}

int initializeButton(menu* button){
    al_init_font_addon();
    al_init_ttf_addon();

if (!al_init() || !al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }
    button->display = al_create_display(SCREEN_W, SCREEN_H);
    button->menuBackgroundImage = al_load_bitmap("./starry_sky1.jpg");


    if (!button->display || !button->menuBackgroundImage) {
        fprintf(stderr, "Failed to initialize or load resources!\n");
        return -1;
    }

    button->startGameImage = al_load_bitmap("start.png");
    if (!button->startGameImage) {
        fprintf(stderr, "Failed to load start game image!\n");
        return -1;
    }
    button->startX = (SCREEN_W - al_get_bitmap_width(button->startGameImage)) / 2.0;
    button->startY = (SCREEN_H - al_get_bitmap_height(button->startGameImage)) / 2.0 -50;

    button->exitGameImage = al_load_bitmap("exit.png");
    if (!button->exitGameImage) {
        fprintf(stderr, "Failed to load exit game image!\n");
        return -1;
    }
    button->exitX = (SCREEN_W - al_get_bitmap_width(button->exitGameImage)) / 2.0;
    button->exitY = (SCREEN_H - al_get_bitmap_height(button->exitGameImage)) / 2.0 +50;

    button->illustrateImage=al_load_bitmap("./illustrate.jpg");
    if (!button->illustrateImage) {
        fprintf(stderr, "Failed to load illustrate image!\n");
        return -1;
    }
    button->illustrateX = (SCREEN_W - al_get_bitmap_width(button->illustrateImage)) / 2.0;
    button->illustrateY = (SCREEN_H - al_get_bitmap_height(button->illustrateImage)) / 2.0 +100;

    button->nameImage=al_load_bitmap("./name.png");
    if (!button->nameImage) {
        fprintf(stderr, "Failed to load name image!\n");
        return -1;
    }
    button->nameX = (SCREEN_W - al_get_bitmap_width(button->nameImage)) / 2.0;
    button->nameY = (SCREEN_H - al_get_bitmap_height(button->nameImage)) / 2.0 +100;
    
    button->event_queue = al_create_event_queue();
    if (!button->event_queue) {
        fprintf(stderr, "Failed to create event queue!\n");
        return -1;
    }

    al_install_mouse();
    al_install_keyboard();
    al_register_event_source(button->event_queue, al_get_display_event_source(button->display));
    al_register_event_source(button->event_queue, al_get_mouse_event_source());
    al_register_event_source(button->event_queue, al_get_keyboard_event_source());
    button->shouldExit = false;
    return 0;
}

int initialize_game(game_data* game, int num_enemies) {
    game->display = al_create_display(SCREEN_W, SCREEN_H);
    game->background = al_load_bitmap("./starry_sky1.jpg");
    game->pause_image = al_load_bitmap("./pause.jpg");
    game->win_image = al_load_bitmap("./win.png");
    game->lose_image = al_load_bitmap("./lose.png");
    game->level1_Font = NULL;
    game->level1_Font = al_load_ttf_font("assets/arial.ttf", 20, 0);
    game->level2_Font = NULL;
    game->level2_Font = al_load_ttf_font("assets/arial.ttf", 20, 0);
    game->level3_Font = NULL;
    game->level3_Font = al_load_ttf_font("assets/arial.ttf", 20, 0);
    game->level4_Font = NULL;
    game->level4_Font = al_load_ttf_font("assets/arial.ttf", 20, 0);


    if (!game->display || !game->background) {
        return -1;
    }

    game->event_queue = al_create_event_queue();
    if (!game->event_queue) {

        return -1;
    }

    al_register_event_source(game->event_queue, al_get_display_event_source(game->display));

    game->num_enemies = num_enemies;

    al_set_new_display_flags(ALLEGRO_OPENGL);
    game->background_music = al_load_sample("./background_music.wav");
    game->background_music_instance = al_create_sample_instance(game->background_music);

    al_set_sample_instance_playmode(game->background_music_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(game->background_music_instance, al_get_default_mixer());
   
    return 0;
}


int initialize_enemies(enemy_data* enemies, int num_enemies, ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue) {
    srand(time(NULL));
    
    for (int i = 0; i < num_enemies; ++i) {
        
        enemies[i].enemy_display = display;
        enemies[i].enemy_pic = al_load_bitmap("./enemy.png");

        if (!enemies[i].enemy_pic) {
            return -1;
        }

        enemies[i].event_enemy_queue = event_queue;
        enemies[i].timer = al_create_timer(1.0 / 240);
        enemies[i].bullet_timer = al_create_timer(BULLET_UPDATE_TIMER);
        enemies[i].shoot_sound = al_load_sample("enemy_shot.wav");

        if (!enemies[i].shoot_sound) {
            return -1;
        }

        if (!enemies[i].timer || !enemies[i].bullet_timer) {
            return -1;
        }

        al_register_event_source(enemies[i].event_enemy_queue, al_get_timer_event_source(enemies[i].timer));
        al_start_timer(enemies[i].timer);
        al_register_event_source(enemies[i].event_enemy_queue, al_get_timer_event_source(enemies[i].bullet_timer));
        al_start_timer(enemies[i].bullet_timer);

        enemies[i].width = 80;
        enemies[i].height = 80;

        enemies[i].x = rand() % (SCREEN_W - enemies[i].width);
        enemies[i].y = rand() % (SCREEN_H / 3 - enemies[i].height);
        enemies[i].vx = (rand() % 2 == 0 ? 1 : -1) * (rand() % 5 + 1);
        enemies[i].vy = (rand() % 2 == 0 ? 1 : -1) * (rand() % 5 + 1);
        enemies[i].num_bullets = 0;
    }
   
    return 0;
}

void initialize_bullet(enemy_data* enemy, int index) {
    enemy->bullets[index].bullet_pic = al_load_bitmap("./enemy_bullet.png");
    enemy->bullets[index].x = enemy->x + enemy->width / 2;
    enemy->bullets[index].y = enemy->y + enemy->height;
    enemy->bullets[index].vy = 5.0;
    enemy->bullets[index].width = 40;
    enemy->bullets[index].height = 40;
    
}

void initialize_plane_bullet(plane_data* plane, int index)
{
    plane->bullets[index].bullet = al_load_bitmap("./plane_bullet.png");
    plane->bullets[index].x = plane->x + plane->width / 2;
    plane->bullets[index].y = plane->y + plane->height;
    plane->bullets[index].vy = -20.0;
    plane->bullets[index].width = 40;
    plane->bullets[index].height = 40;
    
}

void initialize_plane_bullet2(plane_data *plane, int index)
{
    plane->bullets2[index].bullet = al_load_bitmap("ball.bmp");
    plane->bullets2[index].x = plane->x + plane->width / 2;
    plane->bullets2[index].y = plane->y + plane->height;
    plane->bullets2[index].vy = -20.0;
    plane->bullets2[index].width = 40;
    plane->bullets2[index].height = 40;
}

int initialize_plane(plane_data* plane) {
    plane->health = 5;
    plane->x = SCREEN_W / 2;
    plane->y = SCREEN_H - PLANE_SIZE - 10;
    plane->plane_img = al_load_bitmap("./plane.png");
    plane->plane_timer = al_create_timer(1.0 / 60);
    plane->event_plane_queue = al_create_event_queue(); 
    plane->event_plane_bullet_queue = al_create_event_queue(); 
    plane->event_plane_bullet_queue2 = al_create_event_queue(); 
    plane->plane_bullet_timer = al_create_timer(PLANE_BULLET_UPDATE_TIMER);  // 請根據需要調整計時器間隔
    plane->plane_bullet_timer2 = al_create_timer(PLANE_BULLET_UPDATE_TIMER);  // 根據需要調整
    al_register_event_source(plane->event_plane_queue, al_get_timer_event_source(plane->plane_timer));
    al_register_event_source(plane->event_plane_queue, al_get_keyboard_event_source());
    al_start_timer(plane->plane_timer);
    al_register_event_source(plane->event_plane_bullet_queue, al_get_timer_event_source(plane->plane_bullet_timer));
    al_register_event_source(plane->event_plane_bullet_queue2, al_get_timer_event_source(plane->plane_bullet_timer2));
    al_start_timer(plane->plane_bullet_timer);
    al_start_timer(plane->plane_bullet_timer2);
    
    return 0;
}

void handleInput(ALLEGRO_EVENT *ev, menu *button, game_data *game) {
    int startWidth = al_get_bitmap_width(button->startGameImage);
    int startHeight = al_get_bitmap_height(button->startGameImage);
    int exitWidth = al_get_bitmap_width(button->exitGameImage);
    int exitHeight = al_get_bitmap_height(button->exitGameImage);
    if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        int mouseX = ev->mouse.x;
        int mouseY = ev->mouse.y;

        button ->isXInButtonRange = (mouseX >= button->startX) && (mouseX <= button->startX + startWidth);
        button ->isYInButtonRange = (mouseY >= button->startY) && (mouseY <= button->startY + startHeight);

        button -> isXInButtonRange_exit = (mouseX >= button->exitX) && (mouseX <= button->exitX + exitWidth);
        button -> isYInButtonRange_exit = (mouseY >= button->exitY) && (mouseY <= button->exitY + exitHeight);

            if (button->isXInButtonRange && button->isYInButtonRange) {
                button->isPressed = true;
                printf("button start is pressed\n");
                
            }
    
            if (button->isXInButtonRange_exit && button->isYInButtonRange_exit) {
                printf("button exit is pressed\n");
                button->shouldExit = true;
            }
            
    }
            
}


