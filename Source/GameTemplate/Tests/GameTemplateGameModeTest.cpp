#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// Placeholder pure-logic unit test (no World/PIE required) — replace with
// real coverage as gameplay logic is added. See .agent/rules/testing_qa.md:
// this is intentionally the "deterministic unit test" category, not a
// statistical/simulation one.
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGameTemplateSanityTest, "GameTemplate.Core.Sanity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FGameTemplateSanityTest::RunTest(const FString& Parameters)
{
	// Trivial placeholder assertion so the test target has at least one
	// passing test from the first commit. Replace with real coverage as
	// Source/GameTemplate/Core, Physics, and AI logic land — see
	// Moon/ROADMAP.md Phase 0/1.
	TestTrue(TEXT("Template sanity check"), true);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
