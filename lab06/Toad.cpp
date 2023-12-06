#include "Toad.hpp"
#include "WanderingKnight.hpp"
#include "Dragon.hpp"

Toad::Toad(int x, int y) : NPC(ToadType, x, y) {}
Toad::Toad(std::istream &is) : NPC(ToadType, is) {}

void Toad::print()
{
    std::cout << *this;
}

void Toad::save(std::ostream &os)
{
    os << ToadType << std::endl;
    NPC::save(os);
}

bool Toad::visitToad(std::shared_ptr<Toad> other)
{
    fight_notify(other, true);
    return true;
}

bool Toad::visitDragon(std::shared_ptr<Dragon> other)
{
    fight_notify(other, true);
    return true;
}

bool Toad::visitWanderingKnight(std::shared_ptr<WanderingKnight> other)
{
    fight_notify(other, true);
    return true;
}

bool Toad::accept(std::shared_ptr<NPC> attacker){
    return attacker->visitToad(std::dynamic_pointer_cast<Toad>(shared_from_this()));
}

std::ostream &operator<<(std::ostream &os, Toad &toad)
{
    os << "Toad: " << *static_cast<NPC *>(&toad) << std::endl;
    return os;
}