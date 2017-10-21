#include "Utility.h"

std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("mainlog"); // NOLINT

void init()
{
    std::ios::sync_with_stdio(false);
    logger->set_level(logLevel);
}

void msleep(int tempsMillisecondes)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(tempsMillisecondes));
}