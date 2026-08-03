# Skill: Add a Behavior Tree Task

**When to use:** Adding a new `UBTTaskNode` for AI actors.

## Steps

1. Create `UMyNewTask : public UBTTaskNode` under `Source/GameTemplate/AI/` (or a subfolder if the AI module has grown one).
2. Implement `ExecuteTask` returning `EBTNodeResult::InProgress`/`Succeeded`/`Failed` explicitly — never leave a path with no return.
3. If the task needs per-tick work, override `TickTask` and call `FinishLatentTask` when done; don't busy-loop.
4. Expose designer-tunable parameters via `UPROPERTY(EditAnywhere, Category = "AI")` on the task node.
5. Add a Blackboard key dependency check in `GetInstanceMemorySize`/`InitializeMemory` if the task needs per-instance state.
6. Test: a pure-logic unit test for any scoring/decision helper the task calls; a functional test if the task's correctness depends on actual World state.
7. Document the new task in `Moon/Roadmaps/ai.md` if it represents a new tactical capability, not just plumbing.
