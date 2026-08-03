# Skill: Build the Project

**When to use:** First-time setup, or after pulling changes that touch `Source/`.

## Steps

1. `git lfs install && git lfs pull` (safe no-op if no LFS content exists yet).
2. `just generate-project-files` to regenerate IDE project files from the `.uproject`.
3. `just build::editor` — fix any compiler errors before proceeding; hand-authored UE5 C++ without a compiler in the loop is a known risk (see `.agent/AGENTS.md` §8.1).
4. `just editor` to open the project and confirm it loads.
5. If `Config/DefaultEngine.ini` references a default map that doesn't exist yet, create an empty level and save it at the referenced path (see `Content/README.md`).
6. `just test::automation` to confirm the baseline Automation Tests pass.
