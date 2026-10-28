# Literały w C++

Materiały, ćwiczenia i quiz o literałach w C++: wbudowane, surowe i definiowane przez użytkownika.

## Czym jest <temat>?

*Do uzupełnienia: 3–5 zdań — co to jest, do czego służy, jakie problemy rozwiązuje.
Więcej w [`lab/_start.ipynb`](lab/_start.ipynb).*

## Struktura

- `lab/` — notebooki JupyterLab z materiałami i ćwiczeniami; zacznij od `lab/_start.ipynb`
  - `lab/NN_temat/exK_nazwa/` — ćwiczenie K z tematu NN (osobny projekt CMake)
  - `lab/cmake/lab.cmake` — wspólne ustawienia CMake (C++20, GoogleTest)
- `pyproject.toml` — środowisko Pythona dla notebooków (zarządzane przez [uv](https://docs.astral.sh/uv/))

## Jak zacząć

```bash
uv sync
uv run --with jupyterlab jupyter lab lab/_start.ipynb
```

Szczegółowa instrukcja instalacji — w przygotowaniu.

## Autorzy

- Tomasz Idźkowski (idzkowskit@student.agh.edu.pl)
- Kacper Kobieluch (kkobieluch@student.agh.edu.pl)
- Maksymilian Koleśniak (mkolesniak@student.agh.edu.pl)
