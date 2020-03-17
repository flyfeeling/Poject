/*! \class Vec3
    \brief Vec3
 */

#include "Vec3.h"

const Vec3 ForwardVector = Vec3(0.0f, 0.0f, 1.0f);
const Vec3 UpVector = Vec3(0.0f, 1.0f, 0.0f);
const Vec3 ZeroVector = Vec3(0.0f, 0.0f, 0.0f);

const Vec3& Vec3::forward()
{
	return ForwardVector;
}

const Vec3& Vec3::up()
{
	return UpVector;
}

const Vec3& Vec3::zero()
{
	return ZeroVector;
}
