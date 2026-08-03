# Workflow: Audio Changes

1. **Confirm the module exists.** `Source/GameTemplate/Audio/` is created on first real audio work — see `.agent/AGENTS.md` §3.
2. **Design the parameter surface first.** List the gameplay parameters the graph needs (intensity, pitch, distance, event triggers) before building the MetaSound graph.
3. **Wire from C++/Blueprint.** Set MetaSound inputs from the owning actor's gameplay state; don't duplicate gameplay logic inside the graph.
4. **Profile.** Any real-time analysis pipeline gets a profiling pass to confirm it isn't blocking the game thread.
5. **Test.** Where the audio system gates a gameplay outcome (e.g., a detected signal triggers a state change), cover the detection threshold with a unit test independent of actual audio hardware.
