#ifndef TPE_LIFI_SETTINGS_H
#define TPE_LIFI_SETTINGS_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <spdlog/spdlog.h>
using std::string;

const auto logLevel = spdlog::level::debug;
/// Logger général de l'application
extern std::shared_ptr<spdlog::logger> logger; // Initialisé dans Utility.cpp

/// Fait une pause de X millisecondes dans le programme
void msleep(int tempsMillisecondes);

/// Initialise les réglages du programme (à exécuter au début de main)
void init();

#endif //TPE_LIFI_SETTINGS_H
