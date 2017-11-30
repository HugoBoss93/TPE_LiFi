#include "Utility.h"
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("mainlog"); // NOLINT

void init()
{
    std::ios::sync_with_stdio(false);
    logger->set_level(logLevel);
    sched_param* x = new sched_param();
    x->sched_priority = 99;
    sched_setscheduler(getpid(), SCHED_RR, x);
}

void msleep(std::chrono::time_point<std::chrono::steady_clock> &pointDepart, int tempsMillisecondes)
{
    pointDepart += std::chrono::milliseconds(tempsMillisecondes);
    std::this_thread::sleep_until(pointDepart);
}