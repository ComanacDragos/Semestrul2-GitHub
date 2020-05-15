#pragma once
#include "AbstractRepository.h"

class Action
{
protected:
	AbstractRepository* repository;

public:
	Action(AbstractRepository* repo):repository{repo}{}
	virtual void executeUndo() = 0;
	virtual void executeRedo() = 0;

	virtual ~Action(){}
};

class ActionAdd : public Action
{
private:
	TrenchCoat coat;

public:
	ActionAdd(AbstractRepository* repo, const TrenchCoat& coat) :Action{ repo }, coat{ coat }{}

	void executeUndo();
	void executeRedo();

	~ActionAdd() {}
};

class ActionDelete : public Action
{
private:
	TrenchCoat coat;

public:
	ActionDelete(AbstractRepository* repo, const TrenchCoat& coat) :Action{ repo }, coat{ coat }{}

	void executeUndo();
	void executeRedo();

	~ActionDelete() {}
};

class ActionUpdate : public Action
{
private:
	TrenchCoat oldCoat;
	TrenchCoat newCoat;

public:
	ActionUpdate(AbstractRepository* repo, const TrenchCoat& oldCoat, const TrenchCoat& newCoat) :Action{ repo }, oldCoat{ oldCoat }, newCoat{ newCoat }{}

	void executeUndo();
	void executeRedo();

	~ActionUpdate() {}
};
