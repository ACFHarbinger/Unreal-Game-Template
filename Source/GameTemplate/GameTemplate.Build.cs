using UnrealBuildTool;

public class GameTemplate : ModuleRules
{
	public GameTemplate(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"GameplayTasks"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
		});

		// Enable once UMG-based HUD/menu widgets land (Docs/Docs/Moon/Roadmaps/ui_ux.md):
		// PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Slate", "SlateCore" });

		// Enable once MetaSounds work lands (Docs/Docs/Moon/Roadmaps/animation_audio.md §3):
		// PublicDependencyModuleNames.AddRange(new string[] { "MetasoundEngine", "AudioMixer", "SignalProcessing" });

		// Enable once replication/networking work lands (Docs/Docs/Moon/Roadmaps/networking.md):
		// PublicDependencyModuleNames.AddRange(new string[] { "NetCore", "OnlineSubsystem" });
	}
}
