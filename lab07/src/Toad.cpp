#include "Toad.hpp"
#include "WanderingKnight.hpp"
#include "Dragon.hpp"

Toad::Toad(int x, int y) : NPC(ToadType, x, y) {
    move_distance = 10;
    kill_distance = 5;
}
Toad::Toad(std::istream &is) : NPC(ToadType, is) {
    move_distance = 10;
    kill_distance = 5;
}

void Toad::print()
{
    std::cout << *this;
}

void Toad::save(std::ostream &os)
{
    os << ToadType << std::endl;
    NPC::save(os);
}

bool Toad::accept(const std::shared_ptr<NPC>& attacker) const{
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Toad> defender = std::dynamic_pointer_cast<Toad>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

std::ostream &operator<<(std::ostream &os, Toad &toad)
{
    os << "Toad: " << *static_cast<NPC *>(&toad) << std::endl;
    return os;
}