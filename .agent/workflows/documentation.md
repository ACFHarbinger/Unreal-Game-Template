# Workflow: Documentation Updates

1. **Roadmap → changelog.** When an item completes, delete/move it out of `Moon/ROADMAP.md` and add a dated entry to `Docs/CHANGELOG.md` citing concrete artifacts changed.
2. **Architecture changes.** Update `Docs/ARCHITECTURE.md`'s module map/data-flow diagrams in the same PR as the code change that invalidated them.
3. **Significant decisions → ADR.** Use `Docs/Adr/0001-record-architecture-decisions.md`'s format: Status/Context/Decision/Consequences. Number sequentially, never edit an accepted ADR's decision — supersede it.
4. **New domain.** Add matching `.agent/rules/<domain>.md`, `.agent/workflows/<domain>.md`, and (if there's a repeatable task) `.agent/skills/<task>.md` together, not piecemeal.
5. **Consistency check.** Before finishing any documentation PR, grep for the changed fact across `Moon/`, `Docs/`, and `.agent/` to make sure no stale copy remains.
