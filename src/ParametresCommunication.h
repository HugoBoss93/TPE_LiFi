#ifndef TPE_LIFI_PARAMETRESCOMMUNICATION_H
#define TPE_LIFI_PARAMETRESCOMMUNICATION_H

/// Structure représentant les paramètres du protocole réseau
struct ParametresCommunication
{
    /// Message séparé en plusieurs blocs ou non
    bool SYSTEME_BLOCS = true;

    /// Longueur d'un bloc, en octets
    int BLOC_LEN = 1;

    /// Délai entre deux bits d'un même bloc (en ms)
    int BIT_DELAI = 5;

    /// Attente supplémentaire après le bit de start (en ms)
    int BIT_START_SUPPLEMENT = 1;
};

#endif //TPE_LIFI_PARAMETRESCOMMUNICATION_H
