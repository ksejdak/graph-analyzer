/*
 * Filename	: AnalysisSystem.cpp
 * Author	: Kuba Sejdak
 * Created on	: 21-06-2012
 */

#include "AnalysisSystem.h"

AnalysisSystem::AnalysisSystem() {
	sample = NULL;
	loadModules();
}

AnalysisSystem::~AnalysisSystem() {
}

void AnalysisSystem::loadSample(ShellcodeSample *sample) {
	this->sample = sample;
}

bool AnalysisSystem::analyze() {
	if(!sample)
		return false;

	if(!sample->getInfo()->isShellcodePresent()) {
		sample = NULL;
		return true;
	}

	bool status;
	map<string, AbstractAnalyze *>::iterator it;
	for(it = analyzeModules->begin(); it != analyzeModules->end(); ++it) {
		status = (*it).second->perform(sample);
		if(!status)
			return false;
	}

	sample = NULL;
	return true;
}

void AnalysisSystem::loadModules() {
	analyzeModules = ModuleManager::getInstance()->getAnalyze();
}
