# Rule: Error Handling & Debugging

**Scope:** All modules.

## Enforced

1. No swallowed failures — a `Cast<T>()` that can legitimately fail is checked, and the failure path is either handled or logged with `UE_LOG` at an appropriate verbosity, never silently ignored.
2. Reproduce before fixing. A fix proposed without an established repro (headless seed, explicit steps, or a failing test) is not acceptable for a non-trivial bug.
3. Root-cause, not symptom-patch. Identify which architectural layer actually owns the bug before changing code — a visible symptom in one subsystem is frequently rooted in a different layer.
4. Every non-trivial bugfix ships with a regression test that would have caught it.

## Rejected on sight

- A fix with no accompanying test and no explanation of why the root cause is now addressed.
- Broad `try/catch`-style suppression patterns (N/A in UE5's no-exceptions build, but the equivalent — swallowing a failed `Cast`/`TOptional` without logging — is equally rejected).

See `.agent/workflows/error_debug.md`.
