# 💫 Remote Procedure Calls (RPC)

_“Let your programs talk across worlds (or… just different computers)~” 💻🌐_

---

## 🌷 What Is RPC?

RPC stands for **Remote Procedure Call**, and it’s a magical way for one program to call a function that _actually lives on another computer_! 💫
Think of it like sending a letter to a faraway friend—she performs the task and sends you the results back, all so smoothly you might forget you’re not in the same place! 💌✨

---

### 🔹 Core Idea

RPC **abstracts procedure calls** between processes on **networked systems** — meaning it makes remote calls feel _just like local ones!_ 🪄

Here’s how the spell works:

1. **Ports for service differentiation** 🌀
   - Just like each café has a different theme (☕🎶🍰), ports identify which service or process you’re calling on the network.

2. **Stubs (Tiny Magic Proxies)** ✨
   - 🧩 _Client Stub:_ Acts like a local stand-in for the real procedure on the server.
   - 🧩 _Server Stub:_ Receives the request, unpacks it, and performs the real work.

   ➤ Together, they’re like magical couriers translating your intent across systems~ 📜💫

3. **Marshalling & Unmarshalling** 🎁
   - _Marshalling:_ Packing up your data and parameters neatly for the journey.
   - _Unmarshalling:_ Unwrapping them on the other side so the server can understand them again.

---

## 🧑‍💻 Behind the Scenes (Windows Style)

On Windows, the stub code is generated from a special specification written in **Microsoft Interface Definition Language (MIDL)**.
It’s like a magic contract 🪄 that defines what both sides should expect and how they should communicate!

---

## 🌍 Handling Data Differences

Different systems speak in different “byte dialects” 🧠💬 — some are **big-endian**, others **little-endian** (basically, who puts the “big” or “small” part of data first).

To make everyone get along, RPC uses **External Data Representation (XDR)** format ✨ — a universal translator ensuring both sides understand each other perfectly, no matter the architecture. 🌐💖

---

## ⚙️ Communication Challenges

Talking across the network isn’t always smooth sailing 🚤💨
There are more possible _failure scenarios_ than in local communication — think timeouts, dropped packets, or unresponsive servers. 😣

To handle this:

- RPC systems often guarantee **messages delivered exactly once** (not “at most once” — so no accidental repeats 🌀).
- The OS provides a **rendezvous (matchmaker) service** 💞 to help clients and servers find each other safely and start talking.

---

## 🌟 TL;DR (Tiny Lovely Digest 💕)

| Concept                | Description                                                        |
| :--------------------- | :----------------------------------------------------------------- |
| **RPC**                | Lets one program call another’s function _across a network_        |
| **Stub**               | The magical go-between (Client-side sends; Server-side receives)   |
| **Marshalling**        | Packing data for travel ✈️                                         |
| **Unmarshalling**      | Unpacking it upon arrival 🎁                                       |
| **XDR**                | Format that ensures both systems “speak” the same data language 🌍 |
| **Reliability**        | Messages guaranteed _exactly once_                                 |
| **Matchmaker Service** | Helps client and server meet 💞                                    |
