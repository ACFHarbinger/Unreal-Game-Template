# Docker/

Unreal Engine games generally aren't containerized for the game itself — the Editor and packaged builds are native installs. Docker is used here for two narrower, genuinely useful purposes:

1. **`Dockerfile.docs`** — a lightweight container to build/preview the MkDocs documentation site locally, without installing the Python doc toolchain on the host.
2. **`Dockerfile.ci-runner`** — the base image for the **self-hosted** GitHub Actions runner (`.github/workflows/ci.yml`) that has a licensed Unreal Engine install baked in.

For **dedicated game server** containerization (the packaged, headless Linux server target running in production), see [`Infra/global/Docker/`](../Infra/global/Docker/) instead — that's a separate concern from these dev-tooling images.

## A note on Unreal Engine + Docker licensing

Epic Games publishes official UE5 container images to a **private** GitHub Container Registry (`ghcr.io/epicgames/unreal-engine`) that requires your GitHub account to be linked to Epic's organization (same linkage used for engine source access). `Dockerfile.ci-runner` expects that image as its base and will fail to build for anyone without that linkage — this is expected and is Epic's licensing model, not a bug in this template. See [Epic's Linux container documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine/quick-start-guide-for-using-container-images-in-unreal-engine) before attempting to build it.

## Usage

```bash
# Docs preview (no Epic linkage required)
docker compose -f Docker/docker-compose.yml up docs

# CI runner image (requires Epic GitHub org linkage + `docker login ghcr.io`)
docker build -f Docker/Dockerfile.ci-runner -t game-template-ci-runner Docker/
```
