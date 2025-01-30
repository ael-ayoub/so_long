# so_long

![so_long](https://img.shields.io/badge/42-so_long-blue)

A simple 2D game project developed as part of the 42 curriculum. The goal is to move a character through a maze to collect items and reach an exit while avoiding enemies.

## 📌 Features
- 2D grid-based movement
- Player controls using keyboard inputs
- Basic enemy AI
- Collectible items
- Victory and game-over conditions

## 📥 Installation
```sh
git clone https://github.com/ael-ayoub/so_long.git
cd so_long
git clone https://github.com/42Paris/minilibx-linux.git
make
```

## 🕹️ Usage
```sh
./so_long map.ber
```
Use **WASD** keys to move the player.

## 🗺️ Map Format
The game uses `.ber` files for level maps. Example:
```
111111
1P0C1E
111111
```
- `1` = Wall
- `P` = Player Start
- `0` = Empty Space
- `C` = Collectible
- `E` = Exit

## 🛠️ Dependencies
- MinilibX
- GCC compiler
- Make

## 📂 Project Structure
```
img/
include/
libft/
Makefile
maps/
so_bonus.c
so_long.c
src/
src_bonus/
```

## 🎉 Bonus Part
- Additional animations
- Improved enemy AI
- More advanced interactions
- Extra game modes

## ✅ To-Do
- [ ] Improve enemy AI
- [ ] Add more levels
- [ ] Enhance visuals with sprites
- [ ] Expand bonus features

## 📜 License
This project is licensed under the MIT License.

## 🙌 Acknowledgments
Thanks to the 42 community for guidance and resources.

---
*Project developed as part of the 42 curriculum.*
