# 🕵️ ft_malcolm (42 São Paulo)

Available in: [🇺🇸 English](README.en.md)

![Static Badge](https://img.shields.io/badge/C-c?style=plastic&label=Linguagem)

<div align="center">
  <img src="https://github.com/user-attachments/assets/039a1079-c4dc-4d3a-8b57-c81b7a541d52" alt="common_coren" width="200">
</div>

Este projeto é uma introdução à segurança de rede, focado na interceptação e análise de pacotes ARP (Address Resolution Protocol). O projeto consiste em um sniffer de rede desenvolvido em C, capaz de capturar e exibir tráfego ARP em tempo real, demonstrando a base para ataques como Man-in-the-Middle (MITM).

---

## 📜 Índice

* [Visão Geral](#%EF%B8%8F-vis%C3%A3o-geral)
* [Funcionalidades](#-funcionalidade)
* [Tecnologias Utilizadas](#%EF%B8%8F-tecnologias-utilizadas)
* [Instalação e Setup](#-instala%C3%A7%C3%A3o-e-setup)
* [Modo de Uso](#-modo-de-uso)
* [Autora](#-autora)

---

## 🕵️ Visão Geral

O **ft_malcolm** é um projeto da 42 que simula um sniffer de rede. O principal objetivo é entender como funciona a resolução de endereços IP para MAC na camada de enlace, além de praticar:
* Captura de pacotes em tempo real.
* Manipulação de estruturas de rede (Cabeçalhos Ethernet e ARP).
* Uso de raw sockets (soquetes brutos).
* Análise de tráfego de rede de baixo nível.

---

## ✨ Funcionalidade

* Captura de pacotes ARP em uma interface de rede especificada.
* Exibição de informações como IP de origem/destino, MAC de origem/destino e tipo de operação (request/reply).
* Filtra pacotes irrelevantes para focar apenas na comunicação ARP.
* Fornece uma saída formatada e legível no terminal.

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem C**: Para manipulação de baixo nível da rede.
* **`Raw Sockets` (Socket Bruto)**: Para capturar pacotes diretamente da camada de enlace (L2).
* **Linux Networking**: Uso das bibliotecas `<sys/socket.h>`, `<netinet/if_ether.h>`, `<arpa/inet.h>`.
* **`Makefile`**: Para compilação e gerenciamento de regras de teste.

---

## ⚠️ Aviso Legal

> Usar spoofing de ARP ou sniffeing sem permissão é uma violação das políticas de segurança e pode ser ilegal. É crucial usar esta ferramenta apenas em ambientes controlados, como uma rede de laboratório pessoal(VMs), para fins educacionais ou de teste.

> Esta ferramenta foi desenvolvida como parte do currículo Advanced da 42 São Paulo e destina-se apenas a fins educacionais. A autora não tolera nem incentiva o uso desta ferramenta para fins maliciosos.

---

## 🚀 Instalação e Setup

1. Clone o repositório:

``` bash
git clone https://github.com/MayaraMCarvalho/2-ft_malcolm/ ft_malcolm
cd ft_malcolm
```

2. Compile o projeto: O Makefile contém as regras para compilar o programa.

``` bash
make comp
```
> Para compilar com valgrind, use: make val
> Para limpar os binários, use: make fclean

---

## 🔧 Modo de Uso

Para testar de maneira segura, devemos usar um ambiente totalmente isolado usando **Internal Network** do VirtualBox entre **duas VMs**. Assim, não haverá exposição de dados sensíveis e evita qualquer risco de sanções.

### Preparação no VirtualBox (GUI) — configurar rede isolada

1. Em VirtualBox, selecione uma VM → **Configurações → Rede**.
2. Para **Adaptador 1**:
   * Marque **Habilitar placa de rede**.
   * Em **Conectado a:** escolha **Rede Interna (Internal Network)**.
   * Em **Nome:** digite um nome compartilhado para as duas VMs, por exemplo `rede_ft_malcolm`.
   * Opcional: marque **Conectar cabo**.
3. Repita para a **segunda VM**: ajuste **Adaptador 1** com o mesmo nome `rede_ft_malcolm`.
4. **Importante:** não configure Bridged para estas VMs; deixe o Adaptador 2 desabilitado ou em NAT somente se precisar de internet temporariamente (mas para teste isolado deixe desabilitado).
5. Inicie ambas as VMs e abra dois terminais em cada uma.

### Configuração de IPs nas VMs (modo manual, seguro)

#### 1 .Na **VM A (sniffer)** — execute:

```bash
make net_vm_a
```

#### 2. Na **VM B (generator)** — execute:

```bash
make net_vm_b
```

#### 3. Na **VM A (sniffer)** — execute:

* No terminal 1 da VM A
```bash
make run_vm_a
```
> Deixe aberto — mostrará ARP broadcast `who-has`.

* No terminal 2 da VM A
```bash
make comp
```
ou para rodar com valgrind
```bash
make val
```

#### 4. Na **VM B (generator)** — execute:

* No terminal 1 da VM B
```bash
make run_vm_b
```

* No terminal 2 da VM B
```bash
make request
```

---

## 👩🏻 Autora
**Mayara Carvalho**
<br>
[:octocat: @MayaraMCarvalho](https://github.com/MayaraMCarvalho) | 42 Login: `macarval`

---
