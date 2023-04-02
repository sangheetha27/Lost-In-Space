#include "splashkit.h"
#include "power_up.h"

/**
 * The power up bitmap function converts a power up kind into a 
 * bitmap that can be used.
 * 
 * Not exposed by the header.
 * 
 * @param kind  The kind of power up you want the bitmap of
 * @return      The bitmap matching this power up kind
 */

bitmap power_up_bitmap(power_up kind)
{
    switch (kind)
    {
    case FUEL:
        return bitmap_named("fuel");
    case HEART:
        return bitmap_named("heart");
    case COIN:
        return bitmap_named("coin");
    case DROPS:
        return bitmap_named("drops");
    case STAR:
        return bitmap_named("star");
    case CASH:
        return bitmap_named("cash");
    default: 
        return bitmap_named("coin");
    }
}

power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    power_up kind;

    // This outputs a random power up bitmap
    kind = static_cast<power_up>(rnd(6));
    result.power_up_sprite = create_sprite(power_up_bitmap(kind));

    // Position in the centre of the initial screen
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);

    // Gives a random velocity to the power up 
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);

    return result;
}

void draw_power_up (const power_up_data &power_up_to_draw)
{
    draw_sprite(power_up_to_draw.power_up_sprite);
}

void update_power_up (power_up_data &power_up_to_update)
{
    // Apply movement based the velocity in the sprite
    update_sprite(power_up_to_update.power_up_sprite);
}