#pragma once
#include "NPC.hpp"
#include "Toad.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"



class Visitor{
    public:
        virtual bool visit(const std::shared_ptr<Toad> other) = 0;
        virtual bool visit(const std::shared_ptr<Dragon> other) = 0;
        virtual bool visit(const std::shared_ptr<WanderingKnight> other) = 0;
};

class ToadVisitor: public Visitor{
    public:
        virtual bool visit(const std::shared_ptr<Toad> other) override {return true;}
        virtual bool visit(const std::shared_ptr<Dragon> other) override{return true;}
        virtual bool visit(const std::shared_ptr<WanderingKnight> other) override{return true;}
};

class DragonVisitor: public Visitor{
    public:
        virtual bool visit(const std::shared_ptr<Toad> other) override{return false;}
        virtual bool visit(const std::shared_ptr<Dragon> other) override{return false;}
        virtual bool visit(const std::shared_ptr<WanderingKnight> other) override{return true;}
};

class WanderingKnightVisitor: public Visitor{
    public:
        virtual bool visit(const std::shared_ptr<Toad> other) override{return false;}
        virtual bool visit(const std::shared_ptr<Dragon> other) override{return true;}
        virtual bool visit(const std::shared_ptr<WanderingKnight> other) override{return false;}
};

class VisitorFactory {
    public:
        static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
            std::shared_ptr<Visitor> result;
            switch (type) {
                case NpcType::ToadType:
                    result = static_pointer_cast<Visitor>(std::make_shared<ToadVisitor>());
                    break;

                case NpcType::DragonType:
                    result = static_pointer_cast<Visitor>(std::make_shared<DragonVisitor>());
                    break;

                case NpcType::WanderingKnightType:
                    result = static_pointer_cast<Visitor>(std::make_shared<WanderingKnightVisitor>());
                    break;
                default:
                    break;
            }
            return result;
        }
};