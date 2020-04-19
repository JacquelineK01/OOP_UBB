#pragma once
#include <string.h>
class User
{
private:
	char* username;
	char* password;
public:
	User(const char* username, const char* password);
	~User();
	bool operator==(const User& b);
};

