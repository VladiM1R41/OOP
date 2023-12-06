#pragma once
#include "NPC.hpp"

struct Toad : public NPC
{
    Toad(int x, int y);
    Toad(std::istream &is);
    void print() override;
    void save(std::ostream &os) override;
    bool accept(std::shared_ptr<NPC> attacker) override;
    bool visitToad(std::shared_ptr<Toad> other) override;
    bool visitDragon(std::shared_ptr<Dragon> other) override;
    bool visitWanderingKnight(std::shared_ptr<WanderingKnight> other) override;

    friend std::ostream &operator<<(std::ostream &os, Toad &knight);
};