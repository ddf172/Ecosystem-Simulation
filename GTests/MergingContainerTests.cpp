#include <gtest/gtest.h>
#include "Utilities/MergingContainer.h"
#include "Simulation/Resources/GrassResource.h"
#include "Simulation/Resources/MeatResource.h"

TEST(MergingContainerTest, MergingContainerCreation) {
    MergingContainer<std::shared_ptr<Resource>> container = MergingContainer<std::shared_ptr<Resource>>();
    EXPECT_EQ(container.getData()->size(), 0);
}

TEST(MergingContainerTest, MergingContainerAddOneTypeResource) {
    MergingContainer<std::shared_ptr<Resource>> container = MergingContainer<std::shared_ptr<Resource>>();
    container += std::make_shared<Resource>(GRASS, 50, 1);

    EXPECT_EQ(container.getData()->size(), 1);
    EXPECT_EQ(container[0]->getAmount(), 50);

    container[0]->setAmount(10);

    EXPECT_EQ(container.getData()->size(), 1);
    EXPECT_EQ(container[0]->getAmount(), 10);
    
    container += std::make_shared<Resource>(GRASS, 30, 1);

    EXPECT_EQ(container.getData()->size(), 1);
    EXPECT_EQ(container[0]->getAmount(), 40);
}

TEST(MergingContainerTest, MergingContainerAddDifferentTypeResources) {
    MergingContainer<std::shared_ptr<Resource>> container = MergingContainer<std::shared_ptr<Resource>>();
    container += std::make_shared<Resource>(GRASS, 10, 1);

    EXPECT_EQ(container[0]->getAmount(), 10);
    EXPECT_EQ(container.getData()->size(), 1);

    container += std::make_shared<MeatResource>(15, 1);

    EXPECT_EQ(container[0]->getAmount(), 10);
    EXPECT_EQ(container[1]->getAmount(), 15);
    EXPECT_EQ(container.getData()->size(), 2);

    container += std::make_shared<MeatResource>(30, 1);

    EXPECT_EQ(container[0]->getAmount(), 10);
    EXPECT_EQ(container[1]->getAmount(), 45);
    EXPECT_EQ(container.getData()->size(), 2);
}

TEST(MergingContainerTest, MergingContainerRemoveMeatResource) {
    MergingContainer<std::shared_ptr<Resource>> container = MergingContainer<std::shared_ptr<Resource>>();
    container += std::make_shared<MeatResource>(10, 1);

    EXPECT_EQ(container[0]->getAmount(), 10);
    EXPECT_EQ(container.getData()->size(), 1);

    container[0]->setAmount(0);

    EXPECT_EQ(container.getData()->size(), 0);
}
