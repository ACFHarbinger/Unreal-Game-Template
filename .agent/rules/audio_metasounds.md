# Rule: Audio (MetaSounds)

**Scope:** `Source/GameTemplate/Audio/` (introduce when audio work starts), MetaSounds graphs.

## Enforced

1. Gameplay-reactive audio parameters (intensity, pitch, spatial position) are driven by exposed MetaSound inputs, not hardcoded inside the graph — C++/Blueprint sets the parameter, the graph reacts.
2. Any audio-analysis pipeline (e.g., real-time signal detection) runs on a background/audio thread path appropriate for its cost — never block the game thread on FFT-class work.
3. Spatial audio components attach to the actor whose position should drive attenuation, not a proxy/parent actor, unless deliberately designed otherwise (and documented why).

## Rejected on sight

- A MetaSound graph with gameplay logic hardcoded as graph-internal constants that should be exposed inputs.
- Synchronous heavy audio-analysis work on the game thread.

See `.agent/workflows/audio_metasounds.md`.
