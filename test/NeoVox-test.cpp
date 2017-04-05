#include <gtest/gtest.h>
#include "../NeoVox.h"

TEST(neovox, dummy) {
    EXPECT_EQ("42",NeoVox::getAnswer());
}