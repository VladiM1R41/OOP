#pragma once
#include "NPC.hpp"

struct Dragon : public NPC
{
    Dragon(int x, int y);
    Dragon(std::istream &is);

    void print() override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visitWanderingKnight(std::shared_ptr<WanderingKnight> other) override;

    void save(std::ostream &os) override;

    friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};