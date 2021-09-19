// SimulationModule.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "IController.hpp"

#include <atomic>

// Example implementation of a controller object
class Controller : public IController {
public:
	virtual void StartSimulation(IController::eSimulationType) override;
	virtual void StopSimulation() override;
protected:
	std::atomic<bool> m_simRunning = false;
	std::thread m_simThread;
};
