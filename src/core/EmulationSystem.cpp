/*
 *  Filename	: EmulationSystem.cpp
 *  Author		: Kuba Sejdak
 *  Created on	: 03-05-2012
 */

#include "EmulationSystem.h"

EmulationSystem::EmulationSystem() {
	loadModules();
}

EmulationSystem::~EmulationSystem() {
}

void EmulationSystem::loadSample(ShellcodeSample *sample) {
}

bool EmulationSystem::emulate() {
	return true;
}

void EmulationSystem::loadModules() {
	analyzeModules = ModuleManager::getInstance()->getAnalyze();
}
