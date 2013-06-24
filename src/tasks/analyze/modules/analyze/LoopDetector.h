/*
 * Filename		: LoopDetector.h
 * Author		: Kuba Sejdak
 * Created on	: 13-07-2012
 */

#ifndef LOOPDETECTOR_H_
#define LOOPDETECTOR_H_

#include <tasks/analyze/modules/analyze/IAnalyze.h>

class ExploitSample;

class LoopDetector: public IAnalyze {
public:
	LoopDetector();
    virtual ~LoopDetector() {}

	virtual bool perform(ExploitSampleHandle sample);
	virtual bool exportToDatabase(ExploitSampleHandle sample, int sampleId);
};

#endif /* LOOPDETECTOR_H_ */
