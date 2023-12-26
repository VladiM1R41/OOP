#include "Toad.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"

Dragon::Dragon(int x, int y) : NPC(DragonType, x, y) {
    move_distance = 10;
    kill_distance = 10;
}
Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {
    move_distance = 10;
    kill_distance = 10;
}

void Dragon::print()
{
    std::cout << *this;
}

bool Dragon::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type()  );
    std::shared_ptr<Dragon> defender = std::dynamic_pointer_cast<Dragon>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
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