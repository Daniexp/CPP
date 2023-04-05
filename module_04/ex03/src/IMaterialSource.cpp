#include <IMaterialSource.hpp>

IMaterialSource::IMaterialSource()
{
//Const
}

IMaterialSource::IMaterialSource(const IMaterialSource& src)
{
//Copy Const
	*this = src;
}

IMaterialSource::~IMaterialSource()
{
//Dest
}

IMaterialSource& IMaterialSource::operator = (const IMaterialSource& src)
{
	return *this;
}
