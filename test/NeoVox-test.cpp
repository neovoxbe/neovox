#include <gtest/gtest.h>
#include "../NeoVox.h"

TEST(neovox, dummy) {
    EXPECT_EQ("42",NeoVox::getAnswer());
}

TEST(neovox, dummy2) {
    EXPECT_EQ(42,42);
}

TEST(neovox, dummy_fail) {
    EXPECT_EQ(42,43);
}