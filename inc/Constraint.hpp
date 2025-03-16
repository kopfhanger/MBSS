//
// Created by kopfhanger on 25-2-3.
//

#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include "RigidBody.hpp"
#include <eigen3/Eigen/Dense>
#include <vector>

namespace mbss {

enum class ConstraintType {
    Revolute,
    Spherical,
    Prismatic,
    Fixed
};

class Constraint {
public:
    virtual ~Constraint() = default;
    virtual void apply(RigidBody& a, RigidBody& b, double dt) = 0;
    virtual ConstraintType type() const = 0;

    // 通用属性
    Eigen::Vector3d anchorPoint;
    std::string bodyAName;
    std::string bodyBName;

    std::vector<RigidBody*> connected_bodies;
    Eigen::MatrixXd jacobian; // Jacobian matrix
    Eigen::VectorXd constraint_values; // Constraint equations

    virtual void updateJacobian() = 0;
    virtual void applyConstraint() = 0;
};

class RevoluteJoint : public Constraint {
    Eigen::Vector3d axis;
public:
    void apply(RigidBody& a, RigidBody& b, double dt) override {
        // 1. 计算相对位置约束
        Eigen::Vector3d r_a = anchorPoint - a.position();
        Eigen::Vector3d r_b = anchorPoint - b.position();

        // 2. 应用旋转轴约束
        Eigen::Vector3d currentAxis = a.orientation().toRotationMatrix() * axis;
        // ...约束方程实现...
    }

    ConstraintType type() const override {
        return ConstraintType::Revolute;
    }
};

class ConstraintFactory {
public:
    static std::unique_ptr<Constraint> create(
        const JointConfig& config,
        const std::map<std::string, RigidBody>& bodies)
    {
        switch (resolveType(config.type)) {
        case ConstraintType::Revolute:
            return createRevolute(config, bodies);
        case ConstraintType::Spherical:
            return createSpherical(config, bodies);
        // ...其他类型...
        }
    }

private:
    static ConstraintType resolveType(const std::string& typeStr) {
        static const std::map<std::string, ConstraintType> typeMap = {
            {"revolute", ConstraintType::Revolute},
            {"spherical", ConstraintType::Spherical}
        };
        return typeMap.at(typeStr);
    }

    static std::unique_ptr<Constraint> createRevolute(
        const JointConfig& config,
        const std::map<std::string, RigidBody>& bodies)
    {
        auto joint = std::make_unique<RevoluteJoint>();
        joint->bodyAName = config.body_a;
        joint->bodyBName = config.body_b;
        joint->anchorPoint = config.anchor_point;
        joint->axis = config.axis.normalized();
        return joint;
    }
};

}  // namespace mbss

#endif //CONSTRAINT_HPP
