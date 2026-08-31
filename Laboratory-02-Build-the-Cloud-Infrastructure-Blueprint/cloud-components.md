# Cloud Infrastructure Components

## 1. Compute Resources
- **Purpose:** Provides the processing power (CPU and memory) to run applications and services.
- **Importance in Cloud Computing:** Allows companies to run servers without buying physical hardware. They can scale up or down easily.
- **In KillerCoda:** The CPU cores and RAM that I checked using `lscpu` and `free -h` are examples of compute resources.

## 2. Storage Resources
- **Purpose:** Stores data, files, and system information permanently or temporarily.
- **Importance in Cloud Computing:** Data must be saved safely and accessed quickly. Cloud storage can grow as needed.
- **In KillerCoda:** The disk space shown by `df -h` and `lsblk` represents storage resources.

## 3. Networking Resources
- **Purpose:** Allows the server to communicate with other devices and the internet.
- **Importance in Cloud Computing:** Without networking, users cannot access the services running on the cloud.
- **In KillerCoda:** The IP address and network interfaces shown by `ip a` or `hostname -I` are networking resources.

## 4. Operating System
- **Purpose:** Manages the hardware and allows software to run.
- **Importance in Cloud Computing:** Most cloud servers run Linux because it is stable, secure, and free.
- **In KillerCoda:** The Ubuntu Linux system I am using is the operating system.
