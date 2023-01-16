//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_MANA_H
#define HW3_CLION_MANA_H

#include "Card.h"

class Mana : public Card {

public:
    static const int GAIN_HP = 10;

    explicit Mana(const std::string& name);
    void applyEncounter(Player* curPlayer) const override;


    ~Mana() override = default;
    Mana(const Mana&) = delete; ///???
    Mana& operator=(const Mana& other) = delete; ///???

private:

};


#endif //HW3_CLION_MANA_H
