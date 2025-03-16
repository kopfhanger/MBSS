//
// Created by kopfhanger on 25-2-3.
//

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

// #include <iostream>
#include "dualquat/dualquat_base.h"
#include "input.hpp"
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/src/Geometry/Quaternion.h>
#include <string>



namespace mbss {
    using dualquat::DualQuaterniond;
    using Eigen::Matrix3d;
    using Eigen::Vector3d;

class RigidBody {
    private:
    std::string name;
    double mass; // 质量
    Matrix3d inertia;  // 惯性张量矩阵
    Eigen::Matrix<double, 8, 8> mass_matrix; // 质量矩阵
    Vector3d position; // 世界坐标系位置
    Eigen::Quaterniond orientation; // 世界座标系姿态
    dualquat::DualQuaterniond dualQuaternion; // 世界座标系双四元数位姿
    Vector3d velocity; // 速度
    Vector3d angularVelocity; // 角速度

    public:
        class Builder {
            std::string name = "unnamed";
            double mass = 1.0;
            Matrix3d inertia = Matrix3d::Identity();
            Vector3d position = Vector3d::Zero();
            Eigen::Quaterniond orientation = Eigen::Quaterniond::Identity();
            dualquat::DualQuaterniond dualQuaternion = dualquat::DualQuaterniond(orientation, orientation);
            Vector3d velocity = Vector3d::Zero();
            // ...其他参数默认值...
        public:
            Builder& setName(const std::string& _name) {
                name = _name;
                return *this;
            }
            Builder& setMass(double _mass) { /* 参数校验 */ return *this; }

            Builder& setInertia(Matrix3d _inertia) {return *this;}

            Builder& setPosition(Matrix3d _position) {return *this;}

            Builder& setOrientation(Eigen::Quaterniond _orientation) {return *this;}

            // Builder& setPosition(Eigen::Matrix3d _position) {return *this;}

            // Builder& setPosition(Eigen::Matrix3d _position) {return *this;}

            // ...其他set方法...



            RigidBody build() {
                return RigidBody(mass, inertia, position,
                            orientation, velocity,
                            angularVelocity, name);
            }
        };

        // 从配置直接构建的工厂方法
        static RigidBody fromConfig(const BodyConfig& config) {
            return Builder()
                .setName(config.name)
                .setMass(config.mass)
                .setInertia(config.inertia)
                .setPosition(config.initial_position)
                .setOrientation(config.initial_orientation)

                // ...其他参数...
                .build();
        }

    // // 设定物体的初始值
    // RigidBody(double _mass, Matrix3d _inertia, Vector3d _position, Eigen::Quaterniond _orientation, Vector3d _velocity, Vector3d _angularVelocity, std::string _name) :
    // name(std::move(_name)),
    // mass(_mass),
    // inertia(std::move(_inertia)),
    // position(std::move(_position)),
    // orientation(std::move(_orientation)),
    // velocity(std::move(_velocity)),
    // angularVelocity(std::move(_angularVelocity)) {}

};

};  // namespace mbss

#endif //RIGIDBODY_HPP
