/*
 * MathHelper.cpp
 *
 *  Created on: 2015年10月20日
 *      Author: root
 */

#include "MathHelper.h"
#include "Quaternion.h"

const F32 MathHelper::PI = 3.14159265;

F32 MathHelper::degree2radians(F32 degree)
{
	return degree * PI / 180.0f;
}

F32 MathHelper::radians2degree(F32 radians)
{
	return radians * 180.0f / PI;
}

F32 MathHelper::distBtwPtSeg(const Vec3 &vPoint, const Vec3 &vSegPoint1, const Vec3 &vSegPoint2)
{
	Vec3 vDir = vSegPoint2 - vSegPoint1;
	Vec3 vSeg1ToPoint = vPoint - vSegPoint1;

	F32 dot = vSeg1ToPoint.Dot(vDir);
	if (dot < floatEps)
	{
		return (vPoint - vSegPoint1).Length();
	}

	F32 dot2 = vDir.Dot(vDir);
	if (dot2 < dot)
	{
		return (vPoint - vSegPoint2).Length();
	}

	// 计算投影
	Vec3 insPoint = vSegPoint1 + (dot / dot2) * vDir;
	return (insPoint - vPoint).Length();
}

F32 MathHelper::distBtwPtLine(const Vec3 &vPoint, const Vec3 &vSegPoint1, const Vec3 &vSegPoint2)
{
	Vec3 vDir = vSegPoint2 - vSegPoint1;
	Vec3 vSeg1ToPoint = vPoint - vSegPoint1;

	F32 dot = vSeg1ToPoint.Dot(vDir);
	F32 dot2 = vDir.Dot(vDir);

	// 计算投影
	Vec3 insPoint = vSegPoint1 + (dot / dot2) * vDir;
	return (insPoint - vPoint).Length();
}

void MathHelper::setBit(U8 &dest, const U8 index, const bool value)
{
	if (value)
	{
		dest |= 1 << index;
	}
	else
	{
		dest &= ~(1 << index);
	}
}
