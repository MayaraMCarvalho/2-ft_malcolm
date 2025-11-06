# 🕵️ ft_malcolm (42 São Paulo)

Available in: [🇧🇷 Português](README.md)

![Static Badge](https://img.shields.io/badge/C-c?style=plastic&label=Language)

This project is an introduction to network security, focused on intercepting and analyzing ARP (Address Resolution Protocol) packets. The project consists of a network sniffer developed in C, capable of capturing and displaying ARP traffic in real-time, demonstrating the basis for attacks like Man-in-the-Middle (MITM).

---

## 📜 Table of Contents

* [Overview](#-overview)
* [Features](#-features)
* [Tech Stack Used](#-tech-stack-used)
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
git clone [https://github.com/MayaraMCarvalho/2-ft_malcolm/](https://github.com/MayaraMCarvalho/2-ft_malcolm/) ft_malcolm
cd ft_malcolm
