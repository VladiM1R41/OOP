#pragma once
#include "npc.hpp"
#include "Dragon.hpp"
#include "Toad.hpp"
#include "WanderingKnight.hpp"
#include "observer.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, int x, int y) {
        std::shared_ptr<NPC> result;
        if (type > NpcType::UnknownType && type < NpcType::Max) {

            switch (type) {
                case NpcType::ToadType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Toad>(x, y));
                    break;

                case NpcType::DragonType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Dragon>(x, y));
                    break;

                case NpcType::WanderingKnightType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<WanderingKnight>(x, y));
                    break;
                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type && type > NpcType::UnknownType && type < NpcType::Max) {
            switch (type) {
                case NpcType::ToadType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Toad>(is));
                    break;

                case NpcType::DragonType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Dragon>(is));
                    break;

                case NpcType::WanderingKnightType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<WanderingKnight>(is));
                    break;
                default:
                    break;
            }
        } else {
            std::string err = "unexpected NPC type: " + type;
            throw std::runtime_error(err);
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};



