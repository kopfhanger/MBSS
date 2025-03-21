//
// Created by kopfhanger on 25-2-7.
//

#ifndef INPUT_TEST_HPP
#define INPUT_TEST_HPP

#include "../input.hpp"

namespace mbss {
    // 辅助函数，将Eigen::Vector3d转换为std::vector<double>（用于打印调试）
    inline std::vector<double> fromEigenVector3d(const Eigen::Vector3d& vec) {
        return {vec(0), vec(1), vec(2)};
    }

    // 辅助函数，将Eigen::Matrix3d转换为std::vector<double>（用于打印调试）
    inline std::vector<double> fromEigenMatrix3d(const Eigen::Matrix3d& mat) {
        auto vec = mat.asDiagonal().diagonal();
        return {vec(0), vec(1), vec(2)};
    }

    inline void test_input() {

        // 找到系统配置文件
        std::string system_file = InputManager::find_system_file();
        if (system_file.empty()) {
            std::cerr << "Failed to obtain a valid system.toml file path." << '\n';
        }

        // 示例：解析TOML文件
        const mbss::InputManager input_manager(system_file);

        // 打印仿真配置
        const auto&[dt, total_time, integrator] = input_manager.getSimulationConfig();
        std::cout << "Simulation Config:\n"
                  << "  dt: " << dt << "\n"
                  << "  total_time: " << total_time << "\n"
                  << "  integrator: " << integrator << "\n";

        // 打印物体配置
        for (const auto& bodies = input_manager.getBodiesConfig(); const auto&[name, mass, inertia, initial_position, initial_velocity] : bodies) {
            std::cout << "Body: " << name << "\n"
                      << "  mass: " << mass << "\n"
                      << "  inertia: ";
            for (const double val : fromEigenMatrix3d(inertia)) {
                std::cout << val << " ";
            }
            std::cout << "\n"
                      << "  initial_position: ";
            for (const double val : fromEigenVector3d(initial_position)) {
                std::cout << val << " ";
            }
            std::cout << "\n"
                      << "  initial_velocity: ";
            for (double val : fromEigenVector3d(initial_velocity)) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }

        // 打印约束配置
        for (const auto& constraints = input_manager.getConstraintsConfig(); const auto&[type, body_a, body_b, anchor_point, axis] : constraints) {
            std::cout << "Constraint:\n"
                      << "  type: " << type << "\n"
                      << "  body_a: " << body_a << "\n"
                      << "  body_b: " << body_b << "\n"
                      << "  anchor_point: ";
            for (const double val : fromEigenVector3d(anchor_point)) {
                std::cout << val << " ";
            }
            std::cout << "\n"
                      << "  axis: ";
            for (const double val : fromEigenVector3d(axis)) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }
}  // namespace mbss

#endif //INPUT_TEST_HPP
