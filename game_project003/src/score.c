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

    for (int i = 0; i < plane->num_bullets; ++i)
    {
        for (int j = 0; j < game->num_enemies; ++j)
        {
            if(PLAYER_1 == 1){
                if (check_collision(plane->bullets[i].x, plane->bullets[i].y,
                                    plane->bullets[i].width, plane->bullets[i].height,
                                    game->enemies[j].x, game->enemies[j].y,
                                    game->enemies[j].width-20, game->enemies[j].height))
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

    for (int i = 0; i < game->num_enemies; ++i)
    {

        if (game->enemies[i].destroy_enemy >= 3)
        {
            // Other destruction code for enemy resources

            // Remove destroyed enemy
            game->enemies[i] = game->enemies[game->num_enemies - 1];

            game->num_enemies--;
        }
    }

    if (game->num_enemies == 0)
    {
        printf("You WIN\n");
        cleanup(game);
        cleanup_enemies(game);
        cleanup_plane(plane);
    }

    if (plane->health == 1)
    {   
        printf("You LOSE\n");
        cleanup(game);
        cleanup_enemies(game);
        cleanup_plane(plane);
    }
}
