#pragma once
#include "Subject.h"
using namespace std;

class Subject;

class Observer
{
public:
	virtual ~Observer() {};
	virtual void update(Subject* modsubject) = 0;

	Observer() {};
};