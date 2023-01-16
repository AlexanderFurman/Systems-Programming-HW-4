//
// Created by Omer Meushar on 16/01/2023.
//

#ifndef HW3_CLION_WELL_H
#define HW3_CLION_WELL_H

#include "Card.h"

class Well : public Card{

public:
    static const int WELL_LOSE_HP = 10;

    explicit Well(const std::string& name);
    void applyEncounter(Player* curPlayer) const override;

    ~Well() override = default;
    Well(const Well&) = delete; ///???
    Well& operator=(const Well& other) = delete; ///???

private:

};


#endif //HW3_CLION_WELL_H
