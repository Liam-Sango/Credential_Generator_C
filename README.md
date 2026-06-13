# Credential Generator

A terminal-based **C99** utility for generating randomized credentials and identifiers. Random output is produced with **OpenSSL** (cryptographically secure bytes) and **ICU** for Unicode/UTF-8 handling.

![Language](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-GPLv3-blue.svg)

## Features

Run the program and pick an option from the menu:

| Option | Generator | Output format |
|:------:|-----------|---------------|
| 1 | **Username** | `word1_word2_NNNN` (two random words + a number) |
| 2 | **Password** | Random printable ASCII string, configurable length (default 20) |
| 3 | **Passphrase** | Space-separated words from a wordlist, configurable word count |
| 4 | **Full Name** | `First Middle Surname` |
| 5 | **Random Number** | An integer within a user-defined range |
| 6 | **Custom Unicode String** | Random UTF-8 string within a user-defined code-point range |

The word-based generators (1, 3, 4) accept a custom wordlist path, or fall back to the bundled lists in [`Files/`](Files/).

## Dependencies

- [OpenSSL](https://www.openssl.org/) — cryptographic random byte generation (`libssl`, `libcrypto`)
- [ICU](https://icu.unicode.org/) — Unicode handling and UTF-8 encoding (`libicuuc`, `libicudata`, `libicuio`)

## Build

### Quick build (Arch Linux)

The included script installs dependencies and compiles to `bin/main`:

```bash
./compile.sh
```

It runs `sudo pacman -S --needed openssl icu` first, so adapt the package install step for your distribution if you're not on Arch.

### Using Make

```bash
make        # build to bin/main
make run    # build and run
make clean  # remove build artifacts
make help   # list all targets
```

### Manual compile

```bash
gcc -std=c99 -Wall -Wextra -pedantic -g \
    main.c \
    src/Core/Credential_Generator/random/random.c \
    src/Core/Credential_Generator/file/file.c \
    -o bin/main \
    -lssl -lcrypto -licuuc -licudata -licuio
```

## Run

```bash
./bin/main
```

Then choose a menu option (1–6) and follow the prompts.

## Project Structure

```
.
├── main.c                 # Menu and generator entry points
├── src/Core/Credential_Generator/
│   ├── random/            # OpenSSL-backed RNG, UTF-8 strings, phrase generation
│   └── file/              # Wordlist validation and random line selection
├── Files/                 # Bundled default wordlists
├── makefile               # Build targets
├── compile.sh             # One-shot build script (Arch)
└── Documentation/         # Additional notes and requirements
```

## License

Released under the **GNU General Public License v3**. See [`LICENSE`](LICENSE) for the full text.
