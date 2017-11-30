#include "Emetteur.h"

void Emetteur::envoyerMessage(const string &messagebase)
{
    logger->info("Début de l'envoi du message : {}", messagebase);
    repereTemporel = now();
    string message = messagebase + '\0'; // Octet 0 pour signaler la fin de la transmission
    auto messageLen = (int)(message.length());
    int iOctet = 0;

    while (iOctet < messageLen)
    {
        bool debutBloc = (iOctet == 0) || (param.SYSTEME_BLOCS && (iOctet % param.BLOC_LEN == 0));
        int octet = message[iOctet];

        if (debutBloc)
        {
            // Bit de start
            impl->changerEtat(false);
            msleep(repereTemporel, param.BIT_DELAI);
            logger->debug("Envoi du bit de start");
            impl->changerEtat(true);
            msleep(repereTemporel, param.BIT_DELAI);
        }

        logger->debug("Envoi du caractère {} ({})", (char)(octet), octet);
        for (int iPow = 7; iPow >= 0; --iPow)
        {
            /// Bit de poids iPow : exemple dans 64 (01000000), bit = 1 pour iPow = 6
            bool bit;
            bit = (bool)((octet >> iPow) & 1);

            impl->changerEtat(bit);
            msleep(repereTemporel, param.BIT_DELAI);
        }
        ++iOctet;
    }

    logger->info("Message envoyé : {}", messagebase);
}

