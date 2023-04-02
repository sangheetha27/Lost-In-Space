#include "splashkit.h"
#include "player.h"
#include "power_up.h"

using namespace std;

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

/**
 * Draws the needed bitmap and texts in th heads up display.
 */

void hud (player_data player)
{
    double fuel_pct = 0.75;
    double heart_lvl = 0.5;
    draw_text("SCORE: ", COLOR_WHITE, 0, 0, option_to_screen());
    draw_text("LOCATION: " + point_to_string(center_point(player.player_sprite)), COLOR_WHITE, 0, 10, option_to_screen());
    draw_text("NUMBER OF COINS COLLECTED: ", COLOR_WHITE, 670, 25, option_to_screen());
    draw_text("FUEL GAUGE", COLOR_WHITE, 10, 25, option_to_screen());
    draw_text("HEART COLLECTED", COLOR_WHITE, 310, 25, option_to_screen());
    draw_text("DROPS COLLECTED", COLOR_WHITE, 510, 25, option_to_screen());
    draw_bitmap("blue", 500, 30, option_part_bmp(0, 0, (bitmap_width("blue") * 0.25), bitmap_height("blue"), option_to_screen()));
    draw_bitmap("empty", 0, 70, option_to_screen());
    draw_bitmap("red", 300, 30, option_part_bmp(0, 0, (bitmap_width("red") * heart_lvl), bitmap_height("red"), option_to_screen()));
    draw_rectangle(COLOR_BLUE, 900, 600, 100, 100, option_to_screen());
    draw_bitmap("full", 0, 30, option_part_bmp(0, 0, (bitmap_width("full") * fuel_pct), bitmap_height("full"), option_to_screen()));
}
/**
 * Entry point.
 * 
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Lost In Space", 1000, 700);
    load_resources();

    power_up_data power;
    player_data player;
    player = new_player();
    power = new_power_up(200, 200);

    while (not quit_requested())
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(player);

        // Perform movement and update the camera
        update_player(player);

        // Redraw everything
        clear_screen(COLOR_BLACK);

        // Calls the function
        hud(player);

     
        draw_power_up(power);
        update_power_up(power);

        
        draw_player(player);

        refresh_screen(60);
    }

    return 0;
}