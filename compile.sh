#!/usr/bin/env bash
set -euo pipefail

echo "==> Installing dependencies..."
sudo pacman -S --needed openssl icu

echo "==> Compiling Credential Generator..."

mkdir -p bin

gcc -std=c99 -w -g \
    main.c \
    src/Core/Credential_Generator/random/random.c \
    src/Core/Credential_Generator/file/file.c \
    -o bin/main \
    -lssl -lcrypto -licuuc -licudata -licuio

echo "==> Build complete: bin/main"