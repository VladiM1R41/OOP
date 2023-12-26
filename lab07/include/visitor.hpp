#pragma once
#include "npc.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class ToadVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ToadType:
                result = true;
                break;

            case NpcType::DragonType:
                result = true;
                break;

            case NpcType::WanderingKnightType:
                result = true;
                break;
        }
        return result;
    }
};

class DragonVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ToadType:
                result = false;
                break;

            case NpcType::DragonType:
                result = false;
                break;

            case NpcType::WanderingKnightType:
                result = true;
                break;
        }
        return result;
    }
};

class WanderingKnightVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ToadType:
                result = false;
                break;

            case NpcType::DragonType:
                result = true;
                break;

            case NpcType::WanderingKnightType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::ToadType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<ToadVisitor>());
                break;

            case NpcType::DragonType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DragonVisitor>());
                break;

            case NpcType::WanderingKnightType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<WanderingKnightVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};