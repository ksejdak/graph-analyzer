/*
 *  Filename	: AnalyzeTask.h
 *  Author		: Kuba Sejdak
 *  Created on	: 14-03-2013
 */

#ifndef ANALYZETASK_H
#define ANALYZETASK_H

#include <string>
#include <list>
#include <QDomElement>

#include <tasks/ITask.h>
#include <tasks/analyze/modules/ModulesManager.h>
#include <tasks/analyze/AnalysisSystem.h>
#include <tasks/analyze/EmulationSystem.h>

class ExploitSample;

class AnalyzeTask : public ITask {
public:
	AnalyzeTask();
	virtual ~AnalyzeTask() {}

private:
	void loadModules();
    virtual bool performTask();
	virtual void updateStatus();
	virtual bool readConfigXML(QDomElement taskNode);
	void addScheduledFile(std::string filename);

	int load(std::string filename);
	bool emulate(ExploitSampleHandle s);
	bool analyze(ExploitSampleHandle s);
	bool exportResults(ExploitSampleHandle s);

	EmulationSystem m_emulationSystem;
	AnalysisSystem m_analysisSystem;

	// task specific info
	bool m_duplicate;
	int m_scheduledFiles;
	int m_loadedFiles;
	int m_analyzedSamples;
	int m_detectedExploits;
	int m_allTaskFiles;

	Analyze::InputMap *m_inputMods;
	Analyze::AnalyzeMap *m_analyzeMods;
	Analyze::OutputMap *m_outputMods;
};

#endif /* ANALYZETASK_H */
