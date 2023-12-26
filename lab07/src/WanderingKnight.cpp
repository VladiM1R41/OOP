#include "Toad.hpp"
#include "WanderingKnight.hpp"
#include "Dragon.hpp"

WanderingKnight::WanderingKnight(int x, int y) : NPC(WanderingKnightType, x, y) {
    move_distance = 10;
    kill_distance = 10;
}
WanderingKnight::WanderingKnight(std::istream &is) : NPC(WanderingKnightType, is) {
    move_distance = 10;
    kill_distance = 10;
}

void WanderingKnight::print()
{
    std::cout << *this;
}

void WanderingKnight::save(std::ostream &os)
{
    os << WanderingKnightType << std::endl;
    NPC::save(os);
}

bool WanderingKnight::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<WanderingKnight> defender = std::dynamic_pointer_cast<WanderingKnight>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

std::ostream &operator<<(std::ostream &os, WanderingKnight &knight)
{
    os << "WanderingKnight: " << *static_cast<NPC *>(&knight) << std::endl;
    return os;
}