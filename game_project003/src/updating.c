#include "myheader.h"

void update_enemy_positions(game_data* game, plane_data* plane) {
    for (int i = 0; i < game->num_enemies; ++i) {
        game->enemies[i].x += game->enemies[i].vx;
        game->enemies[i].y += game->enemies[i].vy;

        if (game->enemies[i].x < 0 || game->enemies[i].x + game->enemies[i].width > SCREEN_W) {
            game->enemies[i].vx = -game->enemies[i].vx;
        }

        if (game->enemies[i].y < 0 || game->enemies[i].y + game->enemies[i].height > SCREEN_H / 3) {
            game->enemies[i].vy = -game->enemies[i].vy;
        }

        ALLEGRO_EVENT ev;
        al_wait_for_event(game->enemies[i].event_enemy_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == game->enemies[i].bullet_timer) {
            fire_bullet(&game->enemies[i]);
        }

        for (int j = 0; j < game->enemies[i].num_bullets; ++j) {
            game->enemies[i].bullets[j].y += game->enemies[i].bullets[j].vy;

            if (game->enemies[i].bullets[j].y > SCREEN_H) {
                al_destroy_bitmap(game->enemies[i].bullets[j].bullet_pic);
                game->enemies[i].bullets[j] = game->enemies[i].bullets[game->enemies[i].num_bullets - 1];
                game->enemies[i].num_bullets--;
            }
        }

    }
    check_and_remove_bullet_collision(game, plane);
    
}


void movePlane(plane_data* plane, const ALLEGRO_KEYBOARD_EVENT* kbEvent) {
    if (kbEvent->keycode == ALLEGRO_KEY_LEFT && plane->x > PLANE_MIN) {
        plane->x -= PLANE_MOVE;
    } else if (kbEvent->keycode == ALLEGRO_KEY_RIGHT && plane->x < PLANE_MAX-PLANE_SIZE) {
        plane->x += PLANE_MOVE;
    }


}

void fire_bullet(enemy_data* enemy) {
    al_stop_samples();

    if (enemy->num_bullets < MAX_BULLETS) {
        initialize_bullet(enemy, enemy->num_bullets);
        
        enemy->num_bullets++;
        al_play_sample(enemy->shoot_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    }
}

void fire_plane_bullet(plane_data* plane) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(plane->event_plane_bullet_queue, &ev);

    for (int j = 0; j < plane->num_bullets; ++j) {
        plane->bullets[j].y += plane->bullets[j].vy;

        if (plane->bullets[j].y < 0) {
            al_destroy_bitmap(plane->bullets[j].bullet);
            plane->bullets[j] = plane->bullets[plane->num_bullets - 1];
            plane->num_bullets--;
            
        }
    }
    if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == plane->plane_bullet_timer)
    {
        if (plane->num_bullets < MAX_PLANE_BULLETS) {
            initialize_plane_bullet(plane, plane->num_bullets);
            plane->num_bullets++;

        }
    }
}


int check_collision(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2) {
    return x1 < x2 + w2 &&
           x1 + w1 > x2 &&
           y1 < y2 + h2 &&
           y1 + h1 > y2;
}


void check_and_remove_bullet_collision(game_data* game, plane_data* plane) {
    
    for (int i = 0; i < game->num_enemies; ++i) {
        for (int j = 0; j < game->enemies[i].num_bullets; ++j) {
            if (check_collision(game->enemies[i].bullets[j].x, game->enemies[i].bullets[j].y,
                                 game->enemies[i].bullets[j].width, game->enemies[i].bullets[j].height,
                                 plane->x+20, plane->y, plane->width, plane->height)) {
                al_destroy_bitmap(game->enemies[i].bullets[j].bullet_pic);
                game->enemies[i].bullets[j] = game->enemies[i].bullets[game->enemies[i].num_bullets - 1];
                game->enemies[i].num_bullets--;

                
            }
        }
    }

    for (int i = 0; i < plane->num_bullets; ++i) {
        for (int j = 0; j < game->num_enemies; ++j) {
            if (check_collision(plane->bullets[i].x, plane->bullets[i].y,
                                 plane->bullets[i].width, plane->bullets[i].height,
                                 game->enemies[j].x, game->enemies[j].y,
                                 game->enemies[j].width, game->enemies[j].height)) {
                al_destroy_bitmap(plane->bullets[i].bullet);
                plane->bullets[i] = plane->bullets[plane->num_bullets - 1];
                plane->num_bullets--;
               game->enemies[j].destroy_enemy ++;
               
            }
        }
    }
   
     for (int i = 0; i < game->num_enemies; ++i) {
       
        if (game->enemies[i].destroy_enemy>=3) {
            // Other destruction code for enemy resources

            // Remove destroyed enemy
            game->enemies[i] = game->enemies[game->num_enemies - 1];
           
          game->num_enemies--;

        

        }
    }
}
