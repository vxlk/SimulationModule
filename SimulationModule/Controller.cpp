#include "Controller.hpp"

void Controller::StartSimulation(IController::eSimulationType type) {
	type;
	auto simulationLoop = [this]() {
		m_simRunning.exchange(true);
		while (this->m_simRunning.load()) {
			std::this_thread::sleep_for(std::chrono::duration<long long, std::milli>(50));
		}
	};
	m_simThread = std::thread(simulationLoop);
}

void Controller::StopSimulation() {
	m_simRunning.exchange(false);
	m_simThread.join();
}
