#include <gtest/gtest.h>
#include "NPC.hpp"
#include "Toad.hpp"
#include "Dragon.hpp"
#include "WanderingKnight.hpp"

TEST(DefenseTest, ToadAttackKnight) {
    std::shared_ptr<NPC> toad = std::make_shared<Toad>(0, 5);
    std::shared_ptr<NPC> knight = std::make_shared<WanderingKnight>(2, 7);
    bool success = knight->accept(toad);
    ASSERT_TRUE(success);
}

TEST(DefenseTest, ToadAttackDragon) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 5);
    std::shared_ptr<NPC> toad = std::make_shared<Toad>(2, 7);
    bool success = dragon->accept(toad);
    ASSERT_TRUE(success);
}

TEST(DefenseTest, ToadAttackToad) {
    std::shared_ptr<NPC> toad1 = std::make_shared<Toad>(0, 5);
    std::shared_ptr<NPC> toad2 = std::make_shared<Toad>(2, 7);
    bool success = toad2->accept(toad1);
    ASSERT_TRUE(success);
}

TEST(DefenseTest, DragonAttackKnight) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 5);
    std::shared_ptr<NPC> knight = std::make_shared<WanderingKnight>(2, 7);
    bool success = knight->accept(dragon);
    ASSERT_TRUE(success);
}

TEST(DefenseTest, DragonAttackToad) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 5);
    std::shared_ptr<NPC> toad = std::make_shared<Toad>(2, 7);
    bool success = toad->accept(dragon);
    ASSERT_FALSE(success);
}

TEST(DefenseTest, DragonAttackDragon) {
    std::shared_ptr<NPC> dragon1 = std::make_shared<Dragon>(0, 5);
    std::shared_ptr<NPC> dragon2 = std::make_shared<Dragon>(2, 7);
    bool success = dragon2->accept(dragon1);
    ASSERT_FALSE(success);
}

TEST(DefenseTest, KnightAttackDragon) {
    std::shared_ptr<NPC> dragon = std::make_shared<Dragon>(0, 5);
    std::shared_ptr<NPC> knight = std::make_shared<WanderingKnight>(2, 7);
    bool success = dragon->accept(knight);
    ASSERT_TRUE(success);
}

TEST(DefenseTest, KnightAttackToad) {
    std::shared_ptr<NPC> toad = std::make_shared<Toad>(0, 5);
    std::shared_ptr<NPC> knight = std::make_shared<WanderingKnight>(2, 7);
    bool success = toad->accept(knight);
    ASSERT_FALSE(success);
}

TEST(DefenseTest, KnightAttackKnight) {
    std::shared_ptr<NPC> knight1 = std::make_shared<WanderingKnight>(0, 5);
    std::shared_ptr<NPC> knight2 = std::make_shared<WanderingKnight>(2, 7);
    bool success = knight2->accept(knight1);
    ASSERT_FALSE(success);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}