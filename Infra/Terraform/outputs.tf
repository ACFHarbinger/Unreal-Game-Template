# Uncomment as the corresponding resources in main.tf are added.

# output "container_registry_url" {
#   description = "URL of the container registry the dedicated-server image is pushed to."
#   value       = aws_ecr_repository.gameserver.repository_url
# }

# output "cluster_endpoint" {
#   description = "Kubernetes API endpoint for the provisioned cluster."
#   value       = aws_eks_cluster.main.endpoint
# }

# output "matchmaker_endpoint" {
#   description = "Connection endpoint for the managed matchmaking/session cache."
#   value       = aws_elasticache_cluster.matchmaker.cache_nodes[0].address
# }
