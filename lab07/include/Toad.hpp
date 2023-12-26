#pragma once
#include "NPC.hpp"
#include "Visitor.hpp"

class Toad final: public NPC
{
    public:
        Toad(int x, int y);
        Toad(std::istream &is);
        void print() override;
        void save(std::ostream &os) override;
        virtual bool accept(const std::shared_ptr<NPC>& attacker)const override;

        friend std::ostream &operator<<(std::ostream &os, Toad &knight);
};