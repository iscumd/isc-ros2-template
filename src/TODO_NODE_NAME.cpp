#include <cstdio>

#include "TODO_NODE_NAME/TODO_NODE_NAME_node.hpp"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor exec;
    rclcpp::NodeOptions options;
    auto node = std::make_shared<TODO_NODE_NAME>(options);
    exec.add_node(node);
    exec.spin();
    rclcpp::shutdown();
    return 0;
}
