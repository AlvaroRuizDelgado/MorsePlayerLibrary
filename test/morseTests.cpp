#include "gtest/gtest.h"
#include "../src/morse.hpp"

namespace {

class MorseTest : public ::testing::Test {
 protected:

  MorseTest() {
  }

  virtual ~MorseTest() {
  }

virtual void SetUp() {
}

virtual void TearDown() {    
}

};

};

TEST_F(MorseTest, charToMorse)
{
  Morse morse;
  EXPECT_EQ(0, morse.charToMorse('0'));
  EXPECT_EQ(42, morse.charToMorse('z'));
  EXPECT_EQ(43, morse.charToMorse(' '));
}

} // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}