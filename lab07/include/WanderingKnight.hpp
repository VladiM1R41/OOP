#pragma once
#include "NPC.hpp"
#include "visitor.hpp"

class WanderingKnight final: public NPC
{
    public:
        WanderingKnight(int x, int y);
        WanderingKnight(std::istream &is);
        void print() override;
        void save(std::ostream &os) override;
        virtual bool accept(const std::shared_ptr<NPC>& attacker)const override;
        friend std::ostream &operator<<(std::ostream &os, WanderingKnight &knight);
};