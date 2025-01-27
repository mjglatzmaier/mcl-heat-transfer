#include <functional>

#include "ExplicitFDM.hpp"
#include "Backend.hpp"

namespace mcl
{

    template <typename Backend>
    void ExplicitFDM<Backend>::initialize(SolverState &state)
    {
        std::cout << "Initializing Explicit FDM...\n";
        // Add initialization logic
    }

    template <typename Backend>
    void ExplicitFDM<Backend>::solve(SolverState &state, Backend &backend)
    {
        auto &criteria = state.convergenceCriteria;
        for (int i = 0; i < criteria.maxIterations; ++i)
        {
            step(state, backend, [&](SolverState &state)
            {
                if (i % 10 == 0) 
                {
                    std::cout << "Iteration " << i << ": Writing residual to disk.\n";
                } 
            });

            if (checkConvergence(state))
            {
                std::cout << "Convergence reached at iteration " << i << ".\n";
                criteria.hasConverged = true;
                break;
            }
        }

        if (!criteria.hasConverged)
        {
            std::cerr << "Warning: Maximum iterations reached without convergence.\n";
        }
    }

    template <typename Backend>
    void ExplicitFDM<Backend>::step(SolverState &state, Backend &backend, std::function<void(SolverState &)> callback)
    {
        std::cout << "Executing Explicit FDM step...\n";
        backend.executeKernel([]()
            { std::cout << "Backend kernel execution.\n"; });

        if (callback)
        {
            callback(state);
        }
    }

    template <typename Backend>
    void ExplicitFDM<Backend>::finalize(SolverState &state)
    {
        std::cout << "Finalizing Explicit FDM...\n";
        // Add cleanup logic
    }

    template <typename Backend>
    std::string ExplicitFDM<Backend>::name() const
    {
        return "Explicit Finite Difference Method";
    }

    template <typename Backend>
    bool ExplicitFDM<Backend>::checkConvergence(SolverState &state)
    {
        return state.convergenceCriteria.tolerance < 1e-5; // Dummy condition for now
    }

    // Example backend types
    using DummyBackend = mcl::Backend<DummyDevice>;
    template class ExplicitFDM<DummyBackend>;

    using CudaBackend = mcl::Backend<CudaDevice>;
    template class ExplicitFDM<CudaBackend>;

}
