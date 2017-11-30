#include "Recepteur.h"

string Recepteur::lireMessage()
{
    logger->info("En attente d'un message à recevoir...");
    repereTemporel = now();
    string message;
    int iOctet = 0;

    while (iOctet == 0 || message.back() != '\0')
    {
        int octet = 0;
        bool debutBloc = (iOctet == 0) || (param.SYSTEME_BLOCS && (iOctet % param.BLOC_LEN == 0));
        bool finBloc = (param.SYSTEME_BLOCS && ((iOctet + 1) % param.BLOC_LEN == 0));
        if (debutBloc)
        {
            // Attente du bit de start
            while (! impl->lireEtat())
            { std::this_thread::sleep_for(std::chrono::microseconds(100)); }
            repereTemporel = now(); // Resynchronisation
            logger->debug("Bit de start reçu");
            msleep(repereTemporel, param.BIT_DELAI + param.BIT_START_SUPPLEMENT);
            logger->debug("Attente terminée");
        }

        for (int iPow = 7; iPow >= 0; --iPow)
        {
            bool bit = impl->lireEtat();
            octet += (bit << iPow); // 2 puissance iPow
            msleep(repereTemporel, param.BIT_DELAI);
        }
        logger->debug("Caractère reçu : {} ({})", (char)(octet), octet);
        message.push_back((char)(octet));
        ++iOctet;
    }

    message.pop_back(); // Retrait du bit de fin
    logger->info("Message reçu : {}", message);
    return message;
}
