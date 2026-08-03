# Workflow: Planning a Multi-Step Change

1. **Survey existing design context.** `Moon/ROADMAP.md`, the relevant `Moon/Roadmaps/*.md`, and `Docs/Adr/` — don't start from a blank slate if a decision already exists.
2. **State the plan.** Modules touched, files affected, test plan, documentation impact — before writing code, not after.
3. **Get confirmation on ambiguous architectural calls.** Use `.agent/prompts/architecture_analysis.md` if the plan crosses a critical boundary.
4. **Execute in reviewable increments.** Prefer several small, single-purpose diffs over one large mixed one.
5. **Update `Moon/ROADMAP.md`** with the plan if the work spans more than one session, so it survives context loss.
6. **Close the loop.** On completion, run `.agent/prompts/documentation_update.md`'s task list.
