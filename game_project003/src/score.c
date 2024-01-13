#include "myheader.h"

void initPlayers(player_data *players, int nPlayer)
{
    int i = 0;
    for (i = 0; i < nPlayer; ++i)
    {
        players[i].score = 0;
    }
}

int check_collision(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2)
{
    return x1 < x2 + w2 &&
           x1 + w1 > x2 &&
           y1 < y2 + h2 &&
           y1 + h1 > y2;
}

void check_and_remove_bullet_collision(game_data *game, plane_data *plane)
{
    player_data *playersPtr = game->players;

    for (int i = 0; i < game->num_enemies; ++i)
    {
        for (int j = 0; j < game->enemies[i].num_bullets; ++j)
        {
            if (check_collision(game->enemies[i].bullets[j].x, game->enemies[i].bullets[j].y,
                                game->enemies[i].bullets[j].width, game->enemies[i].bullets[j].height,
                                plane->x + 20, plane->y, plane->width, plane->height))
            {
                al_destroy_bitmap(game->enemies[i].bullets[j].bullet_pic);
                game->enemies[i].bullets[j] = game->enemies[i].bullets[game->enemies[i].num_bullets - 1];
                game->enemies[i].num_bullets--;
                plane->health--;
            }
        }
    }

    if (playersPtr[PLAYER_1].score < 320)
    {
        for (int i = 0; i < plane->num_bullets; ++i)
        {
            for (int j = 0; j < game->num_enemies; ++j)
            {
                if (PLAYER_1 == 0)
                {
                    if (check_collision(plane->bullets[i].x, plane->bullets[i].y,
                                        plane->bullets[i].width, plane->bullets[i].height,
                                        game->enemies[j].x, game->enemies[j].y,
                                        game->enemies[j].width - 40, game->enemies[j].height-40))
                    {
                        al_destroy_bitmap(plane->bullets[i].bullet);
                        plane->bullets[i] = plane->bullets[plane->num_bullets - 1];
                        plane->num_bullets--;
                        game->enemies[j].destroy_enemy++;
                        playersPtr[PLAYER_1].score += 20;
                        printf("enemy X POSITION=%f~%f\n", game->enemies[j].x, game->enemies[j].x + game->enemies[j].width);
                        printf("enemy Y POSITION=%f~%f\n", game->enemies[j].y, game->enemies[j].y + game->enemies[j].height);
                        printf("plane Bullet POSITION=(%f,%f)\n", plane->bullets[i].x, plane->bullets[i].y);
                        printf("\n");
                    }
                }
            }
        }
    }

    if (playersPtr[PLAYER_1].score >= 320)
    {
        for (int i = 0; i < plane->num_bullets2; ++i)
        {
            for (int j = 0; j < game->num_enemies; ++j)
            {
                if (PLAYER_1 == 0)
                {
                    if (check_collision(plane->bullets2[i].x, plane->bullets2[i].y,
                                        plane->bullets2[i].width, plane->bullets2[i].height,
                                        game->enemies[j].x, game->enemies[j].y,
                                        game->enemies[j].width - 20, game->enemies[j].height))
                    {
                        al_destroy_bitmap(plane->bullets2[i].bullet);
                        plane->bullets2[i] = plane->bullets2[plane->num_bullets2 - 1];
                        plane->num_bullets2--;
                        game->enemies[j].destroy_enemy=game->enemies[j].destroy_enemy+2;
                        playersPtr[PLAYER_1].score += 20;
                        
                    }
                }
            }
        }
    }

    for (int i = 0; i < game->num_enemies; ++i)
    {

        if (game->enemies[i].destroy_enemy >= 1)
        {
            // Other destruction code for enemy resources

            // Remove destroyed enemy
            game->enemies[i] = game->enemies[game->num_enemies - 1];

            game->num_enemies--;
        }
    }
    if(playersPtr[PLAYER_1].score==100)
    {
        
        spawn_new_enemies( game);

    }
 
     if(playersPtr[PLAYER_1].score==200){
        spawn_new_enemies2( game);
    }

    if(playersPtr[PLAYER_1].score==320){
        spawn_new_enemies3( game);
    }

    if (game->num_enemies == 0)
    {
        printf("You WIN\n");
        cleanup(game);
        cleanup_enemies(game);
        cleanup_plane(plane);
    }

    if (plane->health <= 0)
    {   
        printf("You LOSE\n");
        cleanup(game);
        cleanup_enemies(game);
        cleanup_plane(plane);
    }
}

void spawn_new_enemies(game_data* game) {
    // 在這裡新增新的敵機
    for (int i = 0; i < NEW_ENEMY_COUNT; ++i) {
        // 確保敵機數量未超過敵機數組的大小
        if (game->num_enemies < 5) {
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
