# Shards of the Arena

**Shards of the Arena** is a small-scale multiplayer arena game built in Unreal Engine 5. Players compete to collect “Shards” scattered around the map or dropped by defeated opponents, with the first to reach a target winning. This project demonstrates gameplay systems, ability mechanics, modular C++ framework design, and networked multiplayer.

---

## 🎮 Core Gameplay

- **Arena Matches:** Players spawn with a basic ability loadout and compete to collect Shards.  
- **Victory Condition:** First to X shards wins; matches last a maximum of 5 minutes.  
- **Abilities (via GAS):**  
  - **Movement:** Dash or Double Jump  
  - **Attack:** Projectile or melee  
  - **Defense:** Shield or short invulnerability  
  - Each ability has cooldowns, costs, VFX/SFX, and is configurable via DataTables.  

---

## 🛠 Modular Framework

- Base Character class with modular components (Movement, Combat, Interaction).  
- Ability registration system for easy skill addition.  
- Clear separation between logic, input mapping, and visual feedback.  
- Blueprint hooks included for designer-friendly extension.

---

## 🌐 Networking

- Full replication of:  
  - Player movement  
  - Abilities (cooldowns, effects, projectiles)  
  - Match state and shard counts  
- Minimum listen server support (dedicated optional).  

---

## ⚙️ Tools & Utilities

- In-editor tools to place spawn points and shard pickups.  
- Adjustable shard respawn times.  

---

## ✨ Audio & Visual Polish

- Basic SFX for movement, abilities, and shard pickups.  
- VFX for abilities and shard collection.  
- Simple UI including:  
  - Shard counter  
  - Ability cooldown indicators  
  - Match timer  

---

## 🎯 Stretch Goals (Optional)

- Multiple character archetypes with unique abilities/loadouts.  
- Environmental hazards (lava, spikes, traps).  
- AI bots for solo testing.  
- Match replay system (event storage).

---

## 📂 Portfolio Deliverables

- **Technical Breakdown PDF / README:** Show what was built in C++ vs Blueprints.  
- **Gameplay Video (1–2 min):** Demonstrating abilities, network play, and modularity.  
- **Code Highlights:** Links to a few well-commented core files in the repo.

---

## 🛠 Tech Stack

- **Engine:** Unreal Engine 5  
- **Language:** C++ and Blueprint  
- **Systems:** Gameplay Ability System (GAS), Multiplayer Replication  
- **Tools:** Editor utilities for level setup and shard placement  

---

## ⚡ Notes

This repo focuses solely on the Unreal Engine component of the Shards of the Arena project. Future integration may include Web3 NFT item ownership and a Java microservice for inventory management, showcased in separate repositories.
This repo focuses solely on the Unreal Engine component of the Shards of the Arena project. Future integration may include Web3 NFT item ownership and a Java microservice for inventory management, showcased in separate repositories.

