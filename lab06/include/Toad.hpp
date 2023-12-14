#pragma once
#include "NPC.hpp"
#include "Visitor.hpp"

class Toad : public NPC
{
    public:
        Toad(int x, int y);
        Toad(std::istream &is);
        void print() override;
        void save(std::ostream &os) override;
        bool accept(std::shared_ptr<NPC> attacker) override;

        friend std::ostream &operator<<(std::ostream &os, Toad &knight);
};