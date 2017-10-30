#include "Emetteur.h"

void Emetteur::envoyerBloc(const string &message, int iDebut, int iFin)
{
    impl->changerEtat(true); // 1 de synchronisation
    msleep(param.BIT_DELAI);

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
            msleep(param.BIT_DELAI);
        }
    }

    impl->changerEtat(false);
}

void Emetteur::envoyerMessage(const string &message)
{
    logger->info("Début de l'envoi du message : {}", message);
    auto messageLen = (int)(message.length());
    logger->debug("Envoi de l'en-tête (longueur du message : {})", messageLen);
    envoyerEnTete(message);

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
        }
    }
    else
    {
        envoyerBloc(message, 0, messageLen);
    }

    logger->info("Message envoyé : {}", message);
}

void Emetteur::envoyerEnTete(const string &message)
{
    // Structure de l'en-tête : longueur du message codé sur 4 octets (entier signé)
    auto messageLen = (int)(message.length());
    string enTete;
    auto byte = (char*)&messageLen;
    for (int iOctet = 0; iOctet < 4; ++iOctet) { enTete.push_back(byte[iOctet]); }
    envoyerBloc(enTete, 0, 4);
}

