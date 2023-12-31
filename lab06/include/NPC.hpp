#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>

// type for npcs
class NPC;
class Toad;
class Dragon;
class WanderingKnight;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    ToadType = 1,
    DragonType = 2,
    WanderingKnightType = 3
};

class IFightObserver{
    public:
        virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};


class NPC : public std::enable_shared_from_this<NPC>
{
    public:
        NpcType type;
    protected:
        int x{0};
        int y{0};
        std::vector<std::shared_ptr<IFightObserver>> observers;
    public:
        NPC(NpcType t, int _x, int _y);
        NPC(NpcType t, std::istream &is);

        void subscribe(std::shared_ptr<IFightObserver>observer );
        void fight_notify(const std::shared_ptr<NPC> defender,bool win);
        virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

        virtual void print() = 0;
        virtual bool accept(std::shared_ptr<NPC> attacker) = 0;

        virtual void save(std::ostream &os);

        friend std::ostream &operator<<(std::ostream &os, NPC &npc);
};