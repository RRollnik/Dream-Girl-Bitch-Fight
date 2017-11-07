#pragma once

class Girlfriend
{
public:
	Girlfriend();
	~Girlfriend();

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }

	void Status();

private:

	bool isBuffed;
	bool isDebuffed;

	int 
};

