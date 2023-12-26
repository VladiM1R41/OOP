#pragma once
#include "NPC.hpp"
#include "Visitor.hpp"

class Dragon final: public NPC
{
    public:
        Dragon(int x, int y);
        Dragon(std::istream &is);

        void print() override;
        virtual bool accept(const std::shared_ptr<NPC>& attacker)const override;

        void save(std::ostream &os) override;

        friend std::ostream &operator<<(std::ostream &os, Dragon &dragon);
};