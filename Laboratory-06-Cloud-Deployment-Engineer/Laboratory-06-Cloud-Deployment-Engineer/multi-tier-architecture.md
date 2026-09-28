# Multi-Tier Architecture

## What is a Two-Tier Architecture?

A Two-Tier Architecture separates an application into two main parts that work together:

### 1. The Web/Application Tier
This tier is responsible for serving the user interface and handling HTTP requests. In this laboratory, the **Nextcloud** container acts as the Web/Application Tier. Users interact with Nextcloud through their web browser.

### 2. The Database Tier
This tier is responsible for storing persistent data such as user accounts, file metadata, and settings. In this laboratory, the **MariaDB** container acts as the Database Tier.

### Why Separate Them?

It is better to put the web server and the database in two separate containers because they have different responsibilities. Separating them makes the system more flexible, easier to scale, and easier to maintain. If one container has a problem, the other can still continue working. It also follows best practices in cloud and modern application design.
