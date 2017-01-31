#ifndef GetFeildPosition_H
#define GetFeildPosition_H

#include "../CommandBase.h"

class GetFeildPosition : public CommandBase {
public:
	GetFeildPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GetFeildPosition_H
