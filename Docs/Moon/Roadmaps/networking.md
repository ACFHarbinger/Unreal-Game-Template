# Roadmap: Networking

## 1. Design Spike

Before building any networking code: does this game need multiplayer, and if so, what kind (co-op, competitive, MMO-scale)? Different answers imply very different architectures (listen server vs. dedicated server vs. rollback netcode). Record the decision and rationale here — this is exactly the kind of decision that deserves a `Docs/Adr/` entry once made.

## 2. Rollback / Reconciliation

If the design needs client-side prediction with rollback, this depends on the determinism guarantees in `.agent/AGENTS.md` §8.3 already holding for the relevant state machines — validate that first (see `Moon/Roadmaps/gameplay.md` §2) before investing in netcode.

See `Infra/K8s/` and `Infra/Terraform/` for the dedicated-server hosting scaffolding this roadmap eventually deploys to.
