#include <gtest/gtest.h>
#include "General/Grid.h"

class BasicTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

// Simple test to verify Google Test is working
TEST_F(BasicTest, SanityCheck) {
    EXPECT_TRUE(true);
    EXPECT_EQ(2 + 2, 4);
}

// Simple test using your project's Grid class
TEST_F(BasicTest, GridCreation) {
    const int width = 10;
    const int height = 10;
    Grid grid(width, height, Grid::GenType::NONE);
    
    EXPECT_EQ(grid.getWidth(), width);
    EXPECT_EQ(grid.getHeight(), height);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}