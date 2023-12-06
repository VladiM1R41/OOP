#include "Toad.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

void Dragon::print()
{
    std::cout << *this;
}

bool Dragon::visitWanderingKnight(std::shared_ptr<WanderingKnight> other) 
{
    fight_notify(other, true);
    return true;
}

bool Dragon::accept(std::shared_ptr<NPC> attacker){
    return attacker->visitDragon(std::dynamic_pointer_cast<Dragon>(shared_from_this()));
}

void Dragon::save(std::ostream &os) 
{
    os << DragonType << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Dragon &dragon)
{
    os << "Dragon: " << *static_cast<NPC *>(&dragon) << std::endl;
    return os;
}