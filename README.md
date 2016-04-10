# Projektin kääntäminen

## Win
Tarvittava ohjelmisto:

- CMake
- Visual Studio

Kääntäminen

1. lataa tai kloonaa projekti koneellesi
2. Suorita CMake projekti kansiossa
3. Avaa CMake:n tekemä Visual Studio projekti tiedosto
4. Build

## Linux
- CMake
- g++

Kääntäminen

1. Mene terminaalilla kansioon johon haluat projektin
2. Copy&Paste alla ole scripti terminaaliin
```bash
git clone https://simpller@bitbucket.org/simpller/fightsimulator6000.git &&
cd fightsimulator6000 &&
cmake . &&
make
```