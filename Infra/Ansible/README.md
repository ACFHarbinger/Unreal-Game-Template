# Infra/Ansible/

Config-management/provisioning playbooks for bare-metal or VM targets that sit outside the Kubernetes/container world — e.g. a self-hosted GitHub Actions runner with a licensed Unreal Engine install (`Docker/Dockerfile.ci-runner`'s non-containerized equivalent), or a bare-metal dedicated-server box for a region without managed Kubernetes. Not needed if everything runs in containers/k8s — delete this directory in that case.

```bash
ansible-playbook -i inventory/hosts.ini playbook.yml
```

| Path | Purpose |
| --- | --- |
| `ansible.cfg` | Local Ansible config (inventory path, SSH settings) |
| `inventory/hosts.ini` | Target hosts, grouped (`ue5_runners`, `game_servers`) |
| `playbook.yml` | Entry-point playbook, applies the `dedicated_server` role |
| `roles/dedicated_server/` | Installs OS dependencies and deploys the `GameTemplateServer` Linux binary directly to a host (systemd-managed, no container) |
