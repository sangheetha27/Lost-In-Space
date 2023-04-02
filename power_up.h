#ifndef POWER_UP
#define POWER_UP

#include "splashkit.h"
#include <vector>

using namespace std;

/**
 * Different options for the kind of power up.
 * Adjusts the image used.
 */
enum power_up
{
    FUEL,
    HEART,
    COIN,
    DROPS,
    STAR,
    CASH,
};

/**
 * The player data keeps track of all of the information related to the player.
 * 
 * @field   power_up_sprite   The power up's sprite - used to track position and movement
 * @field   kind              Current kind power up
 */
struct power_up_data
{
    sprite power_up_sprite;
    power_up kind;
};

/**
 * Creates a new power up in the centre of the screen with the random power up option.
 * 
 * @returns     The new power up data
 */
power_up_data new_power_up(double x, double y);

/**
 * Draws the power up to the screen. 
 * 
 * @param power_up_to_draw    The power up to draw to the screen
 */
void draw_power_up (const power_up_data &power_up_to_draw);

/**
 * Actions a step update of the power up 
 * 
 * @param power_up_to_update      The power up being updated
 */
void update_power_up (power_up_data &power_up_to_update);

#endif