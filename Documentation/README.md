# Credential Generator

A terminal-based C99 utility for generating randomized credentials and identifiers. It produces cryptographically secure output using OpenSSL for random number generation and ICU for Unicode handling.

## Features

| Option | Function | Output Format |
|--------|----------|---------------|
| 1 | Username Generator | `word1_word2_NNNN` |
| 2 | Password Generator | Random printable ASCII string, configurable length |
| 3 | Passphrase Generator | Space-separated words from a wordlist, configurable word count |
| 4 | Full Name Generator | `First Middle Surname` |
| 5 | Random Number Generator | Integer in a user-defined range |
| 6 | Custom Unicode String | Random UTF-8 string in a user-defined code point range |

All generators accept custom wordlist paths or fall back to the bundled wordlists in `Files/`.

## Dependencies

- [OpenSSL](https://www.openssl.org/) — cryptographic random byte generation (`libssl`, `libcrypto`)
- [ICU](https://icu.unicode.org/) — Unicode character handling and UTF-8 encoding (`libicuuc`, `libicudata`, `libicuio`)

## Compiling with GCC

### Arch Linux

Install dependencies:

```bash
sudo pacman -S openssl icu
```

Then compile:

```bash
gcc -std=c99 -Wall -Wextra -pedantic -g \
    main.c \
    src/Core/Credential_Generator/random/random.c \
    src/Core/Credential_Generator/file/file.c \
    -o bin/main \
    -lssl -lcrypto -licuuc -licudata -licuio
```

Run:

```bash
./bin/main
```

### Using Make

```bash
make        # build
make run    # build and run
make clean  # remove build artifacts
```

## License

GNU General Public License v3. See `LICENSE` for the full text.