//
// Created by kopfhanger on 25-2-3.
//

#ifndef CONSTRAINT_HPP
#define CONSTRAINT_HPP

#include <vector>
#include <eigen3/Eigen/Dense>

namespace mbss {

class Constraint {
public:
    std::vector<RigidBody*> connected_bodies;
    Eigen::MatrixXd jacobian; // Jacobian matrix
    Eigen::VectorXd constraint_values; // Constraint equations

    virtual void updateJacobian() = 0;
    virtual void applyConstraint() = 0;
};

} // mbss

#endif //CONSTRAINT_HPP
