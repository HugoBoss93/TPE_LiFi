#ifndef TPE_LIFI_EMETTEUR_H
#define TPE_LIFI_EMETTEUR_H

#include "../Utility.h"
#include "ImplEmetteur.h"
#include "../ParametresCommunication.h"

typedef std::unique_ptr<ImplEmetteur> ImplEmetteurPtr;
// Classe gérant un émetteur matériel (interface logicielle à fournir), permettant d'envoyer du texte
class Emetteur
{
    public:
        explicit Emetteur(ImplEmetteurPtr &&_impl) : impl(std::move(_impl)) {};
        Emetteur(ImplEmetteurPtr &&_impl, ParametresCommunication &_param) :
            impl(std::move(_impl)), param(_param) {};
        void envoyerMessage(const string &message);

    private:
        void envoyerBloc(const string &message, int iDebut, int iFin);
        ImplEmetteurPtr &&impl;
        ParametresCommunication param;
};


#endif //TPE_LIFI_EMETTEUR_H
