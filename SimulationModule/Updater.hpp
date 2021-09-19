// SimulationModule.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include "IState.hpp"

#include <functional>

// An updater object
class Updater {
public:
	using UpdaterFunction_t = std::function<void()>;
	using ValidatorFunction_t = std::function<bool(IState*)>;
//	static const ValidatorFunction_t defaultValidator = [](IState*) { return true; };

	// Immutable functor that acts a subUpdater to an updater object
	class SubUpdater {
	public:
		SubUpdater(UpdaterFunction_t updater) : m_function(updater) {}
		void Update() { return m_function(); }
	private:
		UpdaterFunction_t m_function;
	};

	// Immutable Functor that acts as a validator for an update to state
	class Validator {
	public:
		Validator(ValidatorFunction_t validator) : m_function(validator) {}
		bool Validate(IState* newState) { return m_function(newState); }
	private:
		ValidatorFunction_t m_function;
	};

	Updater() = default;
	~Updater() = default;

	template <class StateType>
	void Emplace(IState* state, Updater updater, Validator validator = [](IState*) { return true; });
};
