#ifndef TPE_LIFI_IMPLEMETTEUR_H
#define TPE_LIFI_IMPLEMETTEUR_H

#include "../Utility.h"

/// Interface logicielle de l'implémentation matérielle de l'émetteur (classe abstraite)
class ImplEmetteur
{
    public:
        void changerEtat(bool etat) { implChangementEtat(etat); }

    private:
        virtual void implChangementEtat(bool etat) = 0;
};


#endif //TPE_LIFI_IMPLEMETTEUR_H
