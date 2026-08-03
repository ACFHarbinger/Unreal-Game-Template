# Resources go here once a provider is configured in versions.tf.
#
# Typical shape for a dedicated-server fleet once you add a provider
# (illustrative only, not applied):
#
# resource "aws_ecr_repository" "gameserver" {
#   name = "${local.name_prefix}-server"
# }
#
# resource "aws_eks_cluster" "main" {
#   name     = "${local.name_prefix}-cluster"
#   role_arn = aws_iam_role.eks.arn
#   # ...
# }
#
# resource "aws_elasticache_cluster" "matchmaker" {
#   cluster_id      = "${local.name_prefix}-matchmaker"
#   engine          = "redis"
#   node_type       = "cache.t3.micro"
#   num_cache_nodes = 1
# }

locals {
  name_prefix = "${var.project_name}-${var.environment}"
}
