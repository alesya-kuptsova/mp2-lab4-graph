#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
#include <gtest.h>
#endif

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
