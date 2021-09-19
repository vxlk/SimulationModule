// SimulationModule.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <exception>

// Interface to a state object
class IState {
public:
	virtual void Emplace(IState) = 0;
};

template <class T>
struct state_id : std::false_type {
	static constexpr const char* id() { throw std::exception("Type ID not registered for this type"); return ""; }
};

template <>
struct state_id<void> : std::true_type {
	static constexpr const char* id() { return "Default State ID"; }
};
