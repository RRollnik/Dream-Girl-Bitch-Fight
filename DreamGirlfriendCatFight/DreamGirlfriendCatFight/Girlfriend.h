#pragma once

class Girlfriend
{
public:
	Girlfriend();
	~Girlfriend();

	void ResetBuffs() { isBuffed = false; isDebuffed = false; }
	void setBuffed() { isBuffed = true; isDebuffed = false; }
	void setDebuffed() { isDebuffed = true; isBuffed = false; }
	int getHealth() { return Health; }

	void Status();

private:

	int Health;
	bool isBuffed;
	bool isDebuffed;

	int 
};

