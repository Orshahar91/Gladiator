#pragma once
#include "Statics.h"



class Diamond : public Statics
{
public:

	using Statics::Statics;
	~Diamond();

	virtual void HandleCollision(Objects& obj) override;
	virtual void HandleCollision(Digger& digger) override;
	virtual void HandleCollision(Monsters& monster) override;
	virtual void HandleCollision(Diamond& diamond) override;
	virtual void HandleCollision(Stone& stone) override;
	virtual void HandleCollision(Gift& gift) override;
	virtual void HandleCollision(Wall& wall) override;

protected:

private:

};
