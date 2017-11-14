#ifndef TPE_LIFI_SETTINGS_H
#define TPE_LIFI_SETTINGS_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <spdlog/spdlog.h>
using std::string;

auto now = [](){ return std::chrono::steady_clock::now(); };

const auto logLevel = spdlog::level::debug;
/// Logger général de l'application
extern std::shared_ptr<spdlog::logger> logger; // Initialisé dans Utility.cpp

/// Incrémente de X millisecondes le time point de départ (référence), puis fait un sleep_until dessus
void msleep(std::chrono::time_point<std::chrono::steady_clock> &pointDepart, int tempsMillisecondes);

/// Initialise les réglages du programme (à exécuter au début de main)
void init();

#endif //TPE_LIFI_SETTINGS_H
