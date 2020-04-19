#include "User.h"

User::User(const char* username, const char* password)
{
	strcpy_s(this->username, strlen(username), username);
	strcpy_s(this->password, strlen(password), password);
}

User::~User()
{
	delete[] username;
	delete[] password;
}

bool User::operator==(const User& b)
{
	return strcmp(username, b.username) == 0 && strcmp(password, b.password) == 0;
}
