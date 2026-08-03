# Unreal-Game-Template - Root Justfile
# Entry point. All recipes delegate to sub-modules via `mod`.
# Invoke sub-module recipes directly with double-colon notation: just build::editor
# Or use the root shorthands defined below.

set shell := ["bash", "-c"]
set unstable := true

red := '\033[0;31m'
green := '\033[0;32m'
yellow := '\033[0;33m'
blue := '\033[0;34m'
purple := '\033[0;35m'
cyan := '\033[0;36m'
bold := '\033[1m'
reset := '\033[0m'

# --- Default variables (can be overridden on the command line) ---

project_name := "GameTemplate"
config := "Development"          # Debug | DebugGame | Development | Shipping | Test
platform := "Linux"              # Linux | Win64 | Mac
test_filter := "GameTemplate"    # Automation test name/group filter
map := "TestMap"

# --- Submodules ---

mod build 'Tools/Build'
mod ci 'Tools/Ci'
mod helper 'Tools/Helper'
mod monitoring 'Tools/Monitoring'
mod test 'Tools/Test'
mod validation 'Tools/Validation'

# --- Default target ---

default: help

# --- Help ---

# Print available commands
help: helper::_print_header
    @echo -e "{{bold}}Setup{{reset}}"
    @echo "  just generate-project-files     Regenerate IDE project files (UnrealBuildTool -projectfiles)"
    @echo ""
    @echo -e "{{bold}}Build{{reset}}"
    @echo "  just build::editor                Build the Editor target (see Tools/Build/justfile)"
    @echo "  just build::game config=Shipping  Build a packaged-config game target"
    @echo "  just build::all                   Build Editor + Game + headless server targets"
    @echo ""
    @echo -e "{{bold}}Run{{reset}}"
    @echo "  just editor                      Open the project in the Unreal Editor"
    @echo "  just play map=TestMap            Launch a standalone PIE session on a given map"
    @echo ""
    @echo -e "{{bold}}Test / QA{{reset}}"
    @echo "  just test::automation              Run the Automation Testing suite headlessly"
    @echo "  just monitoring::headless-sim runs=1000    Run N headless simulations for telemetry"
    @echo ""
    @echo -e "{{bold}}Lint / Format{{reset}}"
    @echo "  just validation::cpp               clang-format --dry-run over Source/"
    @echo "  just validation::fix               clang-format -i over Source/"
    @echo ""
    @echo -e "{{bold}}Maintenance{{reset}}"
    @echo "  just clean                        Remove Binaries/, Intermediate/, Saved/, DerivedDataCache/"
    @echo ""
    @echo "Run 'just <module>::' with no recipe to list that module's recipes, e.g. 'just build::'"

# --- Shorthands ---

# Regenerate IDE project files from the .uproject
generate-project-files: helper::_print_header
    @echo -e "{{cyan}}Regenerating project files for {{project_name}}.uproject...{{reset}}"
    ./GenerateProjectFiles.sh || echo -e "{{yellow}}GenerateProjectFiles.sh not found — run from an Unreal Engine install with this project registered.{{reset}}"

# Open the project in the Unreal Editor
editor: helper::_print_header
    @echo -e "{{cyan}}Launching UnrealEditor for {{project_name}}...{{reset}}"
    UnrealEditor "{{project_name}}.uproject"

# Launch a standalone Play-In-Editor session on a given map
play map=map: helper::_print_header
    UnrealEditor "{{project_name}}.uproject" {{map}} -game -windowed -resx=1280 -resy=720

# Full local pre-PR gate: format check, lint, and automation tests
check: validation::cpp test::automation
    @echo -e "{{green}}✓ All local checks passed.{{reset}}"

# Remove all engine-regenerated build artifacts
clean: helper::_print_header
    @echo -e "{{yellow}}Removing Binaries/, Intermediate/, Saved/, DerivedDataCache/...{{reset}}"
    rm -rf Binaries Intermediate Saved DerivedDataCache
