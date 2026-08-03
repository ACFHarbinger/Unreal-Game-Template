terraform {
  required_version = ">= 1.7"

  required_providers {
    # Uncomment and pin once a cloud provider is chosen:
    # aws = {
    #   source  = "hashicorp/aws"
    #   version = "~> 5.0"
    # }
    # google = {
    #   source  = "hashicorp/google"
    #   version = "~> 5.0"
    # }
  }

  # Remote state backend — configure before the first `terraform init`.
  # backend "s3" {
  #   bucket = "your-org-gametemplate-tfstate"
  #   key    = "Infra/Terraform.tfstate"
  #   region = "us-east-1"
  # }
}

# provider "aws" {
#   region = var.region
# }
