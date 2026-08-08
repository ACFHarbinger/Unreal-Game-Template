# Roadmap: QA & Testing

## 1. Headless Simulation Harness

A dedicated-server-target build running with `-nullrhi` to execute many accelerated, rendering-free runs and export structured telemetry (see `Tools/Monitoring/justfile`). Essential for catching AI-weight regressions and rare rules-engine edge cases that would take real-time hours to witness manually.

## 2. Adversarial Automated Testing

[Research] Automated "bad actor" QA bots that deliberately probe edge cases (boundary exploits, rules-engine corner cases) rather than playing optimally — evaluate third-party tooling vs. an in-house implementation once Phase 2 rules logic is stable enough to be worth stress-testing.
