# Infra/global/K8s/

Kustomize-based Kubernetes manifests for running `GameTemplateServer` dedicated-server pods: a `base/` layer plus per-environment `overlays/`.

```bash
kubectl apply -k Infra/global/K8s/Overlays/Dev
kubectl apply -k Infra/global/K8s/Overlays/Prod
```

| Directory | Purpose |
| --- | --- |
| `base/` | Environment-agnostic Deployment/Service/ConfigMap/Ingress for the dedicated-server pod |
| `overlays/dev/` | Dev patches: 1 replica, `imagePullPolicy: Always`, dev host |
| `overlays/prod/` | Prod patches: replica count, resource limits, prod host |

## Dedicated-server-specific notes

Unlike a stateless web service, a UE dedicated-server pod holds **live match state** for the duration of a session — a naive `Deployment` rolling update will drop players mid-match. Two options once this matters:

1. **Simplest (current `base/deployment.yaml`)**: treat each pod as ephemeral/single-match, let a matchmaker allocate a fresh pod per match, and scale the `Deployment`'s replica count based on queue depth. Fine for early development.
2. **Production-grade**: adopt [Agones](https://agones.dev/) (a Kubernetes controller purpose-built for game server fleets — handles the allocate/health/graceful-shutdown lifecycle a raw `Deployment` doesn't). Not wired up in this template; evaluate once `Docs/Docs/Moon/Roadmaps/networking.md` §1's design spike concludes multiplayer is actually needed.

> **TODO:** Point the `image:` field in `base/deployment.yaml` at your real
> container registry once one exists (see `Infra/global/Docker/`). The Helm chart
> in `Infra/global/Helm/` packages the same base manifests for teams that prefer
> `helm install` over `kubectl apply -k`.
