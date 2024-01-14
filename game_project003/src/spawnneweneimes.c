#include "myheader.h"

void spawn_new_enemies(game_data* game) {

    

    // 在這裡新增新的敵機
    for (int i=0;i<MAX_ENEMIES_LEVEL2;i++){
       game->enemies[i].destroy_enemy = 0;
    }
    for (int i = 0; i < NEW_ENEMY_COUNT; ++i) {
        
        // 確保敵機數量未超過敵機數組的大小
        if (game->num_enemies < MAX_ENEMIES_LEVEL2) {
            initialize_enemies(&game->enemies[game->num_enemies], 1, game->display, game->event_queue);

            // 检查新生成的敌机是否与现有敌机或飞机发生了重叠
            while (check_collision_with_existing(game, &game->enemies[game->num_enemies])) {
                // 调整敌机的位置，直到不再发生重叠
                // 例如，可以随机设置新的 x 和 y 值
                int width=80;
                int height=80;
                game->enemies[game->num_enemies].x = rand() % (SCREEN_W -width);
                game->enemies[game->num_enemies].y = rand() % (SCREEN_H / 3 - height);
            }
            game->enemies[game->num_enemies].bullet_timer = al_create_timer(0.001);  // 調整計時器間隔
            al_register_event_source(game->event_queue, al_get_timer_event_source(game->enemies[game->num_enemies].bullet_timer));
            al_start_timer(game->enemies[game->num_enemies].bullet_timer);

          
            game->num_enemies++;
        } else {
            // 處理敵機數量超過限制的情況
            printf("1\n");
            break;
        }
    }
    for (int i = 0; i < game->num_enemies; ++i) {
        ALLEGRO_EVENT event;
        while (al_get_next_event(game->event_queue, &event)) {
            if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == game->enemies[i].bullet_timer) {
                fire_bullet(&game->enemies[i]);
            }
        }
    }
    
}
void spawn_new_enemies2(game_data* game) {
    // 在這裡新增新的敵機

    for (int i=0;i<MAX_ENEMIES_LEVEL3;i++){
       game->enemies[i].destroy_enemy = 0;
    }

    for (int i = 0; i < NEW_ENEMY_COUNT; ++i) {
        // 確保敵機數量未超過敵機數組的大小
        if (game->num_enemies < MAX_ENEMIES_LEVEL3) {
            initialize_enemies(&game->enemies[game->num_enemies], 1, game->display, game->event_queue);

            // 检查新生成的敌机是否与现有敌机或飞机发生了重叠
            while (check_collision_with_existing(game, &game->enemies[game->num_enemies])) {
                // 调整敌机的位置，直到不再发生重叠
                // 例如，可以随机设置新的 x 和 y 值
                int width=80;
                int height=80;
                game->enemies[game->num_enemies].x = rand() % (SCREEN_W -width);
                game->enemies[game->num_enemies].y = rand() % (SCREEN_H / 3 - height);
            }
            game->enemies[game->num_enemies].bullet_timer = al_create_timer(0.001);  // 調整計時器間隔
            al_register_event_source(game->event_queue, al_get_timer_event_source(game->enemies[game->num_enemies].bullet_timer));
            al_start_timer(game->enemies[game->num_enemies].bullet_timer);

          
            game->num_enemies++;
        } else {
            // 處理敵機數量超過限制的情況
            printf("2\n");
            break;
        }
    }
    for (int i = 0; i < game->num_enemies; ++i) {
        ALLEGRO_EVENT event;
        while (al_get_next_event(game->event_queue, &event)) {
            if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == game->enemies[i].bullet_timer) {
                fire_bullet(&game->enemies[i]);
            }
        }
    }
    
}

void spawn_new_enemies3(game_data* game) {
    // 在這裡新增新的敵機
    for (int i=0;i<MAX_ENEMIES_LEVEL4;i++){
       game->enemies[i].destroy_enemy = 0;
    }
    for (int i = 0; i < NEW_ENEMY_COUNT; ++i) {
        // 確保敵機數量未超過敵機數組的大小
        if (game->num_enemies < MAX_ENEMIES_LEVEL4) {
            initialize_enemies(&game->enemies[game->num_enemies], 1, game->display, game->event_queue);

            // 检查新生成的敌机是否与现有敌机或飞机发生了重叠
            while (check_collision_with_existing(game, &game->enemies[game->num_enemies])) {
                // 调整敌机的位置，直到不再发生重叠
                // 例如，可以随机设置新的 x 和 y 值
                int width=80;
                int height=80;
                game->enemies[game->num_enemies].x = rand() % (SCREEN_W -width);
                game->enemies[game->num_enemies].y = rand() % (SCREEN_H / 3 - height);
            }
       
            game->enemies[game->num_enemies].bullet_timer = al_create_timer(0.001);  // 調整計時器間隔
            al_register_event_source(game->event_queue, al_get_timer_event_source(game->enemies[game->num_enemies].bullet_timer));
            al_start_timer(game->enemies[game->num_enemies].bullet_timer);
          
            game->num_enemies++;
        } else {
            // 處理敵機數量超過限制的情況
            printf("3\n");
            break;
        }
    }
    for (int i = 0; i < game->num_enemies; ++i) {
        ALLEGRO_EVENT event;
        while (al_get_next_event(game->event_queue, &event)) {
            if (event.type == ALLEGRO_EVENT_TIMER && event.timer.source == game->enemies[i].bullet_timer) {
                fire_bullet(&game->enemies[i]);
            }
        }
    }
   
}
// 检查新生成的敌机是否与现有敌机或飞机发生了重叠
int check_collision_with_existing(game_data* game, enemy_data* new_enemy) {
    for (int i = 0; i < game->num_enemies; ++i) {
        if (check_collision(new_enemy->x, new_enemy->y, new_enemy->width, new_enemy->height,
                            game->enemies[i].x, game->enemies[i].y, game->enemies[i].width, game->enemies[i].height)) {
            return 1; // 发生重叠
        }
    }

    // 如果新敌机与现有敌机都没有发生重叠，则检查与飞机是否发生重叠
    // 这里需要根据您的代码结构来获取飞机的位置信息
    // 示例：plane_data* plane = &game->player_planes[0];
    // if (check_collision(new_enemy->x, new_enemy->y, new_enemy->width, new_enemy->height,
    //                     plane->x, plane->y, plane->width, plane->height)) {
    //     return 1; // 发生重叠
    // }

    return 0; // 未发生重叠
}