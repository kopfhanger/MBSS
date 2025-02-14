//
// Created by kopfhanger on 25-2-3.
//

#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include "RigidBody.hpp"
#include <eigen3/Eigen/Dense>
#include <vector>

namespace mbss {

class Constraint {
public:
    std::vector<RigidBody*> connected_bodies;
    Eigen::MatrixXd jacobian; // Jacobian matrix
    Eigen::VectorXd constraint_values; // Constraint equations

    virtual void updateJacobian() = 0;
    virtual void applyConstraint() = 0;
};

}  // namespace mbss

#endif //CONSTRAINT_HPP
