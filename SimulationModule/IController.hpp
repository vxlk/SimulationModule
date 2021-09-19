// SimulationModule.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "Event.hpp"

#include <thread>

// Interface to a controller object
// Controller objects are responsible for accepting and 
// publishing or rejecting state changes
class IController {
public:
	enum class eSimulationType {
		Iterative,
		MonteCarlo,
		TimedIterative
	};

	virtual void StartSimulation(eSimulationType) = 0;
	virtual void StopSimulation() = 0;
};
