#include "TODO_PACKAGE_NAME/TODO_NODE_NAME_node.hpp"

TODO_NODE_NAME::TODO_NODE_NAME(const rclcpp::NodeOptions& options) : Node("TODO_NODE_NAME", options) {
    // Parameters
    float x = this->declare_parameter<float>("foo", -10.0);

    // Pub Sub
    this->sub = this->create_subscription<std_msgs::msg::String>("/str", std::bind(&TODO_NODE_NAME::sub_cb, this, _1));
    this->path_pub = this->create_publisher<std_msgs::msg::String>("/run_folder");

    // Log a sample log
    RCLCPP_INFO(this->get_logger(), "You passed %f", x);

    // Send a sample message
    std_msgs::msg::String msg{};
    msg.data = std::string{"Hello World!"};
    path_pub->publish(msg);
}

void TODO_NODE_NAME::sub_cb(const std_msgs::msg::String::SharedPtr msg) {
    // Echo message
    this->pub.publish(msg);
}
