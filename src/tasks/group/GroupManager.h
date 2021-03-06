/*
 * Filename		: GroupManager.h
 * Author		: Kuba Sejdak
 * Created on	: 09-12-2012
 */

#ifndef GROUP_GROUPMANAGER_H_
#define GROUP_GROUPMANAGER_H_

#include <vector>

#include <core/ExploitSample.h>
#include <core/ExploitGroup.h>

typedef std::vector<ExploitGroupHandle> GroupsVector;

class GroupManager {
public:
	GroupManager() {}
	virtual ~GroupManager() {}

	int createGroup();
	void add(int groupId, ExploitSampleHandle sample, int resemblence);

	int find(ExploitSampleHandle sample);
	ExploitGroupHandle group(int groupId);
	ExploitSampleHandle leader(int groupId);

	int count();
	int count(int groupId);

private:
	GroupsVector m_groups;
};

#endif /* GROUP_GROUPMANAGER_H_ */
