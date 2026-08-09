# Infra/global/Helm/

Helm chart packaging the same dedicated-server resources as `Infra/global/K8s/Base/`, for teams that prefer `helm install` over `kubectl apply -k`. Pick one, don't run both against the same cluster/namespace.

```bash
helm lint Infra/global/Helm/Game-template
helm install game-template Infra/global/Helm/Game-template -f Infra/global/Helm/Game-template/values.yaml
helm upgrade game-template Infra/global/Helm/Game-template --set replicaCount=5
```

See `Infra/global/K8s/README.md` for the note on why a raw `Deployment` (what both this chart and the Kustomize base produce) is a development-only pattern for stateful dedicated-server pods — evaluate [Agones](https://agones.dev/) before a real production launch.
