// SimulationModule.cpp : Defines the entry point for the application.
//

#include "SimulationModule.hpp"
#include "Controller.hpp"
int main()
{
	std::unique_ptr<IController> execController = std::make_unique<Controller>();
	execController->StartSimulation(IController::eSimulationType::Iterative);
	std::this_thread::sleep_for(std::chrono::duration<long long, std::milli>(500));
	execController->StopSimulation();
	return 0;
}
