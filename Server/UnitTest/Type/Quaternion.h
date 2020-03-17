/*
 * Quaternion.h
 *
 *  Created on: 2015年4月1日
 *      Author: zh
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "Define.h"
#include "Vec3.h"
#include "MathHelper.h"

class Quaternion
{
public:
	F32 X;
	F32 Y;
	F32 Z;
	F32 W;

	Quaternion(F32 x, F32 y, F32 z, F32 w) : X(x), Y(y), Z(z), W(w){}
	Quaternion() : X(0.0f), Y(0.0f), Z(0.0f), W(1.0f){}
	~Quaternion(){}

	void operator *= (const Quaternion& v)
	{
		F32 a, b, c, d;

		a = W * v.W - X * v.X -  Y * v.Y - Z * v.Z;
		b = W * v.X + X * v.W +  Z * v.Y - Y * v.Z;
		c = W * v.Y + Y * v.W +  X * v.Z - Z * v.X;
		d = W * v.Z + Z * v.W +  Y * v.X - X * v.Y;

		W = a;
		X = b;
		Y = c;
		Z = d;
	}

	void identity()
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
		W = 1.0f;
	}

	F32 getLengthSquared() const
	{
		return X * X + Y * Y + Z * Z + W * W;
	}

	F32 getLength() const
	{
		return ::sqrt(getLengthSquared());
	}

	F32 normalize()
	{
		F32 length = getLength();
		if (length > floatEps)
		{
			float recip = 1.0f / length;
			W *= recip;
			X *= recip;
			Y *= recip;
			Z *= recip;
		}

		return length;
	}

	void set(const F32 x, const F32 y, const F32 z, const F32 w)
	{
		X = x;
		Y = y;
		Z = z;
		W = w;
	}

	void setRotation(const Vec3& axis, F32 angle)
	{
		F32 sin, cos, half;
		half = angle * 0.5f;
		sin = ::sin(half);
		cos = ::cos(half);

		X = axis.X * sin;
		Y = axis.Y * sin;
		Z = axis.Z * sin;
		W = cos;
	}

	void lerp(const F32 t, const Quaternion& left, const Quaternion& right)
	{
		const F32	quatEpsilon = (F32(1.0e-8f));

		*this = left;

		F32 cosine = X * right.X + Y * right.Y + Z * right.Z + W * right.W;		//this is left.dot(right)

		F32 sign = 1.0f;
		if (cosine < 0)
		{
			cosine = -cosine;
			sign = -1.0f;
		}

		F32 Sin = 1.0f - cosine * cosine;

		if(Sin >= quatEpsilon * quatEpsilon)
		{
			Sin = ::sqrt(Sin);
			const F32 angle = ::atan2(Sin, cosine);
			const F32 i_sin_angle = 1.0f / Sin;

			F32 lower_weight = ::sin(angle * (1.0f - t)) * i_sin_angle;
			F32 upper_weight = ::sin(angle * t) * i_sin_angle * sign;

			W = (W * (lower_weight)) + (right.W * (upper_weight));
			X = (X * (lower_weight)) + (right.X * (upper_weight));
			Y = (Y * (lower_weight)) + (right.Y * (upper_weight));
			Z = (Z * (lower_weight)) + (right.Z * (upper_weight));
		}
	}

	void fromEuler(const Vec3 &euler)
	{
		F32 rX = MathHelper::degree2radians(euler.X);
		F32 rY = MathHelper::degree2radians(euler.Y);
		F32 rZ = MathHelper::degree2radians(euler.Z);

		F32 c1 = cos(rX * 0.5f);
		F32 s1 = sin(rX * 0.5f);
		F32 c2 = cos(rY * 0.5f);
		F32 s2 = sin(rY * 0.5f);
		F32 c3 = cos(rZ * 0.5f);
		F32 s3 = sin(rZ * 0.5f);

		Quaternion qX; qX.set(s1, 0, 0, c1);
		Quaternion qY; qY.set(0, s2, 0, c2);
		set(0, 0, s3, c3);

		// 旋转顺序，先Y后X再Z
		this->operator *=(qX);
		this->operator *=(qY);
	}

	void toEuler(Vec3 &euler)
	{
		F64 wz = (F64)W * (F64)Z;
		F64 wx = (F64)W * (F64)X;
		F64 wy = (F64)W * (F64)Y;
		F64 xy = (F64)X * (F64)Y;
		F64 yz = (F64)Z * (F64)Y;
		F64 zx = (F64)Z * (F64)X;
		F64 zz = (F64)Z * (F64)Z;
		F64 xx = (F64)X * (F64)X;
		F64 yy = (F64)Y * (F64)Y;

		euler.Z = atan2(2 * (wz+xy), (1 - 2 * (zz + xx)));
		euler.X = asin(2 * (wx - yz));
		euler.Y = atan2(2 * (wy + zx), (1 - 2 * (xx + yy)));

		euler.X = MathHelper::radians2degree(euler.X);
		euler.Y = MathHelper::radians2degree(euler.Y);
		euler.Z = MathHelper::radians2degree(euler.Z);
	}

	//static void lookRotation(const Vec3 &dir, const Vec3 &up, Quaternion &result);
	//static void lookRotation(const Vec3 &dir, Quaternion &result);
};

Vec3 operator * (const Vec3 &vec, const Quaternion &q);
Vec3 operator * (const Quaternion &q, const Vec3 &vec);
Quaternion operator * (const Quaternion &q1, const Quaternion &q2);

#endif /* QUATERNION_H_ */
