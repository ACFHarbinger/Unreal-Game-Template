# Plugins/

Empty by design. This is where first-party and third-party Unreal Engine plugins live, one subdirectory per plugin, each with its own `<PluginName>.uplugin` and `Source/` module(s) — mirroring the top-level project's own `Source/<Module>/<Module>.Build.cs` layout.

## Conventions

- One plugin = one subdirectory: `Plugins/<PluginName>/<PluginName>.uplugin`, `Plugins/<PluginName>/Source/<PluginName>/...`.
- Prefer a plugin over adding a new top-level `Source/` module when the code is: (a) genuinely reusable across projects, (b) has a clean, narrow public API surface, or (c) wraps a third-party SDK/library that shouldn't leak its dependencies into the main game module.
- Keep gameplay-critical logic that's specific to *this* game in `Source/GameTemplate/`, not in a plugin — plugins are for infrastructure/reusable systems, not primary gameplay.
- Third-party plugins (marketplace or vendored source) are **not** tracked by Dependabot (no ecosystem support for UE plugins) — update them manually and note the version bump in `Docs/CHANGELOG.md`.
- Plugin binary content (if any) follows the same Git LFS rules as `Content/` — see [`.gitattributes`](../.gitattributes).

## Example layout (once a plugin is added)

```
Plugins/
└── MyReusableSystem/
    ├── MyReusableSystem.uplugin
    ├── Resources/
    └── Source/
        └── MyReusableSystem/
            ├── MyReusableSystem.Build.cs
            ├── Public/
            └── Private/
```

See `~/Repositories/MARLGame`'s `Plugins/MARLPlugin/` for a real-world reference of this layout (a plugin wrapping a third-party ML inference library, kept out of the main game module for dependency isolation).
