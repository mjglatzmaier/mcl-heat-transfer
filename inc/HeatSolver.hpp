#pragma once

#include "ISolver.hpp"

namespace mcl
{

template <typename Algorithm, typename Backend>
class HeatSolver : public ISolver<Backend> {
public:
    HeatSolver() = default;

    void compute(Backend& backend, SolverState& state) override {
        std::cout << "Running heat solver with algorithm: " << Algorithm::name() << std::endl;

        // Execute algorithm-specific computation
        Algorithm::solve(state, backend);
    }

    std::string name() const override { return "Heat Solver"; }
    std::string description() const override { return "Solver for heat transfer problems."; }
};

    template <typename Backend>
    class HeatSolver : public mcl::ISolver<Backend>
    {
    public:
        HeatSolver() = default;
        std::string name() const override { return "Heat Solver"; }
        std::string description() const override { return "Solves heat transfer equations."; }

        void compute(mcl::Backend &backend, mcl::SolverState &state) override
        {
            std::cout << "Running heat solver with algorithm: " << Algorithm::name() << std::endl;

            // Execute algorithm-specific computation
            Algorithm::solve(state, backend);
        }
    };

}