#pragma once

#include "Engine/EngineTypes.h"

/**
 * Named aliases for this project's custom Object Channels.
 *
 * The channel *names* are registered in Config/DefaultEngine.ini under
 * [/Script/Engine.CollisionProfile] (+DefaultChannelResponses); the actual
 * per-actor Block/Overlap/Ignore responses are set explicitly in each
 * actor's C++ constructor rather than via named collision presets, per
 * Moon/Roadmaps/physics_collision.md §2.
 *
 * These two channels are placeholders illustrating the pattern — replace
 * with whatever your actual gameplay needs (see Moon/Roadmaps/physics_collision.md §2
 * for a starting response-matrix template).
 *
 * Do not renumber these once shipped — doing so silently breaks every
 * already-serialized Physics Asset that references them
 * (.agent/AGENTS.md §8.4).
 */
namespace GameTemplateCollision
{
	constexpr ECollisionChannel Interactable = ECC_GameTraceChannel1;
	constexpr ECollisionChannel Hazard = ECC_GameTraceChannel2;
}
