#include "myheader.h"

int initialize_all(game_data* game, plane_data* plane, int num_enemies) {
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


int initialize_game(game_data* game, int num_enemies) {
    game->display = al_create_display(SCREEN_W, SCREEN_H);
    game->background = al_load_bitmap("./starry_sky1.jpg");

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
        enemies[i].hit_count = 0;
        
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

        enemies[i].width = 70;
        enemies[i].height = 70;

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

#include "myheader.h"

void Gamebackground_call(game_data* game, plane_data* plane) {
    al_play_sample_instance(game->background_music_instance);

    while (1) {
        update_enemy_positions(game, plane);
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


int initialize_plane(plane_data* plane) {
    plane->health = 5;
    plane->x = SCREEN_W / 2;
    plane->y = SCREEN_H - PLANE_SIZE - 10;
    plane->plane_img = al_load_bitmap("./ball.bmp");
    plane->plane_timer = al_create_timer(1.0 / 60);
    plane->event_plane_queue = al_create_event_queue(); 
    plane->event_plane_bullet_queue = al_create_event_queue(); 
    plane->plane_bullet_timer = al_create_timer(PLANE_BULLET_UPDATE_TIMER); 
    al_register_event_source(plane->event_plane_queue, al_get_timer_event_source(plane->plane_timer));
    al_register_event_source(plane->event_plane_queue, al_get_keyboard_event_source());
    al_start_timer(plane->plane_timer);
    al_register_event_source(plane->event_plane_bullet_queue, al_get_timer_event_source(plane->plane_bullet_timer));
    al_start_timer(plane->plane_bullet_timer);
    
    return 0;
}
 