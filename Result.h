#pragma once

enum pos {GOOD, BAD, NONE};

class Result
{
public:
	Result(int goodPos = 0, int badPos = 0);
	Result(int result[2]);

	int getGoodPos() const;
	int getBadPos() const;

	void setGood(int goodPos);
	void setBad(int badPos);
	void setResult(int result[]);

private:
	int result[2];
};