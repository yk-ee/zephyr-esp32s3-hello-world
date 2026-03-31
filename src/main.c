#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/led_strip.h>
#include <zephyr/device.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(hello_world, LOG_LEVEL_INF);


static const struct device *const strip = DEVICE_DT_GET(DT_ALIAS(led_strip));


int main(void)
{
    LOG_INF("Hello World! %s", CONFIG_BOARD_TARGET);

    if (device_is_ready(strip)) {
        LOG_INF("Found LED strip device %s", strip->name);
    } else {
        LOG_ERR("LED strip device %s is not ready", strip->name);
        return 0;
    }
    struct led_rgb rgb = { .r = 255, .g = 255, .b = 255 };
    int rc = led_strip_update_rgb(strip, &rgb, 1);
    if (rc) {
        LOG_ERR("Couldn't update strip: %d", rc);
    }

    struct led_rgb led_colors[] = {
        { .r = 255, .g = 0, .b = 0 },
        { .r = 0, .g = 255, .b = 0 },
        { .r = 0, .g = 0, .b = 255 },
    };

    int color = 0;
    for (;;) {
        LOG_INF("Tick %d", k_uptime_get_32() / 1000);

        int rc = led_strip_update_rgb(strip, &led_colors[color], 1);
        if (rc) {
            LOG_ERR("Couldn't update strip: %d", rc);
        }
        color = (color + 1) % ARRAY_SIZE(led_colors);

        k_msleep(1000);
    }
    return 0;
}
