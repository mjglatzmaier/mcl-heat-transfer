
#include <iostream>

#include "IAlgorithm.hpp"

namespace mcl {

    template <typename Backend>
    class ImplicitFDM : public IAlgorithm<Backend>
    {
    public:
        void initialize(SolverState &state) override;
        void solve(SolverState &state, Backend &backend) override;
        void step(SolverState &state, Backend &backend, std::function<void(SolverState &)> callback = nullptr) override;
        void finalize(SolverState &state) override;
        std::string name() const override;
    private:
        bool checkConvergence(SolverState &state);
    };

}