#!/bin/bash
# Entrypoint for the packaged GameTemplateServer dedicated-server image.
# Waits for an optional matchmaking/session backend to be reachable (if
# configured via MATCHMAKER_HOST), then execs the server binary.

set -euo pipefail

if [ -n "${MATCHMAKER_HOST:-}" ]; then
    echo "Waiting for matchmaking backend at ${MATCHMAKER_HOST}:${MATCHMAKER_PORT:-6379}..."
    until (echo > "/dev/tcp/${MATCHMAKER_HOST}/${MATCHMAKER_PORT:-6379}") >/dev/null 2>&1; do
        sleep 1
    done
    echo "Matchmaking backend reachable."
fi

exec ./GameTemplateServer.sh \
    -log \
    -unattended \
    -nopause \
    -port="${SERVER_PORT:-7777}" \
    "$@"
