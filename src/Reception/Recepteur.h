#ifndef TPE_LIFI_RECEPTEUR_H
#define TPE_LIFI_RECEPTEUR_H

#include "../Utility.h"
#include "ImplRecepteur.h"
#include "../ParametresCommunication.h"

typedef std::unique_ptr<ImplRecepteur> ImplRecepteurPtr;
// Classe gérant un émetteur matériel (interface logicielle à fournir), permettant d'envoyer du texte
class Recepteur
{
    public:
        explicit Recepteur(ImplRecepteurPtr &&_impl) : impl(std::move(_impl)) {};
        Recepteur(ImplRecepteurPtr &&_impl, ParametresCommunication &_param) :
                impl(std::move(_impl)), param(_param) {};
        string lireMessage();

    private:
        ImplRecepteurPtr &&impl;
        ParametresCommunication param;
        std::chrono::time_point<std::chrono::steady_clock> repereTemporel;
};


#endif //TPE_LIFI_RECEPTEUR_H
