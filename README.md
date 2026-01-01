# cpp-blockchain

  ____   ____  ____  _      ____  _             _             
 / ___| / ___|| __ )| |    / ___|| | ___   __ _(_)_ __   __ _ 
 \___ \| |    |  _ \| |    \___ \| |/ _ \ / _` | | '_ \ / _` |
  ___) | |___ | |_) | |___  ___) | | (_) | (_| | | | | | (_| |
 |____/ \____||____/|_____|____/|_|\___/ \__, |_|_| |_|\__, |
                                         |___/         |___/ 

A lean, modular C++17 blockchain prototype focused on clarity, testability, and education.

[![Build Status](https://img.shields.io/badge/build-untested-lightgrey.svg)](https://example.com)
[![C++ Standard](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](#)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](#)

---

Table of Contents
- [About](#about)
- [Features](#features)
- [Architecture](#architecture)
- [Quickstart](#quickstart)
- [Usage Examples](#usage-examples)
- [Development](#development)
- [Contributing](#contributing)
- [License](#license)

---

## About

`cpp-blockchain` is a small, opinionated blockchain prototype written in modern C++ (C++17).  
It prioritizes readable code, modular components, and easy experimentation with core concepts like blocks, transactions, chaining, and consensus primitives.

Use it to learn, prototype consensus ideas, or as a foundation for demos and tests.

---

## Features

- Minimal block and chain implementation with cryptographic hashing.
- Modular components:
  - `Block` — holds transactions, metadata, and previous hash.
  - `Chain` — verifies and stores blocks.
  - `Miner` — (toy) proof-of-work illustrative miner.
  - `Network` — pluggable mock networking for tests/demos.
- Unit-tested core logic (fixtures + deterministic tests).
- Clean CMake-based build (Ninja generator supported).

---

## Architecture

A compact, modular layout:

- `src/` — implementation (blocks, chain, miner, utils).
- `include/` — public headers.
- `tests/` — unit and integration tests.
- `CMakeLists.txt` — build orchestration.

Mermaid overview:

```mermaid
graph TD;
    A[blocks] -->|ijson| B{chain};
    B -->|m| C[wallet];
    B -->|n| D[miner];
    B -->|o| E[network];
    D -->|extra| B;
````````

---

## Quickstart

Prerequisites:
- CMake >= 3.15 (project built with CMake 3.31 in CI).
- Ninja (recommended).
- A C++17 toolchain (MSVC, clang, or gcc).

Clone and build:

```bash
git clone https://github.com/gnatykdm/cpp-blockchain.git
cd cpp-blockchain
cmake -B build -S . -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C build
```

Run tests (if present):

```bash
cd cpp-blockchain
cmake -B build -S . -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja -C build test
```

---

## Usage Examples

Run a simple node (example CLI):

```bash
./build/node
```

Create/add a block (pseudo-CLI):

```bash
echo "Creating block..."
```

Inspecting chain (programmatically):

```cpp
#include "chain.h"

void inspect_chain(const Chain& chain) {
  for (const auto& block : chain.get_blocks()) {
    std::cout << "Block: " << block.get_hash() << std::endl;
  }
}
```

(See `examples/` for runnable snippets.)

---

## Development

- CMake: prefer out-of-source builds via `-B build -S .`.
- Generator: `Ninja` is recommended for fast incremental builds.
- Compiler flags: use `-Wall -Wextra -Wpedantic` and sanitize in CI for debug builds.
- Formatting: follow a consistent style; run `clang-format` or your configured formatter.
- Tests: add unit tests under `tests/` and integrate with CTest.

Helpful commands:

```bash
# Clean build artifacts
ninja -C build clean

# Re-run CMake configuration
cmake -B build -S .

# Build with specific target
ninja -C build <target_name>
```

---

## Contributing

Contributions are welcome. Suggested workflow:
1. Fork the repo.
2. Create a feature branch: `git checkout -b feat/your-idea`.
3. Add tests for new behavior.
4. Open a PR with a clear description and context.

Please follow the existing module boundaries and keep functions small and testable.

---

## License

This project is released under the MIT License. See `LICENSE` for details.

---

Enjoy exploring blockchain internals. If you'd like, add an example issue or feature request and start a conversation!