#include <gtest/gtest.h>
#include "NPC.hpp"
#include "Toad.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"
#include "visitor.hpp"

std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(25, 15);
std::shared_ptr<NPC> wanderingKnight = std::make_shared<WanderingKnight>(20, 20);
std::shared_ptr<NPC> toad = std::make_shared<Toad>(100, 12);


std::shared_ptr<Visitor> dragon_visitor = std::make_shared<DragonVisitor>();
std::shared_ptr<Visitor> wanderingKnight_visitor = std::make_shared<WanderingKnightVisitor>();
std::shared_ptr<Visitor> toad_visitor = std::make_shared<ToadVisitor>();

TEST(VisitorTest, Dragon) {
    ASSERT_FALSE(dragon_visitor->visit(std::static_pointer_cast<Dragon>(dragon)));
    ASSERT_TRUE(dragon_visitor->visit(std::static_pointer_cast<WanderingKnight>(wanderingKnight)));
    ASSERT_FALSE(dragon_visitor->visit(std::static_pointer_cast<Toad>(toad)));
}

TEST(VisitorTest, WanderingKnight) {
    ASSERT_TRUE(wanderingKnight_visitor->visit(std::static_pointer_cast<Dragon>(dragon)));
    ASSERT_FALSE(wanderingKnight_visitor->visit(std::static_pointer_cast<WanderingKnight>(wanderingKnight)));
    ASSERT_FALSE(wanderingKnight_visitor->visit(std::static_pointer_cast<Toad>(toad)));
}

TEST(VisitorTest, Toad) {
    ASSERT_TRUE(toad_visitor->visit(std::static_pointer_cast<Dragon>(dragon)));
    ASSERT_TRUE(toad_visitor->visit(std::static_pointer_cast<WanderingKnight>(wanderingKnight)));
    ASSERT_TRUE(toad_visitor->visit(std::static_pointer_cast<Toad>(toad)));
}

TEST(AcceptTest, Dragon) {
    ASSERT_FALSE(dragon->accept(dragon));
    ASSERT_TRUE(wanderingKnight->accept(dragon));
    ASSERT_FALSE(toad->accept(dragon));    
}

TEST(AcceptTest, WanderingKnight) {
    ASSERT_TRUE(dragon->accept(wanderingKnight));
    ASSERT_FALSE(wanderingKnight->accept(wanderingKnight));
    ASSERT_FALSE(toad->accept(wanderingKnight));
}

TEST(AcceptTest, Toad) {
    ASSERT_TRUE(dragon->accept(toad));
    ASSERT_TRUE(wanderingKnight->accept(toad));
    ASSERT_TRUE(toad->accept(toad));
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}