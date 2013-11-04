// Observer Header File
// By: Christopher Mukherjee

#pragma once
#include "Subject.h"

class Subject;

class Observer {
public:
	virtual ~Observer() {};
	virtual void update(Subject* o) = 0;

protected:
	Observer() {};
};