# Runtime image for the packaged GameTemplateServer Linux dedicated-server
# binary. This does NOT build the engine or run UnrealBuildTool — build the
# server binary first with `just build.server config=Shipping platform=Linux`
# (or `just build::server` from Tools/Build/justfile), which requires either
# a native Linux UE5 install or the licensed image in
# Docker/Dockerfile.ci-runner. This Dockerfile only packages that already-
# built output into a minimal, deployable runtime container.
#
# Build context is the repository ROOT (see docker-compose.yml:
#   build: { context: ../.., dockerfile: Infra/Docker/Dockerfile }).

FROM debian:bookworm-slim AS runtime

ENV DEBIAN_FRONTEND=noninteractive

# Minimal runtime dependencies for a packaged UE5 Linux dedicated server.
RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    libcurl4 \
    && rm -rf /var/lib/apt/lists/*

RUN useradd --create-home --uid 1000 gameserver
WORKDIR /srv/gametemplate

# Copy the packaged server build. Adjust the source path to match your
# actual `just build.package config=Shipping` / RunUAT archive output
# directory (see Tools/Build/justfile's `package` recipe).
COPY --chown=gameserver:gameserver Packaged/LinuxServer/ ./

COPY --chown=gameserver:gameserver Infra/Docker/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

USER gameserver
EXPOSE 7777/udp
EXPOSE 7777/tcp

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
