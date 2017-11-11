#ifndef TPE_LIFI_PARAMETRESCOMMUNICATION_H
#define TPE_LIFI_PARAMETRESCOMMUNICATION_H

/// Structure représentant les paramètres du protocole réseau
struct ParametresCommunication
{
    /// Message séparé en plusieurs blocs ou non
    bool SYSTEME_BLOCS = true;

    /// Longueur d'un bloc, en octets
    int BLOC_LEN = 1;

    /// Délai entre deux blocs, en millisecondes
    int BLOC_DELAI = 30;

    /// Délai entre deux bits d'un même bloc
    int BIT_DELAI = 15;
};

#endif //TPE_LIFI_PARAMETRESCOMMUNICATION_H
