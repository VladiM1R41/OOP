#pragma once

#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <random>
#include <fstream>
#include <set>
#include <math.h>
#include <shared_mutex>

// type for npcs
class NPC;
class Toad;
class Dragon;
class WanderingKnight;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    UnknownType,
    ToadType,
    DragonType,
    WanderingKnightType,
    Max
};

class Observer{
    public:
        virtual void on_fight(const std::shared_ptr<NPC> attacker,const std::shared_ptr<NPC> defender,bool win) = 0;
};


class NPC : public std::enable_shared_from_this<NPC>
{
    protected:
        std::mutex mtx;

        NpcType type;
        int x{0};
        int y{0};
        bool alive{true};
        int move_distance{0};
        int kill_distance{0};

        std::vector<std::shared_ptr<Observer>> observers;
    public:
        NPC(NpcType t, int _x, int _y);
        NPC(NpcType t, std::istream &is);

        NpcType get_type();

        void subscribe(const std::shared_ptr<Observer>& observer );
        void fight_notify(const std::shared_ptr<NPC> defender,bool win) const;
        virtual bool is_close(const std::shared_ptr<NPC> &other);

        virtual void print() = 0;
        virtual bool accept(const std::shared_ptr<NPC>& attacker) const = 0;

        virtual void save(std::ostream &os);

        friend std::ostream &operator<<(std::ostream &os, NPC &npc);

        std::pair<int, int> position();

        int get_move_distance();
        void move(int, int, int, int);

        bool is_alive();
        void must_die();

        int throw_dice() const noexcept;
};