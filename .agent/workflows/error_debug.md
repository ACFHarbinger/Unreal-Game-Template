# Workflow: Debugging

1. **Reproduce.** Headless with a fixed seed for physics/AI bugs (`just monitoring::headless-sim runs=1`); explicit repro steps otherwise.
2. **Visualize before reading logs.** Domain-specific debug draw (collision contact markers, Gameplay Debugger AI scores, Animation Blueprint debugger) usually narrows the search faster than a log dive.
3. **Identify the owning layer.** Trace the symptom back to the subsystem that actually produced the wrong state, not the one that merely displayed/propagated it.
4. **Fix the root cause.** Not the symptom. If the fix is "nudge a magic number," ask whether an underlying invariant (`.agent/rules/*.md`) is actually being violated.
5. **Add a regression test::** Per `.agent/rules/testing_qa.md`.
6. **Document if it reveals a documentation gap.** If the bug happened because a rule/workflow doc was wrong or missing, fix that doc in the same PR.
