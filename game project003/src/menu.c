#include "myheader.h"
void menu_call() {
    game_data game;
    plane_data plane;
    menu button;

    if (initializeButton(&button) != 0) {
        fprintf(stderr, "Initialization failed!\n");
        return;
    }

    while (1) {
        drawMenu(&button);

        ALLEGRO_EVENT ev;

        if (al_get_next_event(button.event_queue, &ev)) {
            handleInput(&ev, &button, &game);
           
            if(button.isPressed){
                cleanupMenu(&button);
                Gamebackground_call(&game,&plane);
                printf("Switching to game\n");
                cleanup(&game);
                cleanup_enemies(&game);
                cleanup_plane(&plane);
            }
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE || button.shouldExit) {
            button.shouldExit = true;
            printf("exit\n");
            break;
        }

        }
    }

}

int initializeButton(menu* button){

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

void cleanupMenu(menu* button) {
    al_destroy_bitmap(button->menuBackgroundImage);
    al_destroy_bitmap(button->startGameImage);
    al_destroy_bitmap(button->exitGameImage);
    al_destroy_display(button->display);
    al_destroy_event_queue(button->event_queue);
}


void drawMenu(menu* button) {
    al_clear_to_color(al_map_rgb(0, 0, 0));

    int img_w = al_get_bitmap_width(button->menuBackgroundImage);
    int img_h = al_get_bitmap_height(button->menuBackgroundImage);
    al_draw_scaled_bitmap(
        button->menuBackgroundImage, 0, 0, img_w, img_h, 0, 0, SCREEN_W, SCREEN_H, 0
    );
    int startWidth = al_get_bitmap_width(button->startGameImage);
    int startHeight = al_get_bitmap_height(button->startGameImage);
    
    float startX = (SCREEN_W - startWidth) / 2.0;
    float startY = (SCREEN_H - startHeight) / 2.0 - 50.0;  // 調整 Y 座標

    al_draw_bitmap(button->startGameImage, startX, startY, 0);

    // 繪製 exit 按鈕
    int exitWidth = al_get_bitmap_width(button->exitGameImage);
    int exitHeight = al_get_bitmap_height(button->exitGameImage);
    
    float exitX = (SCREEN_W - exitWidth) / 2.0;
    float exitY = (SCREEN_H - exitHeight) / 2.0 + 50.0;
    
    al_draw_bitmap(button->exitGameImage, exitX, exitY, 0);

    al_flip_display();
}