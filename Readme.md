# ft_malcolm 🕵️

**Autor:** **_macarval_**

---

## 1. Visão Geral

Este repositório contém o projeto **ft_malcolm**.

**ft_malcolm** é um projeto da 42 que simula um sniffer de rede, capaz de interceptar, analisar e exibir pacotes ARP que é um programa que intercepta pacotes ARP (Address Resolution Protocol) em tempo real. Ele foi desenvolvido com foco no aprendizado de redes, manipulações de pacotes e uso de sockets em C.

---

## 2. Objetivo 📚

O principal objetivo do projeto é entender como funciona a resolução de endereços IP para MAC na camada de enlace, além de praticar:
* Captura de pacotes em tempo real
* Manipulação de estruturas de rede
* Uso de raw sockets
* Análise de cabeçalhos Ethernet e ARP

---

## 3. Funcionalidade ⚙️

* Captura de pacotes ARP em uma interface de rede especificada
* Exibição de informações como IP de origem/destino, MAC de origem/destino e tipo de operação (request/reply)
* Filtros para ignorar pacotes irrelevantes
* Saída formatada e legível no terminal

---


> ## 4. Warning ⚠️

> Usar spoofing de ARP sem permissão é uma violação das políticas de segurança e pode ser ilegal. É crucial usar esta ferramenta apenas > em ambientes controlados, como uma rede de laboratório pessoal, para fins educacionais ou de teste.

> Esta ferramenta foi desenvolvida como parte do currículo Advanced da 42 São Paulo e destina-se apenas a fins educacionais. A autora não tolera nem incentiva o uso desta ferramenta para fins maliciosos.

---

## 5. Como usar

Para testar de maneira segura, devemos usar um ambiente totalmente isolado usando **Internal Network** do VirtualBox entre **duas VMs**.Assim, não haverá exposição de dados sensíveis e evita qualquer risco de sanções.

### Preparação no VirtualBox (GUI) — configurar rede isolada

1. Em VirtualBox, selecione uma VM → **Configurações → Rede**.
2. Para **Adaptador 1**:
   * Marque **Habilitar placa de rede**.
   * Em **Conectado a:** escolha **Rede Interna (Internal Network)**.
   * Em **Nome:** digite um nome compartilhado para as duas VMs, por exemplo `rede_ft_malcolm`.
   * Opcional: marque **Conectar cabo**.
3. Repita para a **segunda VM**: ajuste **Adaptador 1** com o mesmo nome `rede_ft_malcolm`.
4. **Importante:** não configure Bridged para estas VMs; deixe o Adaptador 2 desabilitado ou em NAT somente se precisar de internet temporariamente (mas para teste isolado deixe desabilitado).
5. Inicie ambas as VMs.
6. Abra dois terminais em cada VM.

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

