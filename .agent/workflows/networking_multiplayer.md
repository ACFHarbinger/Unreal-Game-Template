# Workflow: Networking Changes

1. **Confirm the module exists and is actually needed.** Don't build out `Source/GameTemplate/Network/` speculatively ahead of a validated single-player/local core loop — see `Moon/Roadmaps/networking.md`.
2. **Design authority first.** Decide what's server-authoritative vs. client-predicted before writing replication code.
3. **Minimize replication surface.** Only replicate what remote clients actually need to observe; use RepNotify sparingly and document each one's purpose.
4. **Validate determinism dependencies.** If this touches rollback/reconciliation, confirm the underlying state transitions are already deterministic (`.agent/rules/networking_multiplayer.md` §3) — fix that first if not.
5. **Test with simulated latency.** Use the Editor's network emulation settings (`p.netsim`) before declaring a networked feature done.
