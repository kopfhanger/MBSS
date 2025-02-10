//
// Created by kopfhanger on 25-2-3.
//

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

// #include <iostream>
#include "dualquat/dualquat_base.h"
#include <eigen3/Eigen/Dense>
#include <string>
#include <utility>



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

    // 设定物体的初始值
    RigidBody(double _mass, Matrix3d _inertia, Vector3d _position, Eigen::Quaterniond _orientation, Vector3d _velocity, Vector3d _angularVelocity, std::string _name) :
    name(std::move(_name)),
    mass(_mass),
    inertia(std::move(_inertia)),
    position(std::move(_position)),
    orientation(std::move(_orientation)),
    velocity(std::move(_velocity)),
    angularVelocity(std::move(_angularVelocity)) {}

};

};  // namespace mbss

#endif //RIGIDBODY_HPP
