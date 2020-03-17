
#ifndef MATHHELPER_H_
#define MATHHELPER_H_

#include "Define.h"

#include "Vec3.h"

using namespace std;

class Quaternion;

class MathHelper
{
public:
	static F32 degree2radians(F32 degree);
	static F32 radians2degree(F32 radians);
	static F32 distBtwPtSeg(const Vec3 &vPoint, const Vec3 &vSegPoint1, const Vec3 &vSegPoint2);		// 点到线段距离
	static F32 distBtwPtLine(const Vec3 &vPoint, const Vec3 &vSegPoint1, const Vec3 &vSegPoint2);	// 点到直线距离

	

	static void setBit(U8 &dest, const U8 index, const bool value);
public:
	static const F32 PI;
};

#endif /* MATHHELPER_H_ */
