# Dev Container image for Unreal Engine C++ development tooling.
#
# NOTE: this image does NOT bundle the Unreal Engine itself — Epic
# distributes UE5 container images to a private registry that requires
# linking your GitHub account to Epic's organization (see
# Docker/README.md and Docker/Dockerfile.ci-runner). This devcontainer is
# for editing/formatting/linting C++ and running Tools/ CI scripts with a
# consistent toolchain across contributors' machines — actual
# UnrealBuildTool compilation still requires a real engine install
# (either a native host install, or the licensed ci-runner image).
#
# What this image DOES give you out of the box:
#   - clang / clang-format / clang-tidy for editing and formatting Source/
#   - CMake + Ninja (useful for any standalone tooling/tests outside UBT)
#   - .NET SDK, which UnrealBuildTool itself is built on (UBT is a C#
#     program invoked via dotnet on Linux)
#   - git + git-lfs, just, pre-commit, and Python (for Tools/Ci, Tools/Monitoring scripts)

FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    curl \
    git \
    git-lfs \
    build-essential \
    clang \
    clang-format \
    clang-tidy \
    lldb \
    cmake \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip \
    python3-venv \
    ca-certificates \
    gnupg \
    && rm -rf /var/lib/apt/lists/*

# .NET SDK — UnrealBuildTool (UBT) is a C# program invoked via `dotnet` on
# Linux; having the SDK available lets you run/debug UBT-adjacent tooling
# without a full engine install.
RUN curl -sSL https://dot.net/v1/dotnet-install.sh -o /tmp/dotnet-install.sh \
    && chmod +x /tmp/dotnet-install.sh \
    && /tmp/dotnet-install.sh --channel 8.0 --install-dir /usr/share/dotnet \
    && ln -s /usr/share/dotnet/dotnet /usr/bin/dotnet \
    && rm /tmp/dotnet-install.sh
ENV DOTNET_ROOT=/usr/share/dotnet

# just (task runner) + pre-commit
RUN curl --proto '=https' --tlsv1.2 -sSf https://github.com/casey/just/releases/latest/download/just-installer.sh | bash -s -- --to /usr/local/bin \
    && pip3 install --no-cache-dir --break-system-packages pre-commit ruff

RUN git lfs install --system

RUN useradd -m -s /bin/bash vscode
USER vscode
WORKDIR /workspace

CMD ["/bin/bash"]
