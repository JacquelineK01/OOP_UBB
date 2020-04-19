#include "RepoException.h"

RepoException::RepoException(const char* message)
{
	strcpy_s(error, 18, "Repository error: ");
	strcpy_s(this->message, strlen(message), message);
	strcat_s(error, strlen(message), message);
}

const char* RepoException::what() const noexcept
{
	return error;
}
