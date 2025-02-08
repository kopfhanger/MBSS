//
// Created by kopfhanger on 25-2-3.
//

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

// #include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>
#include "dualquat/dualquat_base.h"

using Eigen::Matrix3d;
using Eigen::Vector3d;

namespace mbss {

class RigidBody {
    public:
    std::string name;
    double mass; // 质量
    Matrix3d inertia;  // 惯性张量矩阵
    Eigen::Matrix<double, 8, 8> mass_matrix; // 质量矩阵
    Vector3d position; // 世界坐标系位置
    Eigen::Quaterniond orientation; // 世界座标系姿态
    dualquat::DualQuaterniond dualQuaternion; // 世界座标系双四元数位姿
    Vector3d velocity; // 速度
    Vector3d angularVelocity; // 角速度

    // 设定物体质量
    RigidBody(double mass, Matrix3d inertia, Vector3d position, Eigen::Quaterniond orientation, Vector3d velocity, Vector3d angularVelocity, std::string name) {
        this->mass = mass;
        this->inertia = inertia;
        this->position = position;
        this->orientation = orientation;
        this->velocity = velocity;
        this->angularVelocity = angularVelocity;
        this->name =name;
    }

};

} // mbss

#endif //RIGIDBODY_HPP
