#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockService.h"
#include "ServiceProxy.h"

using ::testing::InitGoogleTest;
using ::testing::_;
using ::testing::Return;

using namespace turtle;

class TurtleTest {
public:
    void Walk(const std::string& path) {
        ServiceProxy::GetInstance()->Walk(path);
    }
};


TEST(ServiceTest, ServiceTest_1) {
    MockService mockService;
    ServiceProxy::SetMockObject(&mockService);

    EXPECT_CALL(mockService, Walk(_)).WillOnce(Return(true));

    TurtleTest t;
    t.Walk("forward");

    ServiceProxy::SetMockObject(nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
