#include "ValidationException.h"

ValidationException::ValidationException(const char* message)
{
	strcpy_s(error, 18, "Repository error: ");
	strcpy_s(this->message, strlen(message), message);
	strcat_s(error, strlen(message), message);
}

const char* ValidationException::what() const noexcept
{
	return error;
}
