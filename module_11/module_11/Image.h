#pragma once
#include <string>
class Image
{
public:
	Image(std::string path);

	std::string path() const { return _path; }
private:
	std::string _path;

};
