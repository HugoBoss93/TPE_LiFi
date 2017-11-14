#include "Emetteur.h"

void Emetteur::envoyerBloc(const string &message, int iDebut, int iFin)
{
    impl->changerEtat(true); // 1 de synchronisation
    msleep(repereTemporel, param.BIT_DELAI);

    for (int iOctet = iDebut; iOctet < iFin; ++iOctet)
    {
        char octet = message[iOctet];
        logger->debug("Envoi du caractère {} ({})", octet, (int)(octet));
        for (int iPow = 7; iPow >= 0; --iPow)
        {
            /// Bit (0 ou 1) d'exposant iPow dans l'octet (dans 01000000, currBit = 1 pour iPow = 6)
            bool bit;
            bit = (bool)((octet >> iPow) & 1);

            impl->changerEtat(bit);
            msleep(repereTemporel, param.BIT_DELAI);
        }
    }

    impl->changerEtat(false);
}

void Emetteur::envoyerMessage(const string &messagebase)
{
    logger->info("Début de l'envoi du message : {}", messagebase);
    repereTemporel = now();
    string message = messagebase + '\0'; // Octet 0 pour signaler la fin de la transmission
    auto messageLen = (int)(message.length());

    if (param.SYSTEME_BLOCS)
    {
        int nbBlocs = messageLen / param.BLOC_LEN; // Nombre de blocs du message
        if (messageLen % param.BLOC_LEN > 0) { ++nbBlocs; } // On rajoute un bloc pour les bits qui restent
        for (int iBloc = 0; iBloc < nbBlocs; ++iBloc)
        {
            int iDebut = iBloc * param.BLOC_LEN;
            int iFin = std::min(messageLen, (iBloc + 1) * param.BLOC_LEN);
            logger->debug("Envoi du bloc {}", iBloc);
            envoyerBloc(message, iDebut, iFin);
            if (iBloc + 1 != nbBlocs) { msleep(repereTemporel, param.BLOC_DELAI); }
        }
    }
    else
    {
        envoyerBloc(message, 0, messageLen);
    }

    logger->info("Message envoyé : {}", messagebase);
}

