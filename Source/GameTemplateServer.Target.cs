using UnrealBuildTool;
using System.Collections.Generic;

// Headless dedicated-server target used by Tools/Monitoring/justfile's `headless-sim`
// recipe and by Infra/global/Docker's production server image — built with
// -nullrhi at runtime, no rendering dependencies required.
public class GameTemplateServerTarget : TargetRules
{
	public GameTemplateServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

		ExtraModuleNames.Add("GameTemplate");
	}
}
