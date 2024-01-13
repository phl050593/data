// #include "myheader.h"
// #include "weapon_data.h"

// void weapon_initial(weapon_data *weapon){
//     weapon->weapon_img = al_load_bitmap("images/weapon.png");
//     weapon->weapon_display = al_create_display(SCREEN_W, SCREEN_H);
//     weapon->timer = al_create_timer(1.0 / 60);
//     weapon->weapon_timer = al_create_timer(1.0 / 60);
//     weapon->weapon_bullet_timer = al_create_timer(WEAPON_BULLET_UPDATE_TIMER);
//     weapon->event_queue = al_create_event_queue();
//     weapon->event_weapon_queue = al_create_event_queue();
//     weapon->event_weapon_bullet_queue = al_create_event_queue();
//     weapon->x = 0;
//     weapon->y = 0;  
//     weapon->vx = 0;
//     weapon->vy = 0;
//     weapon->width = al_get_bitmap_width(weapon->weapon_img);
//     weapon->height = al_get_bitmap_height(weapon->weapon_img);
//     weapon->num_bullets = 0;
//     weapon->hit_count = 0;
//     weapon->destroy_weapon = 0;
//     weapon_initial_bullet(weapon->bullets);
//     al_register_event_source(weapon->event_queue, al_get_display_event_source(weapon->weapon_display));
//     al_register_event_source(weapon->event_queue, al_get_timer_event_source(weapon->timer));
//     al_register_event_source(weapon->event_weapon_queue, al_get_timer_event_source(weapon->weapon_timer));
//     al_register_event_source(weapon->event_weapon_bullet_queue, al_get_timer_event_source(weapon->weapon_bullet_timer));
//     al_start_timer(weapon->timer);
//     al_start_timer(weapon->weapon_timer);
//     al_start_timer(weapon->weapon_bullet_timer);
// }

// void weapon_initial_bullet(weapon_bullet *weapon){
//     weapon->bullet = al_load_bitmap("images/weapon_bullet.png");
//     weapon->x = 0;
//     weapon->y = 0;
//     weapon->vy = 0;
//     weapon->width = al_get_bitmap_width(weapon->bullet);
//     weapon->height = al_get_bitmap_height(weapon->bullet);
// }

// void weapon_draw(weapon_data *weapon){
//     al_draw_bitmap(weapon->weapon_img, weapon->x, weapon->y, 0);
// }

// void weapon_fire(weapon_data *weapon){
//     if(weapon->num_bullets < MAX_WEAPON_BULLETS){
//         weapon->bullets[weapon->num_bullets].x = weapon->x + 30;
//         weapon->bullets[weapon->num_bullets].y = weapon->y + 30;
//         weapon->bullets[weapon->num_bullets].vy = -10;
//         weapon->num_bullets++;
//     }
// }

// void weapon_bullet_draw(weapon_bullet *weapon){
//     al_draw_bitmap(weapon->bullet, weapon->x, weapon->y, 0);
// }

// void weapon_bullet_move(weapon_bullet *weapon, int x, int y){
//     weapon->x = x;
//     weapon->y = y;
// }

// void weapon_bullet_update(weapon_bullet *weapon){
//     weapon->y += weapon->vy;
// }

// void weapon_bullet_collide_enemy(weapon_bullet *weapon, enemy_data *enemy){
//     if(weapon->x >= enemy->x && weapon->x <= enemy->x + enemy->width && weapon->y >= enemy->y && weapon->y <= enemy->y + enemy->height){
//         weapon_bullet_destroy_enemy(weapon);
//         enemy->hit_count++;
//     }
// }

// void weapon_bullet_destroy_enemy(weapon_bullet *weapon){


// }

// void weapon_bullet_destroy(weapon_bullet *weapon){
//     weapon->x = 0;
//     weapon->y = 0;
//     weapon->vy = 0;
// }

// void weapon_destroy(weapon_data *weapon){
//     al_destroy_bitmap(weapon->weapon_img);
//     al_destroy_display(weapon->weapon_display);
//     al_destroy_timer(weapon->timer);
//     al_destroy_timer(weapon->weapon_timer);
//     al_destroy_timer(weapon->weapon_bullet_timer);
//     al_destroy_event_queue(weapon->event_queue);
//     al_destroy_event_queue(weapon->event_weapon_queue);
//     al_destroy_event_queue(weapon->event_weapon_bullet_queue);
// }