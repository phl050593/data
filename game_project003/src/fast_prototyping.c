// #include "myheader.h"
// //這個不要看 是我在擬稿
// cleanup_plane(plane_data *plane);
// // 進入第二關
// initial_2_plane(plane);
// initial_2plane2_bullet(plane_data *plane, int index);
// draw_2plane2(plane);
// fire_2plane2_bullet(plane);
// movePlane_2(plane, &plane_ev.keyboard);
// cleanup_plane_2(plane_data *plane);

// int initial_2_plane(plane_data *plane)
// {
//     plane->health = 5;
//     plane->x = SCREEN_W / 2;
//     plane->y = SCREEN_H - PLANE_SIZE - 10;
//     plane->plane_img = al_load_bitmap("./plane.png");
//     plane->plane_timer = al_create_timer(1.0 / 60);
//     plane->event_plane_queue = al_create_event_queue();
//     plane->event_plane_bullet_queue = al_create_event_queue();
//     plane->plane_bullet_timer = al_create_timer(PLANE_BULLET_UPDATE_TIMER); // 請根據需要調整計時器間隔
//     al_register_event_source(plane->event_plane_queue, al_get_timer_event_source(plane->plane_timer));
//     al_register_event_source(plane->event_plane_queue, al_get_keyboard_event_source());
//     al_start_timer(plane->plane_timer);
//     al_register_event_source(plane->event_plane_bullet_queue, al_get_timer_event_source(plane->plane_bullet_timer));
//     al_start_timer(plane->plane_bullet_timer);

//     return 0;
// }

// void initial_2plane2_bullet(plane_data *plane, int index)
// {
//     plane->bullets[index].bullet = al_load_bitmap("./plane_bullet.png");
//     plane->bullets[index].x = plane->x + plane->width / 2;
//     plane->bullets[index].y = plane->y + plane->height;
//     plane->bullets[index].vy = -20.0;
//     plane->bullets[index].width = 40;
//     plane->bullets[index].height = 40;
// }

// void draw_2plane2(plane_data *plane)
// {
//     al_draw_bitmap(plane->plane_img, plane->x, plane->y, 0);

//     for (int j = 0; j < plane->num_bullets; ++j)
//     {
//         al_draw_scaled_bitmap(
//             plane->bullets[j].bullet,
//             0, 0,
//             al_get_bitmap_width(plane->bullets[j].bullet),
//             al_get_bitmap_height(plane->bullets[j].bullet),
//             plane->bullets[j].x,
//             plane->bullets[j].y,
//             plane->bullets[j].width,
//             plane->bullets[j].height,
//             0);
//     }
// }

// void fire_2plane2_bullet(plane_data *plane)
// {
//     ALLEGRO_EVENT ev;
//     al_wait_for_event(plane->event_plane_bullet_queue, &ev);

//     for (int j = 0; j < plane->num_bullets; ++j)
//     {
//         plane->bullets[j].y += plane->bullets[j].vy;

//         if (plane->bullets[j].y < 0)
//         {
//             al_destroy_bitmap(plane->bullets[j].bullet);
//             plane->bullets[j] = plane->bullets[plane->num_bullets - 1];
//             plane->num_bullets--;
//         }
//     }
//     if (ev.type == ALLEGRO_EVENT_TIMER && ev.timer.source == plane->plane_bullet_timer)
//     {
//         if (plane->num_bullets < MAX_PLANE_BULLETS)
//         {
//             initial_2plane2_bullet(plane, plane->num_bullets);
//             plane->num_bullets++;
//         }
//     }
// }

// void movePlane_2(plane_data *plane, const ALLEGRO_KEYBOARD_EVENT *kbEvent)
// {
//     if (kbEvent->keycode == ALLEGRO_KEY_LEFT && plane->x > PLANE_MIN)
//     {
//         plane->x -= PLANE_MOVE;
//     }
//     else if (kbEvent->keycode == ALLEGRO_KEY_RIGHT && plane->x < PLANE_MAX - PLANE_SIZE)
//     {
//         plane->x += PLANE_MOVE;
//     }
// }

// void cleanup_plane_2(plane_data *plane)
// {
//     al_destroy_bitmap(plane->plane_img);
//     al_destroy_display(plane->plane_display);
//     al_destroy_event_queue(plane->event_plane_queue);
//     al_destroy_timer(plane->plane_timer);
//     for (int j = 0; j < plane->num_bullets; ++j)
//     {
//         al_destroy_bitmap(plane->bullets[j].bullet);
//     }
//     al_destroy_timer(plane->plane_bullet_timer);
// }