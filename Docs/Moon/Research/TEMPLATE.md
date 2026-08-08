# Research Template

This template provides a standardized format for research notes, feasibility studies, and spike investigations conducted within this project repository.

## Executive Summary

A one-paragraph high-level overview of the research findings, outcomes, and final recommendations. This should capture the "why" and "what" of the research in a way that is easily digestible for stakeholders.

---

## 1. Context & Motivation

Explain the circumstances that initiated this research. What problem or opportunity was identified? Include references to previous discussions, issue numbers, or architectural decisions.

## 2. Research Objectives

Clear, measurable goals for this research spike:
- [ ] Goal 1: Evaluate technical feasibility of Unreal Engine 5 feature X.
- [ ] Goal 2: Measure performance impact (frametime, GPU/CPU cost).
- [ ] Goal 3: Assess developer experience and C++ API cleanliness.

## 3. Options Evaluated

### 3.1. Option A: [Option Title]
- **Pros:** List of advantages.
- **Cons:** List of drawbacks.
- **Complexity/Effort:** S / M / L / XL.
- **Key Findings:** Specific behavior observed during the spike.

### 3.2. Option B: [Option Title]
- **Pros:** List of advantages.
- **Cons:** List of drawbacks.
- **Complexity/Effort:** S / M / L / XL.
- **Key Findings:** Specific behavior observed during the spike.

## 4. Benchmarks & Performance (If Applicable)

| Metrics | Option A | Option B | Target / Baseline |
| --- | --- | --- | --- |
| Frame Time (ms) | 8.3ms | 16.6ms | < 11.1ms (90 FPS) |
| VRAM Allocation (MB) | 450 | 800 | < 500 |
| Draw Calls | 1,200 | 2,500 | < 1,500 |

## 5. Recommendations

What is the proposed path forward based on this research? Specify action items and who needs to approve them:
1. **Decision:** Detailed recommendation.
2. **Next Steps:** Actionable tasks to be added to the backlog/roadmap.
3. **Risks/Mitigations:** What could go wrong if we follow this recommendation, and how do we prevent it?

## 6. References & Further Reading

- [Architectural Decision Records (ADRs)](../Adr/0001-record-architecture-decisions.md)
- [Unreal Engine Documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine)
