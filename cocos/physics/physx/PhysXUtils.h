
#pragma once

#include "base/Macros.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include <PhysX/PxPhysicsAPI.h>

#define PX_RELEASE(x) \
    if (x) {          \
        x->release(); \
        x = NULL;     \
    }

using namespace physx;
using namespace cc;

namespace cc {
namespace physics {

CC_INLINE bool operator!=(const PxVec3 &a, const Vec3 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z;
}

CC_INLINE bool operator!=(const Vec3 &a, const PxVec3 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z;
}

CC_INLINE bool operator==(const PxVec3 &a, const Vec3 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

CC_INLINE bool operator==(const Vec3 &a, const PxVec3 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

CC_INLINE PxVec3 operator*(const PxVec3 &a, const Vec3 &b) {
    return PxVec3{a.x * b.x, a.y * b.y, a.z * b.z};
}

CC_INLINE Vec3 operator*(const Vec3 &a, const PxVec3 &b) {
    return Vec3{a.x * b.x, a.y * b.y, a.z * b.z};
}

CC_INLINE PxVec3 &operator*=(PxVec3 &a, const Vec3 &b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

CC_INLINE Vec3 &operator*=(Vec3 &a, const PxVec3 &b) {
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

CC_INLINE bool operator!=(const PxQuat &a, const cc::Vec4 &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z || a.w == b.w;
}

CC_INLINE bool operator!=(const cc::Vec4 &a, const PxQuat &b) {
    return a.x != b.x || a.y == b.y || a.z == b.z || a.w == b.w;
}

CC_INLINE bool operator==(const PxQuat &a, const cc::Vec4 &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

CC_INLINE bool operator==(const cc::Vec4 &a, const PxQuat &b) {
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

template <typename T1, typename T2>
CC_INLINE void PxSetVec3Ext(T1 &v, const T2 &cv) {
    v = T1(cv.x, cv.y, cv.z);
}

template <typename T1, typename T2>
CC_INLINE void PxSetQuatExt(T1 &p, const T2 &cp) {
    p = T1(cp.x, cp.y, cp.z, cp.w);
}

template <typename T>
CC_INLINE T PxAbsMax(const T &a, const T &b) {
    return PxAbs(a) > PxAbs(b) ? a : b;
}

void PxSetFromTwoVectors(PxQuat &out, const PxVec3 &a, const PxVec3 &b);

} // namespace physics
} // namespace cc
