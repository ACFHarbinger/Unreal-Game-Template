# Infra/global/Terraform/

Minimal Terraform skeleton for provisioning the cloud resources a dedicated-server fleet depends on (a container registry, a managed Kubernetes cluster, a session/matchmaking database). No provider is wired up yet — this is a starting point, not a real stack.

```bash
cd Infra/global/Terraform
terraform init
terraform plan -var-file=environments/dev.tfvars
terraform apply -var-file=environments/dev.tfvars
```

| File | Purpose |
| --- | --- |
| `versions.tf` | Required Terraform + provider versions, remote state backend (commented, fill in before first `init`) |
| `variables.tf` | Input variables |
| `main.tf` | Resources — currently empty, add your provider blocks and resources here |
| `outputs.tf` | Values to surface after `apply` (e.g. registry URL, cluster endpoint) |
| `environments/*.tfvars` | Per-environment variable values |

## What this will typically provision for a game-server fleet

- A container registry (for `Infra/global/Docker/`'s dedicated-server image).
- A managed Kubernetes cluster (target for `Infra/global/K8s/` / `Infra/global/Helm/`).
- A managed database/cache for session/matchmaking state (what `MATCHMAKER_HOST` in `Infra/global/Docker/entrypoint.sh` ultimately points at in production, replacing the local Redis standin).

> **TODO:** Pick a cloud provider, uncomment/configure the matching provider
> block in `versions.tf`, and replace the placeholder resources in `main.tf`.
