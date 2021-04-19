
#include "PhysXShape.h"
#include "PhysXTerrain.h"
#include "../PhysXUtils.h"
#include "../PhysXWorld.h"
#include "renderer/pipeline/helper/SharedMemory.h"

namespace cc {
namespace physics {

PhysXTerrain::PhysXTerrain() : mTerrain(nullptr),
                               mRowScale(1.f),
                               mColScale(1.f),
                               mHeightScale(1.f),
                               PhysXShape(){};

void PhysXTerrain::setTerrain(uintptr_t handle, float rs, float cs, float hs) {
    if ((uintptr_t)mTerrain == handle) return;
    mTerrain = (PxHeightField *)handle;
    mRowScale = rs;
    mColScale = cs;
    mHeightScale = hs;
    if (mShape) {
        // TODO: ...
    }
}

void PhysXTerrain::onComponentSet() {
    if (mTerrain) {
        PxHeightFieldGeometry geom;
        geom.rowScale = mRowScale;
        geom.columnScale = mColScale;
        geom.heightScale = mHeightScale;
        geom.heightField = mTerrain;
        mShape = PxGetPhysics().createShape(geom, getDefaultMaterial(), true);
    }
}

void PhysXTerrain::updateScale() {
    // updateCenter(); needed?
}

void PhysXTerrain::updateCenter() {
    getShape().setLocalPose(PxTransform{mCenter, mRotation});
}

} // namespace physics
} // namespace cc
