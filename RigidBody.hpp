//
// Created by kopfhanger on 25-2-3.
//

#ifndef RIGIDBODY_HPP
#define RIGIDBODY_HPP

// #include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>


namespace mbss {

class RigidBody {
    public:
    std::string name;
    double mass;
    Eigen::Matrix3d inertia;  // 惯性张量
    Eigen::Vector3d position; // 世界坐标系位置
    Eigen::Quaterniond orientation;
    Eigen::Vector3d velocity;
    Eigen::Vector3d angularVelocity;

};

} // mbss

#endif //RIGIDBODY_HPP
