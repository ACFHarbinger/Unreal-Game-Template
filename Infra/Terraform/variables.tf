variable "project_name" {
  description = "Short name used to prefix provisioned resources."
  type        = string
  default     = "gametemplate"
}

variable "environment" {
  description = "Deployment environment (dev, staging, prod)."
  type        = string
  default     = "dev"
}

variable "region" {
  description = "Cloud provider region to provision resources in."
  type        = string
  default     = "us-east-1"
}

variable "server_instance_count" {
  description = "Number of dedicated-server-capable nodes to provision for the cluster's game-server node pool."
  type        = number
  default     = 2
}
