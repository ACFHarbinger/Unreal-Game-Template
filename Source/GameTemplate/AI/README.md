# Source/GameTemplate/AI/

Empty placeholder. Behavior Tree tasks/services/decorators and Utility AI consideration/action classes go here once real AI work starts — see `.agent/rules/ai_behavior.md`, `.agent/workflows/ai_behavior.md`, and `Docs/Docs/Moon/Roadmaps/ai.md`.

Suggested subfolder split once this grows past a handful of files (mirrors the pattern in `~/Repositories/Football-Referee`'s `Source/FootballReferee/AI/`):

```
AI/
├── BehaviorTree/   # UBTTaskNode/UBTService/UBTDecorator subclasses
├── Utility/        # Utility consideration/action scoring classes
└── Controllers/    # AAIController subclasses
```
