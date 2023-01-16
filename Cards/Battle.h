//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_BATTLE_H
#define HW3_CLION_BATTLE_H

#include "Card.h"

class Battle : public Card {
public:
    void applyEncounter(Player *curPlayer) const override;
    //void applyWin(Player *curPlayer) const; //not virtual
    //void applyLoss(Player *curPlayer) const; //not virtual
    virtual void applyMonsterEffect(Player *curPlayer) const = 0;

    std::ostream& virtualPrintCard(std::ostream& os) const override;


    ~Battle() override = default;
    Battle(const Battle&) = delete; ///???
    Battle& operator=(const Battle& other) = delete; ///???

protected:
    Battle(const std::string& name, int force, int loot, int playerHPDamage);

private:
    int m_force;
    int m_loot;
    int m_playerHPDamage;

};



#endif //HW3_CLION_BATTLE_H
