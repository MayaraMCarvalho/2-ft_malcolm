# 🕵️ ft_malcolm (42 São Paulo)

Available in: [🇧🇷 Português](README.md)

![Static Badge](https://img.shields.io/badge/C-c?style=plastic&label=Language)

This project is an introduction to network security, focused on intercepting and analyzing ARP (Address Resolution Protocol) packets. The project consists of a network sniffer developed in C, capable of capturing and displaying ARP traffic in real-time, demonstrating the basis for attacks like Man-in-the-Middle (MITM).

---

## 📜 Table of Contents

* [Overview](#%EF%B8%8F-overview)
* [Features](#-features)
* [Tech Stack Used](#%EF%B8%8F-tech-stack-used)
* [Installation and Setup](#-installation-and-setup)
* [Usage](#-usage)
* [Author](#-author)

---

## 🕵️ Overview

**ft_malcolm** is a 42 project that simulates a network sniffer. The main objective is to understand how IP to MAC address resolution works at the link layer, as well as to practice:
* Real-time packet capture.
* Handling network structures (Ethernet and ARP Headers).
* Using raw sockets.
* Low-level network traffic analysis.

---

## ✨ Features

* Captures ARP packets on a specified network interface.
* Displays information such as source/destination IP, source/destination MAC, and operation type (request/reply).
* Filters irrelevant packets to focus only on ARP communication.
* Provides a formatted and readable output in the terminal.

---

## 🛠️ Tech Stack Used

* **C Language**: For low-level network manipulation.
* **`Raw Sockets`**: To capture packets directly from the link layer (L2).
* **Linux Networking**: Use of `<sys/socket.h>`, `<netinet/if_ether.h>`, `<arpa/inet.h>` libraries.
* **`Makefile`**: For compilation and test rule management.

---

## ⚠️ Legal Disclaimer

> Using ARP spoofing or sniffing without permission is a violation of security policies and may be illegal. It is crucial to use this tool only in controlled environments, such as a personal lab network (VMs), for educational or testing purposes.

> This tool was developed as part of the 42 São Paulo Advanced curriculum and is intended for educational purposes only. The author does not tolerate or encourage the use of this tool for malicious purposes.

---

## 🚀 Installation and Setup

1. Clone the repository:

``` bash
git clone https://github.com/MayaraMCarvalho/2-ft_malcolm/ ft_malcolm
cd ft_malcolm
```

2. Compile the project: The Makefile contains the rules for compiling the program.

```bash
make comp
```
> To compile with valgrind, use: make val
> To clean the binaries, use: make fclean

---

## 🔧 Usage
To test safely, use a completely isolated environment via VirtualBox's **Internal Network** between **two VMs**. This prevents sensitive data exposure and avoids any risk of sanctions.

### VirtualBox Preparation (GUI) — configure isolated network

1. In VirtualBox, select a VM → **Settings → Network**.
2. For **Adapter 1**:
   * Check **Enable Network Adapter**.
   * In **Attached to:** choose **Internal Network**.
   * In **Name:** enter a shared name for both VMs, e.g., `rede_ft_malcolm`.
   * Optional: check **Cable connected**.
3. Repeat for the **second VM**: set **Adapter 1** to the same name `rede_ft_malcolm`.
4. **Important**: do not configure Bridged mode for these VMs; keep Adapter 2 disabled (or set to NAT only if temporary internet access is needed, but keep disabled for isolated testing).
5. Start both VMs and open two terminals in each.

### VM IP Configuration (manual, safe mode)

#### 1. On **VM A (sniffer)** — execute:

```bash
make net_vm_a
```

#### 2. On **VM B (generator)** — execute:

```bash
make net_vm_b
```
#### 3. On **VM A (sniffer)** — execute:

* In terminal 1 of VM A
```bash
make run_vm_a
```
> Leave open — it will show ARP broadcast who-has.

* In terminal 2 of VM A
```bash
make comp
```
or to run with valgrind
```bash
make val
```

#### 4. On **VM B (generator)** — execute:

* In terminal 1 of VM B
```bash
make run_vm_b
```

* In terminal 2 of VM B
```bash
make request
```

---

## 👩🏻 Author
**Mayara Carvalho**
<br>
[:octocat: @MayaraMCarvalho](https://github.com/MayaraMCarvalho) | 42 Login: `macarval`

---
