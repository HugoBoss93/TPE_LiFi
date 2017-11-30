#ifndef TPE_LIFI_IMPLRECEPTEUR_H
#define TPE_LIFI_IMPLRECEPTEUR_H

#include "../Utility.h"

/// Interface logicielle de l'implémentation matérielle du récepteur (classe abstraite)
class ImplRecepteur
{
    public:
        bool lireEtat() { return implLectureEtat(); }

    private:
        virtual bool implLectureEtat() = 0;
};


#endif //TPE_LIFI_IMPLRECEPTEUR_H
