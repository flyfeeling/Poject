/*
 * Quaternion.cpp
 *
 *  Created on: 2015年8月26日
 *      Author: root
 */

#include "Quaternion.h"

Vec3 operator * (const Vec3 &vec, const Quaternion &q)
{
	const F32 vx = vec.X * 2.0f;
	const F32 vy = vec.Y * 2.0f;
	const F32 vz = vec.Z * 2.0f;
	const F32 w2 = q.W * q.W - 0.5f;
	const F32 dot2 = (q.X * vx + q.Y * vy + q.Z * vz);
	return Vec3(vx * w2 + (q.Y * vz - q.Z * vy) * q.W + q.X * dot2
					, vy * w2 + (q.Z * vx - q.X * vz) * q.W + q.Y * dot2
					, vz * w2 + (q.X * vy - q.Y * vx) * q.W + q.Z * dot2);
}

Vec3 operator * (const Quaternion &q, const Vec3 &vec)
{
	return vec * q;
}

Quaternion operator * (const Quaternion &q1, const Quaternion &q2)
{
	F32 w = q1.W * q2.W - q1.X * q2.X - q1.Y * q2.Y - q1.Z * q2.Z;
	F32 x = q1.Y * q2.Z - q1.Z * q2.Y + q1.W * q2.X + q2.W * q1.X;
	F32 y = q1.Z * q2.X - q1.X * q2.Z + q1.W * q2.Y + q2.W * q1.Y;
	F32 z = q1.X * q2.Y - q1.Y * q2.X + q1.W * q2.Z + q2.W * q1.Z;

	return Quaternion(x, y, z, w);
}

// orig
//void Quaternion::lookRotation(const Vec3 &dir, const Vec3 &up, Quaternion &result)
//{
//	const Vec3 f = dir.Normalized();
//	const Vec3 s = up.Cross(f).Normalized();
//	const Vec3 u = f.Cross(s);
//
//	F32 m00 = s.X;
//	F32 m01 = s.Y;
//	F32 m02 = s.Z;
//	F32 m10 = u.X;
//	F32 m11 = u.Y;
//	F32 m12 = u.Z;
//	F32 m20 = f.X;
//	F32 m21 = f.Y;
//	F32 m22 = f.Z;
//
//	F32 num8 = (m00 + m11) + m22;
//	if (num8 > 0.0f)
//	{
//		F32 num = sqrt(num8 + 1.0f);
//		result.W = num * 0.5f;
//		num = 0.5f / num;
//		result.X = (m12 - m21) * num;
//		result.Y = (m20 - m02) * num;
//		result.Z = (m01 - m10) * num;
//		return;
//	}
//
//	if ((m00 >= m11) && (m00 >= m22))
//	{
//		F32 num7 = sqrt(((1.0f + m00) - m11) - m22);
//		F32 num4 = 0.5f / num7;
//		result.X = 0.5f * num7;
//		result.Y = (m01 + m10) * num4;
//		result.Z = (m02 + m20) * num4;
//		result.W = (m12 - m21) * num4;
//		return;
//	}
//
//	if (m11 > m22)
//	{
//		F32 num6 = sqrt(((1.0f + m11) - m00) - m22);
//		F32 num3 = 0.5f / num6;
//		result.X = (m10 + m01) * num3;
//		result.Y = 0.5f * num6;
//		result.Z = (m21 + m12) * num3;
//		result.W = (m20 - m02) * num3;
//		return;
//	}
//
//	F32 num5 = sqrt(((1.0f + m22) - m00) - m11);
//	F32 num2 = 0.5f / num5;
//	result.X = (m20 + m02) * num2;
//	result.Y = (m21 + m12) * num2;
//	result.Z = 0.5f * num5;
//	result.W = (m01 - m10) * num2;
//	return;
//}

//void Quaternion::lookRotation(const Vec3 &dir, const Vec3 &up, Quaternion &result)
//{
//	const Vec3 zaxis = dir.Normalized();
//	Vec3 xaxis = up.Cross(zaxis).Normalized();
//	if (xaxis.SqrLength() < floatEps)
//		xaxis.X = 1.0f;		// 临时解决up跟dir重和的问题，这里假设up为Y轴朝上，待修改
//	const Vec3 yaxis = zaxis.Cross(xaxis);
//
//	F32 m[3][3] = {xaxis.X, yaxis.X, zaxis.X, xaxis.Y, yaxis.Y, zaxis.Y, xaxis.Z, yaxis.Z, zaxis.Z};
//
//	F32 fSqrt = 0.0f;
//	F32 scale = (m[0][0] + m[1][1]) + m[2][2];
//	if (scale > 0.0f)
//	{
//		fSqrt = sqrt(scale + 1.0f);
//		result.W = fSqrt * 0.5f;
//		fSqrt = 0.5f / fSqrt;
//		//result.X = (m12 - m21) * fSqrt;
//		result.X = (m[2][1] - m[1][2]) * fSqrt;
//		result.Y = (m[0][2] - m[2][0]) * fSqrt;
//		result.Z = (m[1][0] - m[0][1]) * fSqrt;
//	}
//	else
//	{
//		I32 s_iNext[3] = {1, 2, 0};
//		I32 i = 0;
//		if (m[1][1] > m[0][0])
//			i = 1;
//		if (m[2][2] > m[i][i])
//			i = 2;
//		I32 j = s_iNext[i];
//		I32 k = s_iNext[j];
//
//		fSqrt = sqrt(m[i][i] - m[j][j] - m[k][k] + 1.0f);
//		F32 *apkQuat[3] = {&result.X, &result.Y, &result.Z};
//		*apkQuat[i] = 0.5f * fSqrt;
//		fSqrt = 0.5f / fSqrt;
//		result.W = (m[k][j] - m[j][k]) * fSqrt;
//		*apkQuat[j] = (m[j][i] + m[i][j]) * fSqrt;
//		*apkQuat[k] = (m[k][i] + m[i][k]) * fSqrt;
//	}
//
//	result.normalize();
//	return;
//}
//
//void Quaternion::lookRotation(const Vec3 &dir, Quaternion &result)
//{
//	lookRotation(dir, Vec3::up(), result);
//}
