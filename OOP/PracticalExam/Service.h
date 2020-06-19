#pragma once
#include "Repository.h"
#include "Observer.h"


class Service : public Observable
{
private:
	Repository& repo;

public:
	Service(Repository& repo) :repo{ repo }{}
};

