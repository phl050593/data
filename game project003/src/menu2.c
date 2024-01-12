#include "myheader.h"
void menu2_call() {
    menu2 button2; 
    menu button;
    game_data game;
    plane_data plane;
    ALLEGRO_EVENT ev;
    // ... 其他初始化邏輯
    if (initializeMenu2(&button2) != 0) {
        fprintf(stderr, "Initialization failed!\n");
        return;
    }
    if (al_get_next_event(button2.event_queue, &ev)) {
                handleInput2(&ev, &button2);
            }
    while (1) {
        if (button2.gamePaused) {
            drawMenu2(&button2);

            if (button2.Exitgame) {
                // 如果 Exitgame 為真，跳轉到 menu
                cleanupMenu2(&button2);
                cleanup(&game);
                menu_call();
                printf("Switching to the menu\n");
                break;
            }
            if (button2.continueButton){
                button2.gamePaused = false;
                printf("Continue button is pressed\n");
            }
        }
    }
}

int initializeMenu2(menu2 *button2) {
    if (!al_init() || !al_init_image_addon()) {
        fprintf(stderr, "Failed to initialize Allegro!\n");
        return -1;
    }

    button2->continueButton = al_load_bitmap("continue.bmp");

    if (!button2->continueButton) {
        fprintf(stderr, "Failed to load continue image!\n");
        return -1;
    }
    button2->continueX = (SCREEN_W - al_get_bitmap_width(button2->continueButton)) / 2.0;
    button2->continueY = (SCREEN_H - al_get_bitmap_height(button2->continueButton)) / 2.0 -50;

    button2->exit2Button = al_load_bitmap("exit2.bmp");

    if (!button2->exit2Button) {
        fprintf(stderr, "Failed to load exit2 image!\n");
        return -1;
    }

    button2->continueX = (SCREEN_W - al_get_bitmap_width(button2->exit2Button)) / 2.0;
    button2->continueY = (SCREEN_H - al_get_bitmap_height(button2->exit2Button)) / 2.0 +50;

    button2->event_queue = al_create_event_queue();

    if (!button2->event_queue) {
        fprintf(stderr, "Failed to create event queue!\n");
        return -1;
    }
    button2->gamePaused = false;
    al_install_mouse();
    al_install_keyboard();
    al_register_event_source(button2->event_queue, al_get_display_event_source(button2->display));
    al_register_event_source(button2->event_queue, al_get_mouse_event_source());
    al_register_event_source(button2->event_queue, al_get_keyboard_event_source());
    return 0;
}

void handleInput2(ALLEGRO_EVENT *ev, menu2 *button2){
    if (ev->type == ALLEGRO_EVENT_KEY_DOWN && ev->keyboard.keycode == ALLEGRO_KEY_TAB) {
        // 暫停遊戲並顯示菜單
        button2 ->gamePaused = true;
       if(button2->gamePaused){
           int continueWidth = al_get_bitmap_width(button2->continueButton);
           int continueHeight = al_get_bitmap_height(button2->continueButton);
           int exit2Width = al_get_bitmap_width(button2->exit2Button);
           int exit2Height = al_get_bitmap_height(button2->exit2Button);
         if (ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
             int mouseX = ev->mouse.x;
             int mouseY = ev->mouse.y;

             button2 ->isXInButtonRange_continue = (mouseX >= button2->continueX) && (mouseX <= button2->continueX + continueWidth);
             button2 ->isYInButtonRange_continue = (mouseY >= button2->continueY) && (mouseY <= button2->continueY + continueHeight);

             button2 -> isXInButtonRange_exit2 = (mouseX >= button2->exit2X) && (mouseX <= button2->exit2X + exit2Width);
             button2 -> isYInButtonRange_exit2 = (mouseY >= button2->exit2Y) && (mouseY <= button2->exit2Y + exit2Height);

            if (button2->isXInButtonRange_continue && button2->isYInButtonRange_continue) {
                button2->gameContinue = true;
                printf("button continue is pressed\n");
                
            }

            if (button2->isXInButtonRange_exit2 && button2->isYInButtonRange_exit2) {
                // Exit2 按鈕被按下，回到 menu
                button2->Exitgame = true;
                button2->gamePaused = false;
                printf("Exit2 button is pressed\n");
                printf("Exiting menu2. Returning to menu\n");
            }
       }
    }
 }
}

void cleanupMenu2(menu2 *button2){
    al_destroy_bitmap(button2->continueButton);
    al_destroy_bitmap(button2->exit2Button);
    al_destroy_display(button2->display);
    al_destroy_event_queue(button2->event_queue);
}

void drawMenu2(menu2 *button2){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    int continueWidth = al_get_bitmap_width(button2->continueButton);
    int continueHeight = al_get_bitmap_height(button2->continueButton);
    
    button2->continueX = (SCREEN_W - al_get_bitmap_width(button2->continueButton)) / 2.0;
    button2->continueY = (SCREEN_H - al_get_bitmap_height(button2->continueButton)) / 2.0 -50;
    float continueX = (SCREEN_W - continueWidth) / 2.0;
    float continueY = (SCREEN_H - continueHeight) / 2.0 - 50.0;
    al_draw_bitmap(button2->continueButton, continueX, continueY, 0);

    // 繪製 exit 按鈕
    int exit2Width = al_get_bitmap_width(button2->exit2Button);
    int exit2Height = al_get_bitmap_height(button2->exit2Button);
    
    button2->exit2X = (SCREEN_W - al_get_bitmap_width(button2->exit2Button)) / 2.0;
    button2->exit2Y = (SCREEN_H - al_get_bitmap_height(button2->exit2Button)) / 2.0 +50;
    float exit2X = (SCREEN_W - exit2Width) / 2.0;
    float exit2Y = (SCREEN_H - exit2Height) / 2.0 + 50.0;
    al_draw_bitmap(button2->exit2Button, exit2X, exit2Y, 0);
    al_draw_bitmap(button2->exit2Button, exit2X, exit2Y, 0);

    al_flip_display();
}