//
// Created by kopfhanger on 25-2-2.
// 解析TOML配置文件，提取系统参数
//

#ifndef INPUT_HPP
#define INPUT_HPP


// #include <map>
#include <string>
#include <vector>
#include <eigen3/Eigen/Dense>
#include <toml.hpp>

namespace mbss {
    // 定义存储仿真配置的结构体
    struct SimulationConfig {
        double dt{};
        double total_time{};
        std::string integrator;
    };

    // 定义存储物体属性的结构体
    struct BodyConfig {
        std::string name;
        double mass{};
        Eigen::Matrix3d inertia;
        Eigen::Vector3d initial_position;
        Eigen::Vector3d initial_velocity;
    };

    // 定义存储运动副的结构体
    struct JointConfig {
        std::string type;
        std::string body_a;
        std::string body_b;
        Eigen::Vector3d anchor_point;
        Eigen::Vector3d axis;
    };

    // 输入模块类
    class InputManager {
    public:
        explicit InputManager(const std::string& config_file) {
            // 解析TOML配置文件
            const auto config = toml::parse(config_file);
            parseSimulationConfig(&config);
            parseBodiesConfig(&config);
            parseConstraintsConfig(&config);
        }
        // 获取仿真配置
        const SimulationConfig& getSimulationConfig() const { return simulation_config_; }

        // 获取物体配置
        const std::vector<BodyConfig>& getBodiesConfig() const { return bodies_config_; }

        // 获取约束配置
        const std::vector<JointConfig>& getConstraintsConfig() const { return constraints_config_; }

    private:
        SimulationConfig simulation_config_;
        std::vector<BodyConfig> bodies_config_;
        std::vector<JointConfig> constraints_config_;

        // 解析仿真配置
        void parseSimulationConfig(const auto& config) {
            simulation_config_.dt = config->at("simulation").at("dt").as_floating();
            simulation_config_.total_time = config->at("simulation").at("total_time").as_floating();
            simulation_config_.integrator = config->at("simulation").at("integrator").as_string();
        }
        // 解析物体配置
        void parseBodiesConfig(const auto& config) {
            for (const auto& bodies_table = config->at("bodies").as_table(); const auto& [name, body] : bodies_table) {
                BodyConfig body_config;
                body_config.name = name;
                body_config.mass = toml::find<double>(body, "mass");

                // 解析惯性矩阵
                auto inertia_vector = toml::find<std::vector<double>>(body, "inertia");
                body_config.inertia = Eigen::Map<Eigen::Matrix<double, 3, 3, Eigen::RowMajor>>(inertia_vector.data());

                // 解析初始位置
                auto position_vector = toml::find<std::vector<double>>(body, "initial_position");
                body_config.initial_position = Eigen::Map<Eigen::Vector3d>(position_vector.data());

                // 解析初始速度
                auto velocity_vector = toml::find<std::vector<double>>(body, "initial_velocity");
                body_config.initial_velocity = Eigen::Map<Eigen::Vector3d>(velocity_vector.data());

                bodies_config_.push_back(body_config);
            }
        }

        // 解析约束配置
        void parseConstraintsConfig(const auto& config) {
            try {
                for (const auto& constraints_table = config->at("constraints").as_table(); const auto& [joint_name, joint] : constraints_table) {
                    JointConfig joint_config;
                    joint_config.type = joint.at("type").as_string();
                    joint_config.body_a = joint.at("body_a").as_string();
                    joint_config.body_b = joint.at("body_b").as_string();

                    // 解析锚点
                    if (auto anchor_table = joint.at("anchor_point").as_array(); anchor_table.size() == 3) {
                        joint_config.anchor_point(0) = anchor_table[0].as_floating();
                        joint_config.anchor_point(1) = anchor_table[1].as_floating();
                        joint_config.anchor_point(2) = anchor_table[2].as_floating();
                    }

                    // 解析轴
                    if (auto axis_table = joint.at("axis").as_array(); axis_table.size() == 3) {
                        joint_config.axis(0) = axis_table[0].as_floating();
                        joint_config.axis(1) = axis_table[1].as_floating();
                        joint_config.axis(2) = axis_table[2].as_floating();
                    }

                    constraints_config_.push_back(joint_config);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error parsing constraints: " << e.what() << std::endl;
            }
        }
    };
}


#endif //INPUT_HPP
