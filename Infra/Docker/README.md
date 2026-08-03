# Infra/Docker/

Containerization for the **packaged, headless Linux dedicated-server build** (`GameTemplateServer`, built via `just build.server` or `just build::server`) — this is production hosting infrastructure, distinct from [`Docker/`](../../Docker/) at the repo root, which only holds dev-tooling images (docs preview, CI runner).

## Quick start

```bash
cp .env.example .env    # create at repo root if it doesn't exist yet — set SERVER_PORT etc.
just build.server config=Shipping platform=Linux
docker compose -f Infra/Docker/docker-compose.yml up --build
```

## Files

| File | Purpose |
| --- | --- |
| `Dockerfile` | Packages a pre-built `GameTemplateServer` Linux binary (see `entrypoint.sh`) into a minimal runtime image — it does **not** compile the engine inside the container; build the server binary first via `just build.server`. |
| `docker-compose.yml` | Local dev stack: dedicated server + a lightweight session/matchmaking-adjacent backend (Redis, standing in for a real matchmaker) |
| `docker-compose.prod.yml` | Production overrides (apply with `-f Infra/Docker/docker-compose.yml -f Infra/Docker/docker-compose.prod.yml`) |
| `entrypoint.sh` | Waits for dependencies (e.g., a matchmaking/session service) before exec'ing the server binary with the right `-log -unattended` flags |

## Notes

- Build context is the **repository root** — the Dockerfile copies the already-built `Linux/GameTemplateServer/` output from `just build.server`, it does not run UnrealBuildTool itself (that requires the licensed engine image from `Docker/Dockerfile.ci-runner`).
- `.dockerignore` at the repo root excludes `Binaries/`/`Intermediate/`/`Saved/` from the build context except the specific packaged server output this Dockerfile copies.
- Dedicated servers are typically **stateless per-match** — persistent state (player profiles, match history) belongs in an external service reached over the network, not baked into this image.
