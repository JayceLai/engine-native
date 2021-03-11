
#include "./World.h"
#include "../PhysicsSelector.h"

namespace cc {
namespace physics {

World::World() {
    _impl.reset(new WrappedWorld());
}

World::~World() {
    _impl.reset(nullptr);
}

void World::emitEvents() {
    _impl->emitEvents();
}

void World::step(float fixedTimeStep) {
    _impl->step(fixedTimeStep);
}

void World::setAllowSleep(bool v) {
    _impl->setAllowSleep(v);
}

void World::setGravity(float x, float y, float z) {
    _impl->setGravity(x, y, z);
}

void World::setDefaultMaterial(float f, float df, float r) {
    _impl->setDefaultMaterial(f, df, r);
}

void World::syncSceneToPhysics() {
    _impl->syncSceneToPhysics();
}

void World::syncSceneWithCheck() {
    _impl->syncSceneWithCheck();
}

void World::destroy() {
    _impl->destroy();
}

std::vector<TriggerEventPair> &World::getTriggerEventPairs() {
    return _impl->getTriggerEventPairs();
}

std::vector<ContactEventPair> &World::getContactEventPairs() {
    return _impl->getContactEventPairs();
}

void World::setCollisionMatrix(uint32_t i, uint32_t m) {
    _impl->setCollisionMatrix(i, m);
}

intptr_t World::createConvex(ConvexDesc &desc) {
    return (intptr_t)_impl->createConvex(desc);
}

intptr_t World::createTrimesh(TrimeshDesc &desc) {
    return (intptr_t)_impl->createTrimesh(desc);
}

} // namespace physics
} // namespace cc
